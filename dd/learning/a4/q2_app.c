/* User space file to test userspace / kernelspace data exchange module */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <errno.h>

#define BYTE_TO_READ	100
#define FILE_PATH	"/etc/passwd"
#define DEV		"/dev/rohitDev"

int main()
{
	int fdPassword = open(FILE_PATH, O_RDONLY);
	if(fdPassword < 0){
		perror("Cannot Open Password File");
		exit(EXIT_FAILURE);
	}
	char *passwd = (char *)calloc(BYTE_TO_READ+1,sizeof(char));
	if(NULL==passwd){
		perror("passwd buffer allocation failed");
		exit(EXIT_FAILURE);
	}
	
	ssize_t ret;
	
	ret = read(fdPassword, passwd, BYTE_TO_READ);
	if(ret != BYTE_TO_READ){
		perror("passwd read failed");
		exit(EXIT_FAILURE);
	}
	passwd[BYTE_TO_READ] = '\0';
//	printf("passwd Content: %s\n", passwd);

	
	int fd = open(DEV, O_RDWR);
	if (fd<0)
	{
		perror("Cannot open device file");
		exit(EXIT_FAILURE);
	}
	
	//size_t stringSize = strlen(passwd);
	//printf("stringSize: %d", stringSize);
	ret = write(fd, passwd, BYTE_TO_READ);
	if(ret != BYTE_TO_READ){
		perror("write to dev failed");
		exit(EXIT_FAILURE);
	}

	char *receiveBuffer = (char *)calloc(BYTE_TO_READ, sizeof(char));
	ret = read(fd, (void *)receiveBuffer, BYTE_TO_READ);
	if(ret != BYTE_TO_READ){
		perror("read from dev failed");
		exit(EXIT_FAILURE);
	}

	printf("Contnet Wrote: %s\n", passwd);
	printf("Contnet Read: %s\n", receiveBuffer);
	
	free(receiveBuffer);
	free(passwd);
	close(fdPassword);
	close(fd);

	return (EXIT_SUCCESS);
}


