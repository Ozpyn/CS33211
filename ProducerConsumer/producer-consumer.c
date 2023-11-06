/*
    Gabriel Mingle
    CS 33211: Operating Systems
    Dr. Qiang Guan
    Programming Assignment #1: Producer Consumer Problem
*/

#include <pthread.h>   //Refer to: https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread.h.html
#include <semaphore.h> //Refer to: https://pubs.opengroup.org/onlinepubs/7908799/xsh/semaphore.h.html
#include <stdlib.h>
#include <stdio.h>

#define MaxItems 5    // To limit the run-time of the program
#define TableSize 2   // Size of the Table, Assignment defines the max is 2
#define NumProducer 1 // Produce More??
#define NumConsumer 1 // Eat more??

// Producer generates items then places into table
// Consumer takes item from table then eats items
// Table only holds 2 items at once
// No Items? -> Consumer Waits
// No Space? -> Producer Waits
// Use Semaphores to sync producer and consumer
// Consider Mutual Exclusion
// Use Threads
// Shared Memory for the table
// Expected run command:
/*
gcc producer.c -pthread -lrt -o producer
gcc consumer.c -pthread -lrt -o consumer
./producer & ./consumer &
*/

sem_t empty;           // Semaphore unlocked
sem_t full;            // Semaphore locked
int in = 0;            // Table ID of input
int out = 0;           // Table ID of output
                       /*
                       In and Out will be used by the producer and consumer to
                       communicate what part of the buffer has been emptied
                       and what will be emptied
                       */
int buffer[TableSize]; // Make a buffer with the size defined

pthread_mutex_t mutex; // Make a mutex lock

void *producer(void *pno)
{
    // Make Item
    // Insert Item when space & able to make more

    int item;                          // Plain placeholder item
    for (int i = 0; i < MaxItems; i++) // Loop until created Max Number of items
    {
        item = rand();                                                                // Produce an random item
        sem_wait(&empty);                                                             // Wait until semaphore is empty
        pthread_mutex_lock(&mutex);                                                   // Lock Mutex lock
        buffer[in] = item;                                                            // Place item in buffer
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno), buffer[in], in); // Exclaim item in buffer
        in = (in + 1) % TableSize;                                                    // Set next input
        pthread_mutex_unlock(&mutex);                                                 // Unlock Mutex lock
        sem_post(&full);                                                              // Change semaphore to indicate full
    }
}
void *consumer(void *cno)
{
    // Remove item if item & not eating
    // Eat item
    for (int i = 0; i < MaxItems; i++)
    {
        sem_wait(&full);                                                        // Wait until semaphore is full
        pthread_mutex_lock(&mutex);                                             // Lock Mutex Lock
        int item = buffer[out];                                                 // Take Item out of the buffer
        printf("Consumer %d: Ate Item %d from %d\n", *((int *)cno), item, out); // Print eat item string
        out = (out + 1) % TableSize;                                            // Set out to next out
        pthread_mutex_unlock(&mutex);                                           // Unlock Mutex
        sem_post(&empty);                                                       // Change semaphore to empty
    }
}
int main()
{
    // Specify producer and consumer threads
    // Initialize mutex lock
    // Initialize semaphores to indicate full or empty
    // Produce and Destroy Logic
    // Unassign mutex lock (free memory)
    // Unassign semaphores (free memory)
    pthread_t pro[NumProducer], con[NumConsumer];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, TableSize);
    sem_init(&full, 0, 0);
    int a[5] = {1, 2, 3, 4, 5}; // Just used for numbering the producer and consumer
    for (int i = 0; i < NumProducer; i++)
    {
        // Create the desired number of Producer threads
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for (int i = 0; i < NumConsumer; i++)
    {
        // Create the desired number of Consumer Threads
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }
    for (int i = 0; i < NumProducer; i++)
    {
        // Terminate the desired number of producer threads
        pthread_join(pro[i], NULL);
    }
    for (int i = 0; i < NumConsumer; i++)
    {
        // Terminate the desired number of consumer threads
        pthread_join(con[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}