#include <stdio.h>
#include <signal.h>
#include <string.h>

void handler() {
    printf("\nSIGINT signal has been sent\n");
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handler;
    sigset_t set; 
    sigemptyset(&set);                                                             
    sigaddset(&set, SIGINT);
    sa.sa_mask = set;
    sigaction(SIGINT, &sa, 0);
    while (1) {
        sleep(1);
    }
    return 0;
}