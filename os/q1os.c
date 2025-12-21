#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

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

    // Create pipe
    if (pipe(fd) == -1)
    {
        perror("Pipe failed");
        return 1;
    }

    // Fork process
    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }

    // ---------------- CHILD PROCESS ----------------
    if (pid == 0)
    {
        close(fd[WRITE_END]);   // Close write end

        int count = 0;
        ssize_t n;

        while ((n = read(fd[READ_END], buffer, BUFFER_SIZE)) > 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (buffer[i] == 'S')
                    count++;
            }
        }

        close(fd[READ_END]);

        printf("Number of 'S' characters: %d\n", count);
        exit(0);
    }

    // ---------------- PARENT PROCESS ----------------
    else
    {
        close(fd[READ_END]);   // Close read end

        file = open("/usr/include/stdio.h", O_RDONLY);
        if (file < 0)
        {
            perror("File open failed");
            return 1;
        }

        while ((bytes = read(file, buffer, BUFFER_SIZE)) > 0)
        {
            write(fd[WRITE_END], buffer, bytes);
        }

        close(file);
        close(fd[WRITE_END]);

        wait(NULL);  // Wait for child to finish
        printf("Child process completed\n");
    }

    return 0;
}

