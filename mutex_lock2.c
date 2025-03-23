#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;  // Mutex declaration
int shared_counter = 0;

void* increment_counter(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&lock);  // Lock before accessing shared resource
        shared_counter++;
        printf("Counter: %d\n", shared_counter);
        pthread_mutex_unlock(&lock);  // Unlock after operation
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    pthread_mutex_init(&lock, NULL);  // Initialize mutex

    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);  // Destroy mutex
    return 0;
}


// output:
// Counter: 1
// Counter: 2
// Counter: 3
// Counter: 4
// Counter: 5
// Counter: 6
// Counter: 7
// Counter: 8
// Counter: 9
// Counter: 10


// without mutex_lock
// Counter: 1
// Counter: 3
// Counter: 4
// Counter: 5
// Counter: 6
// Counter: 2
// Counter: 7
// Counter: 8
// Counter: 9
// Counter: 10