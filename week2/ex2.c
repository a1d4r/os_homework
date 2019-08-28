#include <stdio.h>
#include <string.h>

#define SIZE 256;

int main() {
    printf("Enter a string: ");
    char string[256];
    gets(string);
    for (int i = strlen(string) - 1; i >= 0; i--)
        putchar(string[i]);
    putchar('\n');
    return 0;
}