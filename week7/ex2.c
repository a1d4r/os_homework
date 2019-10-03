#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = i;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}