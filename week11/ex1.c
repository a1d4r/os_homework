#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd, size;
    char *str = "This is a nice day";
    int str_len = strlen(str);
    if ((fd = open("ex1.txt", O_RDWR)) < 0) {
        perror("open error");
        return -1;
    }
    if (ftruncate(fd, str_len) < 0) {
        perror("ftruncate error");
        return -1;
    }
    char *fmem;
    if ((fmem = mmap(0, str_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED) {
        perror("mmap error");
        return -1;
    }
    strcpy(fmem, str);
    msync(fmem, str_len, MS_SYNC);
    munmap(fmem, str_len);
    close(fd);
    return 0;
}