#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t n = fork();
    if (n > 0) { // parent
        printf("Hello from parent [PID - %d]\n", getpid());
    } else if (n == 0) { // child
        printf("Hello from child  [PID - %d]\n", getpid());
    } else {
        printf("Error\n");
    }
    return 0;
}