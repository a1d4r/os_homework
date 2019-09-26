#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define LEN 256

int main() {
    char str1[LEN] = "Hello, World!";
    char str2[LEN] = "";
    printf("str1=%s\n", str1);
    printf("str2=%s\n", str2);
    int fd[2];
    if (pipe(fd) < 0)
        exit(1);

    pid_t rc = fork();
    // parent
    if (rc > 0) {
        write(fd[1], str1, LEN);
    // child
    } else if (rc == 0) {
        read(fd[0], str2, LEN);
        printf("str2=%s\n", str2);
    } else {
        exit(1);
    }
    return 0;
}