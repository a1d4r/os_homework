#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 256

// To run program in background use: command args &
// Example: 
// sleep 5 &
// ls -lah
int main() {
    char command[SIZE];
    fgets(command, SIZE, stdin);
    while (strcmp(command, "exit\n") != 0) {
        system(command);
        fgets(command, SIZE, stdin);
    }
    return 0;
}