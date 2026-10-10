
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2
#define ITEMS_PER_PRODUCER 500000
#define BUFFER_SIZE 50
#define STOP_ITEM -1

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

long long produced = 0;
long long consumed = 0;

void *producer(void *arg)
{
    (void)arg;

    for (int i = 0; i < ITEMS_PER_PRODUCER; i++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = i;
        in = (in + 1) % BUFFER_SIZE;
        produced++;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }

    return NULL;
}

void *consumer(void *arg)
{
    (void)arg;

    while (1)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        if (item != STOP_ITEM)
            consumed++;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        if (item == STOP_ITEM)
            break;
    }

    return NULL;
}

int main(void)
{
    pthread_t producers[NUM_PRODUCERS];
    pthread_t consumers[NUM_CONSUMERS];

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    for (int i = 0; i < NUM_CONSUMERS; i++)
    {
        if (pthread_create(&consumers[i], NULL,
                           consumer, NULL) != 0)
        {
            perror("pthread_create consumer");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_PRODUCERS; i++)
    {
        if (pthread_create(&producers[i], NULL,
                           producer, NULL) != 0)
        {
            perror("pthread_create producer");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_PRODUCERS; i++)
        pthread_join(producers[i], NULL);

    for (int i = 0; i < NUM_CONSUMERS; i++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = STOP_ITEM;
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++)
        pthread_join(consumers[i], NULL);

    printf("Total items produced: %lld\n", produced);
    printf("Total items consumed: %lld\n", consumed);

    if (produced == consumed &&
        produced == (long long)NUM_PRODUCERS * ITEMS_PER_PRODUCER)
        printf("Synchronization: CORRECT\n");
    else
        printf("Synchronization: ERROR\n");

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}

