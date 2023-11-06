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

void producer()
{
    // Make Item
    // Insert Item when space & able to make more
}
void consumer()
{
    // Remove item if item & not eating
    // Eat item
}
int main()
{
    // Specify producer and consumer threads
    // Initialize mutex lock
    // Initialize semaphores to indicate full or empty
    // Produce and Destroy Logic
    // Unassign mutex lock (free memory)
    // Unassign semaphores (free memory)
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, TableSize);
    sem_init(&full, 0, 0);
    int a[5] = {1, 2, 3, 4, 5}; // Just used for numbering the producer and consumer
    for (int i = 0; i < NumProducer; i++)
    {
        // Create the desired number of Producer threads
    }
    for (int i = 0; i < NumConsumer; i++)
    {
        // Create the desired number of Consumer Threads
    }
    for (int i = 0; i < NumProducer; i++)
    {
        // Terminate the desired number of producer threads
    }
    for (int i = 0; i < NumConsumer; i++)
    {
        // Terminate the desired number of consumer threads
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}