#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fdin, fdout;
    if ((fdin = open("ex1.txt", O_RDONLY)) < 0) {
        perror("open input error");
        return -1;
    }
    if ((fdout = open("ex1.memcpy.txt", O_RDWR | O_CREAT | O_TRUNC, 0600)) < 0) {
        perror("open output error");
        return -1;
    }
    struct stat stin;
    if (fstat(fdin, &stin) < 0) {
        perror("fstat error");
        return -1;
    }
    if (ftruncate(fdout, stin.st_size) < 0) {
        perror("ftruncate error");
        return -1;
    }
    void *input, *output;
    if ((input = mmap(0, stin.st_size, PROT_READ, MAP_SHARED, fdin, 0)) == MAP_FAILED) {
        perror("mmap input error");
        return -1;
    }
    if ((output = mmap(0, stin.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0)) == MAP_FAILED) {
        perror("mmap output error");
        return -1;
    }
    memcpy(output, input, stin.st_size);
    munmap(input, stin.st_size);
    munmap(output, stin.st_size);
    close(fdin);
    close(fdout);
    return 0; 
}