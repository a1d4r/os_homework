#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void handler() {
    printf("The signal was handled\n");
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handler;
    sigset_t set; 
    sigemptyset(&set);                                                             
    sigaddset(&set, SIGKILL);
    sigaddset(&set, SIGSTOP);
    sigaddset(&set, SIGUSR1);
    sa.sa_mask = set;
    sigaction(SIGKILL, &sa, 0);
    sigaction(SIGSTOP, &sa, 0);
    sigaction(SIGUSR1, &sa, 0);
    while (1) {
        sleep(1);
    }
    return 0;
}