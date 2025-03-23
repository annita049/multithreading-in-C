#include<stdio.h>
#include<pthread.h>

void* print1(){
    for(int i=0;i<200;i++){
        printf("+");
    }
    printf("\n");
    return NULL;
}

void* print2(){
    for(int i=0;i<200;i++){
        printf("-");
    }
    printf("\n");
    return NULL;
}

int main(){
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, print1, NULL);
    pthread_create(&thread2, NULL, print2, NULL);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}