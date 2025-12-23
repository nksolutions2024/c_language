#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("hello.c", "w");

    if (fp == NULL) {
        return 1;
    }

    char str[] =
        "#include <stdio.h>\n\n"
        "int main() {\n"
        "    printf(\"hello world!\\n\");\n"
        "    return 0;\n"
        "}\n";

    fwrite(str, 1, strlen(str), fp);

    fclose(fp);

    return 0;
}

