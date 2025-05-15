#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

sem_t x, y;
int readercount = 0;

void *reader(void* param) {
    sem_wait(&x);
    readercount++;
    
    if (readercount == 1) 
        sem_wait(&y);  // First reader blocks writers
    
    sem_post(&x);
    
    printf("%d reader is inside\n", readercount);
    sleep(3);
    
    sem_wait(&x);
    readercount--;
    
    if (readercount == 0) 
        sem_post(&y);  // Last reader unblocks writers
    
    sem_post(&x);
    
    printf("%d Reader is leaving\n", readercount + 1);
    return NULL;
}

void *writer(void* param) {
    printf("Writer is trying to enter\n");
    sem_wait(&y);  // Only one writer allowed
    printf("Writer has entered\n");
    sleep(3);
    printf("Writer is leaving\n");
    sem_post(&y);
    return NULL;
}

int main() {
    int nReaders, nWriters, i;
    
    printf("Enter the number of readers: ");
    scanf("%d", &nReaders);
    
    printf("Enter the number of writers: ");
    scanf("%d", &nWriters);
    
    pthread_t readerthreads[nReaders], writerthreads[nWriters];
    
    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);
    
    for (i = 0; i < nReaders; i++)
        pthread_create(&readerthreads[i], NULL, reader, NULL);
    
    for (i = 0; i < nWriters; i++)
        pthread_create(&writerthreads[i], NULL, writer, NULL);
    
    for (i = 0; i < nReaders; i++)
        pthread_join(readerthreads[i], NULL);
    
    for (i = 0; i < nWriters; i++)
        pthread_join(writerthreads[i], NULL);
    
    sem_destroy(&x);
    sem_destroy(&y);
    
    return 0;
}

