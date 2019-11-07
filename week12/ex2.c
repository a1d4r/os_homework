#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char ** argv) {
    // Open files
    int first = argc > 1 && strcmp(argv[1], "-a") == 0 ? 2 : 1;
    if (argc <= first) {
        fprintf(stderr, "Not enough arguments\n");
        exit(1);
    } 
    int fd[argc];
    for (int i = first; i < argc; i++) {
        // with -a: append to the end of the files
        // without -a: clear existing files and create new
        fd[i] = open(argv[i], O_WRONLY | O_CREAT | (first == 1 ? O_TRUNC : O_APPEND), 0600);
        if (fd[i] < 0) {
            fprintf(stderr, "Cannot open file %s\n", argv[i]);
            exit(1);
        }
    }
    // Read stdin and write to stdout and files
    char c;
    while (read(STDIN_FILENO, &c, 1) > 0) {
        write(STDOUT_FILENO, &c, 1);
        for (int i = first; i < argc; i++) {
            if (write(fd[i], &c, 1) != 1) {
                fprintf(stderr, "Cannot write to file %s\n", argv[i]);
                exit(1);
            }
        }
    }
    // Close files
    for (int i = first; i < argc; i++) {
        if (close(fd[i]) < 0) {
            fprintf(stderr, "Cannot close file %s\n", argv[i]);
            exit(1);
        }
    }
    return 0;
}