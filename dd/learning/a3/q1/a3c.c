#include <unistd.h>     // write(), close()
#include <fcntl.h>      // open()
#include <sys/stat.h>   // file permissions
#include <errno.h>      // errno
#include <stdio.h>      // perror()

int main() {
    int fd;

    /* open() */
    fd = open("hello.c", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    const char code[] =
        "#include <stdio.h>\n\n"
        "int main() {\n"
        "    printf(\"hello world!\\n\");\n"
        "    return 0;\n"
        "}\n";

    /* write() */
    ssize_t total = 0;
    ssize_t len = sizeof(code) - 1;

    while (total < len) {
        ssize_t written = write(fd, code + total, len - total);
        if (written == -1) {
            perror("write");
            close(fd);   // best effort cleanup
            return 1;
        }
        total += written;
    }

    /* close() */
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}

