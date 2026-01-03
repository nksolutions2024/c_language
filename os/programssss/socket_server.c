#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/tcp.h>
#include<arpa/inet.h>

#include<netinet/in.h>

#define PortNumber 12345
#define MaxConnects 5
#define BuffSize 256
#define ConversationLen 3
#define Host "localhost"

int main(){
	int fd =  socket(
			AF_INET,	// IPv4
			SOCK_STREAM,	// TCP
			0		// OS chooses protocol(TCP) ?
	);

	//if socket creation fails, terminate
	//
	struct sockaddr_in saddr;
	memset(&saddr, 0, sizeof(saddr)); //clear structure
	
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = htonl(INADDR_ANY); //host to network ;any local IP
	saddr.sin_port = htons(PortNumber);

	if (bind(fd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0)
	{
		perror("bind");
	}

	if (listen(fd, MaxConnects) < 0)
	{
		perror("listen");
	}

	fprintf(stderr, "listening on port 12345 for clients....\n");

	while(1)
	{
		struct sockaddr_in caddr; 
		int len = sizeof(caddr);

		int client_fd = accept(fd, (struct sockaddr*) &caddr, &len);

		if (client_fd < 0)
		{
			perror("accept");
			continue;
		}

		int i;
		for(i = 0; i< ConversationLen; i++)
		{
			char buffer[BuffSize+1];
			memset(buffer, '\0', sizeof(buffer)); //buffer clearing
							   
			int count = read(client_fd, buffer, sizeof(buffer));

			if(count>0)
			{
				puts(buffer);

				write(client_fd, buffer, count);
			}
		}
		close(client_fd);
	}
	return 0;

}

