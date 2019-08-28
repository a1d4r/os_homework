#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No integer argument!\n");
        return 0;
    }
    int n = atoi(argv[1]);
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++)
            putchar(' ');
        for (int j = 0; j < 2 * i + 1; j++)
            putchar('*');
        for (int j = 0; j < n - i - 1; j++)
            putchar(' ');
        putchar('\n');
    }
    return 0;
}