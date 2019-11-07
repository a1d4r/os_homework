#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    // Open file
    int fd = open("/dev/random", O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Error: can't open file");
        exit(1);
    }
    // Read file
    char str[20];
    int len = read(fd, str, sizeof(str));
    if (len < 0) {
        fprintf(stderr, "Error: can't read file");
        exit(1);
    }
    // Convert characters to printable
    for (int i = 0; i < 20; i++)
        str[i] = ((unsigned char) str[i]) % 94 + 33;
    str[19] = '\0';
    printf("%s\n", str);
    return 0;
}