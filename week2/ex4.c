#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int a, b;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    swap(&a, &b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}