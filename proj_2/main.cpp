/*****************
 * Operating Systems: Project 2
 * Michael Dickensheets
 * 10/24/2018
 ******************/

#include <iostream>
#include <pthread.h>
#include <mutex>
#include "dllist.h"

pthread_mutex_t m;
Dllist list;

void* produce1(void *vargp){
        pthread_mutex_lock(&m);
            std::cout << "P1 before:";
            list.print();
            list.produce(false);
            std::cout << "P1 after:";
            list.print();
        pthread_mutex_unlock(&m);
        return NULL;
}

void* produce2(void *vargp){
        pthread_mutex_lock(&m);
            std::cout << "P2 before:";
            list.print();
            list.produce(true);
            std::cout << "P2 after:";
            list.print();
        pthread_mutex_unlock(&m);
        return NULL;
}

void* consume1(void *vargp){
        pthread_mutex_lock(&m);
            std::cout << "C1 before:";
            list.print();
            list.consume(false);
            std::cout << "C1 after:";
            list.print();
        pthread_mutex_unlock(&m);
        return NULL;
}

void* consume2(void *vargp){
        pthread_mutex_lock(&m);
            std::cout << "C2 before:";
            list.print();
            list.consume(true);
            std::cout << "C2 after:";
            list.print();
        pthread_mutex_unlock(&m);
        return NULL;
}
int main(){

    pthread_t threads[4];
    pthread_create(&threads[0], NULL, produce1, NULL);
    pthread_create(&threads[1], NULL, produce2, NULL);
    pthread_create(&threads[2], NULL, consume1, NULL);
    pthread_create(&threads[3], NULL, consume2, NULL);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);

    
    return 0;
}
