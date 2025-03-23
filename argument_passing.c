#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void* print1(void* arg) {
    char *ch = (char*) arg;
    for(int i=0;i<5;i++){
        printf("%s\n", ch);
    }
    return NULL;
}

void* print2(void* arg) {
    char *ch = (char*) arg;
    for(int i=0;i<5;i++){
        printf("%s\n", ch);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&lock, NULL); // Initialize mutex
    pthread_create(&thread1, NULL, print1, "thread 1 running");
    pthread_create(&thread2, NULL, print2, "thread 2 running");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock); // Destroy mutex
    return 0;
}

