## Producer Consumer Assignment

Run the program:
```
gcc producer-consumer.c -pthread -lrt -o procon
./procon
```

There are defined variables the user can modify:
- MaxItems
    - Determines the max number of items to be made / destroyed
- Table Size
    - Determines the size of the table. (How large the buffer is)
- NumProducer
    - How many producer characters there will be.
- NumConsumer
    - How many consumer characters there will be.