#include <stdio.h>

// sorts the specified array a of n elements using bubble sort
void bubble_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
    }
}

int main() {
    int a[5] = {5, 3, 1, 2, 4};
    bubble_sort(a, 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}