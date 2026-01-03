#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>

#define BUFFER_SIZE 1024
#define READ_END 0
#define WRITE_END 1

int main()
{
	int fd[2];
	pid_t pid;
	char buffer[BUFFER_SIZE];
	int file;
	ssize_t bytes;

	if(pipe(fd) == -1)
	{
		perror("pipe failed");
		return 1;
	}

	pid = fork();

	if(pid < 0)
	{
		perror("fork failed");
		return 1;
	}

	if(pid == 0)
	{
		close(fd[WRITE_END]);

		int count = 0;
		ssize_t n;

		while( (n = read(fd[READ_END], buffer, BUFFER_SIZE)) > 0 )
		{
			for(int i=0; i<n; i++)
			{
				if(buffer[i] == 'S')
					count++;
			}
		}
		close(fd[READ_END]);

		printf("Number of 'S' characters: %d\n", count);
		exit(0);
	}
	else
	{
		close(fd[READ_END]);

		file = open("pipe_fork.c", O_RDONLY);
		if(file < 0)
		{
			perror("file open failed");
			return 1;
		}

		while((bytes = read(file, buffer, BUFFER_SIZE)) > 0)
		{
			write(fd[WRITE_END], buffer, bytes);
		}

		close(file);
		close(fd[WRITE_END]);

		wait(NULL);
		printf("child process finished");
	}
	return 0;
}
