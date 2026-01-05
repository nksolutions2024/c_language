#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345

int main()
{
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    printf("enter message: ");
    fgets(buffer, sizeof(buffer), stdin);

    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));

    printf("reply from server: %s\n", buffer);

    close(sockfd);

    return 0;
}

