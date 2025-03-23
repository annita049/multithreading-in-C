#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock;

void* print1(){

    pthread_mutex_lock(&lock);
    for(int i=0;i<200;i++){
        printf("+");
    }
    printf("\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* print2(){
    pthread_mutex_lock(&lock);
    for(int i=0;i<200;i++){
        printf("-");
    }
    printf("\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(){
    pthread_t thread1, thread2;

    pthread_mutex_init(&lock, NULL); // initialization of mutex
    pthread_create(&thread1, NULL, print1, NULL);
    pthread_create(&thread2, NULL, print2, NULL);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}

// output:
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// Effect:

// If thread1 (printing +) gets locked first:
// It prints all 200 "+" before thread2 can even start.
// Only after thread1 finishes, thread2 prints numbers.

// No real parallel execution—one thread fully blocks the other.