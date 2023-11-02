
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
