#include <stdio.h>
#include <unistd.h>

#define LEN 256

int main() {
    char str1[LEN] = "Hello, World!";
    char str2[LEN] = "";
    printf("str1=%s\n", str1);
    printf("str2=%s\n", str2);
    int fd[2];
    if (pipe(fd) < 0)
        exit(1);
    write(fd[1], str1, LEN);
    read(fd[0], str2, LEN);
    printf("str1=%s\n", str1);
    printf("str2=%s\n", str2);
    return 0;
}