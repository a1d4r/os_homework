#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 256

int main() {
    char command[SIZE];
    fgets(command, SIZE, stdin);
    while (strcmp(command, "exit\n") != 0) {
        system(command);
        fgets(command, SIZE, stdin);
    }
    return 0;
}