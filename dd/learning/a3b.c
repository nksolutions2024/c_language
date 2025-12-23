#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
    int fd;

	
    fd = open("hello.c", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) 
    {
        return 1;
    }

    const char str[] =
        "#include <stdio.h>\n\n"
        "int main() {\n"
        "    printf(\"hello world!\\n\");\n"
        "    return 0;\n"
        "}\n";

    write(fd, str, sizeof(str)-1);

    close(fd);

    return 0;
}

