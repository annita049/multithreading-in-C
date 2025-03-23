#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void* print1() {
    for (int i = 0; i < 200; i++) {
        pthread_mutex_lock(&lock); // Lock before printing
        printf("+");
        pthread_mutex_unlock(&lock); // Unlock after printing
    }
    printf("\n");
    return NULL;
}

void* print2() {
    for (int i = 0; i < 200; i++) {
        pthread_mutex_lock(&lock);
        printf("%d", i);
        pthread_mutex_unlock(&lock);
    }
    printf("\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&lock, NULL); // Initialize mutex
    pthread_create(&thread1, NULL, print1, NULL);
    pthread_create(&thread2, NULL, print2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock); // Destroy mutex
    return 0;
}
