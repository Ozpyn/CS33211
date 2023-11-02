/*
    Gabriel Mingle
    CS 33211: Operating Systems
    Dr. Qiang Guan
    Programming Assignment #1: Producer Consumer Problem
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxItems 5    // To limit the run-time of the program
#define TableSize 2   // Size of the Table, Assignment defines the max is 2
#define NumProducer 1 // Produce More??
#define NumConsumer 1 // Eat more??

// Producer generates items and places into table
// Consumer eats items
// Table only holds 2 items at once
// No Items? -> Consumer Waits
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
