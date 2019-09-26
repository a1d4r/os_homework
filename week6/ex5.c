#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define LEN 256

int main() {
    pid_t rc = fork();
    // parent
    if (rc > 0) {
        sleep(10);
        kill(rc, SIGTERM);
    // child
    } else if (rc == 0) {
        while (1) {
            printf("I'm alive!\n");
            sleep(1);
        }
    } else {
        exit(1);
    }
    return 0;
}