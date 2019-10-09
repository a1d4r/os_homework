#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main() {
    for (int i = 0; i < 10; i++) {
        void* ptr = malloc(10*1024*1024);
        if (ptr == NULL) {
            printf("Error: malloc\n");
            exit(1);
        }
        memset(ptr, 0, 10*1024*1024);
        struct rusage usage;
        if (getrusage(RUSAGE_SELF, &usage) == -1) {
            printf("Error: getrusagse\n");
            exit(1);
        }
        printf("%ld\n", usage.ru_maxrss);
        sleep(1);
    }
    return 0;
}