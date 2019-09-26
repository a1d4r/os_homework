#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    if (pipe(fd) < 0)
        exit(1);

    pid_t rc = fork();
    if (rc > 0) {
        pid_t rc2 = fork();
        // parent
        if (rc2 > 0) {
            printf("PIDs of children: %d %d\n", rc, rc2);
            printf("Sending the PID of the 2nd child to the 1st child...\n");
            write(fd[1], &rc2, sizeof(pid_t));
            int status;
            printf("Waiting for state changes in the 2nd child\n");
            waitpid(rc2, NULL, 0);
            // wait(0);
            printf("The 2nd child has changed the state\n");
        // child 2
        } else if (rc2 == 0) {
            printf("Starting the 2nd child...\n");
            while(1);
        } else {
            exit(1);
        }
    // child 1
    } else if (rc == 0) {
        int pid_child2;
        printf("Reading the PID of the 2nd child by the 1st child...\n");
        read(fd[0], &pid_child2, sizeof(pid_t));
        printf("PID of the 2nd child: %d\n", pid_child2);
        sleep(3);
        printf("Sending SIGTERM to the 2nd child by the 1st child\n");
        kill(pid_child2, SIGTERM);
    } else {
        exit(1);
    }
    exit(0);
}