#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *str = (char*) shmat(shmid, NULL, 0);

    printf("Write Data: ");
    gets(str);

    printf("Data written in memory: %s\n", str);

    shmdt(str);
    return 0;
}

/*
$ gcc sharedmem_w.c 
sharedmem_w.c: In function ‘main’:
sharedmem_w.c:13:5: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
   13 |     gets(str);
      |     ^~~~
      |     fgets
/usr/bin/ld: /tmp/ccD6bouJ.o: in function `main':
sharedmem_w.c:(.text+0x73): warning: the `gets' function is dangerous and should not be used.

*/

