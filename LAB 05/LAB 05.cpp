#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

sem_t x, y;
int readercount = 0;

void* reader(void* param) {
    sem_wait(&x);
    readercount++;
    if (readercount == 1)
        sem_wait(&y); // First reader blocks writers
    sem_post(&x);

    printf("Reader %d is inside\n", readercount);
    sleep(3);

    sem_wait(&x);
    readercount--;
    if (readercount == 0)
        sem_post(&y); // Last reader unblocks writers
    sem_post(&x);

    printf("Reader %d is leaving\n", readercount + 1);
    return NULL;
}

void* writer(void* param) {
    printf("Writer is trying to enter\n");
    sem_wait(&y); // Only one writer allowed
    printf("Writer has entered\n");
    sleep(3);
    printf("Writer is leaving\n");
    sem_post(&y);
    return NULL;
}

int main() {
    pthread_t r1, r2, w1;

    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);

    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);
    pthread_create(&r2, NULL, reader, NULL);

    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);

    sem_destroy(&x);
    sem_destroy(&y);

    return 0;
}

