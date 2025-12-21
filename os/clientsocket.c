// Socket client

#include <string.h>     // strlen, memset
#include <stdio.h>      // puts, perror
#include <stdlib.h>     // exit
#include <unistd.h>     // read, write, close
#include <sys/types.h>  // data types
#include <sys/socket.h> // socket APIs
#include <arpa/inet.h>  // inet, htons
#include <netinet/in.h> // sockaddr_in
#include <netinet/tcp.h>// TCP definitions
#include <netdb.h>      // gethostbyname
#include "sock.h"       // Host, PortNumber, BuffSize

// Messages to send to server
const char* books[] = {
  "War and Peace",
  "Pride and Prejudice",
  "The Sound and the Fury"
};

// Error-reporting helper
void report(const char* msg, int terminate) {
  perror(msg);
  if (terminate) exit(-1);
}

int main() {
  // Create TCP socket
  int sockfd = socket(
      AF_INET,         // IPv4
      SOCK_STREAM,     // TCP
      0                // protocol chosen by OS
  );

  if (sockfd < 0) report("socket", 1);

  // Resolve hostname (e.g., "localhost")
  struct hostent* hptr = gethostbyname(Host);

  if (!hptr) report("gethostbyname", 1);
  if (hptr->h_addrtype != AF_INET)
    report("bad address family", 1);

  // Server address structure
  struct sockaddr_in saddr;
  memset(&saddr, 0, sizeof(saddr));

  saddr.sin_family = AF_INET; // IPv4
  saddr.sin_addr.s_addr =
      ((struct in_addr*) hptr->h_addr_list[0])->s_addr; // server IP
  saddr.sin_port = htons(PortNumber); // server port

  // Connect to server
  if (connect(sockfd, (struct sockaddr*) &saddr, sizeof(saddr)) < 0)
    report("connect", 1);

  puts("Connect to server, about to write some stuff...");

  // Send messages and receive echoes
  int i;
  for (i = 0; i < ConversationLen; i++) {

    // Send book title to server
    if (write(sockfd, books[i], strlen(books[i])) > 0) {

      char buffer[BuffSize + 1];
      memset(buffer, '\0', sizeof(buffer));

      // Read echoed message from server
      if (read(sockfd, buffer, sizeof(buffer)) > 0)
        puts(buffer);
    }
  }

  puts("Client done, about to exit...");

  // Close socket
  close(sockfd);

  return 0;
}


