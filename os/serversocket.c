// Socket server

#include <string.h>     // memset, strlen
#include <stdio.h>      // printf, perror, puts
#include <stdlib.h>     // exit
#include <unistd.h>     // read, write, close
#include <sys/types.h>  // data types
#include <sys/socket.h> // socket APIs
#include <netinet/tcp.h>// TCP definitions
#include <arpa/inet.h>  // htons, htonl, inet
#include "sock.h"       // PortNumber, BuffSize, etc.

// Error-reporting helper function
void report(const char* msg, int terminate) {
  perror(msg);          	// print system error message
  if (terminate) exit(-1); 	// exit if fatal error
}

int main(){
  // Create a TCP socket
  int fd = socket(
      AF_INET,          // IPv4
      SOCK_STREAM,      // TCP (reliable stream)
      0                 // OS chooses protocol (TCP)
  );

  // If socket creation fails, terminate
  if (fd < 0) report("socket", 1);

  // Server address structure
  struct sockaddr_in saddr;
  memset(&saddr, 0, sizeof(saddr)); // clear structure

  saddr.sin_family = AF_INET;                // IPv4
  saddr.sin_addr.s_addr = htonl(INADDR_ANY); // accept any local IP
  saddr.sin_port = htons(PortNumber);        // listening port

  // Bind socket to IP + port
  if (bind(fd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0)
  {
	report("bind", 1);
  }

  // Put socket into listening mode
  if (listen(fd, MaxConnects) < 0)
  {
    report("listen", 1);
  }

  fprintf(stderr, "Listening on port %i for clients...\n", PortNumber);

  // Server runs forever
  while (1) 
  {
    struct sockaddr_in caddr; // client address
    int len = sizeof(caddr);  // size of client address

    // Accept a client connection (blocks until client connects)
    int client_fd = accept(fd, (struct sockaddr*) &caddr, &len);

    // If accept fails, continue running server
    if (client_fd < 0) {
      report("accept", 0);
      continue;
    }

    // Communicate with client
    int i;
    for (i = 0; i < ConversationLen; i++) 
    {
      char buffer[BuffSize + 1];
      memset(buffer, '\0', sizeof(buffer)); // clear buffer

      // Read data from client
      int count = read(client_fd, buffer, sizeof(buffer));

      if (count > 0) 
      {
        puts(buffer); // print received message

        // Echo message back to client
        // NOTE: better to use "count" instead of sizeof(buffer)
        write(client_fd, buffer, sizeof(buffer));
      }
    }
    // Close connection with client
    close(client_fd);
  }
  return 0;
}

