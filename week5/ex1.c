#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

void *print(void *i) {
    printf("Running a function in thread %d\n", i);
    pthread_exit(NULL);
}

int main() {
    for (int i = 0; i < N; i++) {
        pthread_t thread;
        printf("Creating thread %d\n", i);
        int return_code = pthread_create(&thread, NULL, print, (void *)i);
        if (return_code != 0) {
            printf("Error: %d\n", return_code);
            exit(1);
        }
        pthread_join(thread, NULL);

    }
    pthread_exit(NULL);
}