#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid;

	pid = fork();

	if(pid < 0)
	{
		fprintf(stderr, "forked failed");
	}
	else if(pid == 0)
	{
		execlp("/bin/ls", "ls", NULL);
		printf("inside child, pid is %d", getpid());
	}
	else
	{
		wait(NULL);// purpose of NULL?
		printf("child complete\n");
		printf("inside parent, pid is %d", getpid());
	}
	
	return 0;
}
