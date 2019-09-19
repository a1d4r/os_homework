#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define RUNNING 0
#define SLEEPING 1

pthread_t consumer, producer;
int n_items;

int consumer_state;
int producer_state;

void produce_item() {
    n_items++;
}

void consume_item() {
    n_items--;
}

void *producer_func() {
    while (1) {
        if (producer_state == RUNNING) {
            if (n_items == N) {
                producer_state = SLEEPING;
            } else {
                produce_item();
                if (n_items == 1) 
                    consumer_state = RUNNING;
            }
        }
        usleep(10);
    }
}

void *consumer_func() {
    while (1) {
        if (consumer_state == RUNNING) {
            if (n_items == 0) {
                consumer_state = SLEEPING;
            } else {
                consume_item();
                if (n_items == N - 1)
                    producer_state = RUNNING;
            }
        }
        usleep(10);
    }
}

int main() {
    producer_state = RUNNING;
    consumer_state = RUNNING;
    n_items = 0;
    pthread_create(&producer, NULL, producer_func, NULL);
    pthread_create(&consumer, NULL, consumer_func, NULL);
    while (1) {
        printf("n_items: %d\n", n_items);
        printf("producer_state: %s\n", producer_state ? "Sleeping" : "Running");
        printf("consumer_state: %s\n", consumer_state ? "Sleeping" : "Running");
        usleep(100000);
    }
}