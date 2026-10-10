
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t resourceA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t resourceB = PTHREAD_MUTEX_INITIALIZER;

void *thread1(void *arg)
{
    (void)arg;

    printf("Thread 1: Requesting Resource A\n");
    pthread_mutex_lock(&resourceA);
    printf("Thread 1: Acquired Resource A\n");

    sleep(1);

    printf("Thread 1: Requesting Resource B\n");
    pthread_mutex_lock(&resourceB);
    printf("Thread 1: Acquired Resource B\n");

    printf("Thread 1: Working with both resources\n");

    pthread_mutex_unlock(&resourceB);
    pthread_mutex_unlock(&resourceA);

    return NULL;
}

void *thread2(void *arg)
{
    (void)arg;

    printf("Thread 2: Requesting Resource A\n");
    pthread_mutex_lock(&resourceA);
    printf("Thread 2: Acquired Resource A\n");

    sleep(1);

    printf("Thread 2: Requesting Resource B\n");
    pthread_mutex_lock(&resourceB);
    printf("Thread 2: Acquired Resource B\n");

    printf("Thread 2: Working with both resources\n");

    pthread_mutex_unlock(&resourceB);
    pthread_mutex_unlock(&resourceA);

    return NULL;
}

int main(void)
{
    pthread_t t1, t2;
    setbuf(stdout, NULL);

    if (pthread_create(&t1, NULL, thread1, NULL) != 0)
    {
        perror("pthread_create thread1");
        return EXIT_FAILURE;
    }

    if (pthread_create(&t2, NULL, thread2, NULL) != 0)
    {
        perror("pthread_create thread2");
        pthread_join(t1, NULL);
        return EXIT_FAILURE;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&resourceA);
    pthread_mutex_destroy(&resourceB);

    printf("Program completed without deadlock.\n");
    return 0;
}

