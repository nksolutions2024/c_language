#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<netdb.h>

#define PortNumber 12345
#define MaxConnects 5
#define BuffSize 256
#define ConversationLen 3
#define Host "localhost"

const char* subjects[] = {
	"Maths",
	"English",
	"Hindi",
	"Science"
};

int main(){
	int sockfd = socket(
			AF_INET,
			SOCK_STREAM,
			0
	);

	//HOST NAME RESOLVING
	struct hostent* hptr = gethostbyname(Host);

	if(hptr->h_addrtype != AF_INET)
	{
		fprintf(stderr, "Not IPv4\n");
		exit(1);
	}

	struct sockaddr_in saddr;
	memset(&saddr, 0, sizeof(saddr));

	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = ((struct in_addr*) hptr->h_addr_list[0])->s_addr;
	saddr.sin_port = htons(PortNumber);

	if(connect(sockfd,(struct sockaddr*) &saddr, sizeof(saddr)) < 0)
	{
		perror("connect");
		exit(1);
	}

	puts("connecting to server, writing.... ");

	int i;
	for(i=0; i<ConversationLen; i++)
	{
		if(write(sockfd, subjects[i], strlen(subjects[i])+1 ) > 0)
		{
			char buffer[BuffSize+1];
			memset(buffer, '\0', sizeof(buffer));

			if(read(sockfd, buffer, sizeof(buffer)) > 0)
			{
				puts(buffer);
			}
		}
	}
	puts("Client work over, exiting ....");	

	close(sockfd);

	return 0;
}
