## Banker's Algorithm Assignment

Run the program:
```
g++ -o bankalg bankers-algorithm.cpp
./bankalg
rm bankalg
```
If you wish to change the Allocation, Max, and Available resources please edit the included text files.

### What is Banker's Algorithm?
The banker’s algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation for the predetermined maximum possible amounts of all resources, then makes an “s-state” check to test for possible activities, before deciding whether allocation should be allowed to continue.

### Libraries Being Used:
- iostream
    - Allow for input and output.
- fstream
    - Allow the program to read files.

### Implementation
Read in tables from text documents, one for each table.

The program will only read the files if they follow the parameters:
- 3 columns * 5 rows (allocation & max)
- 3 columns * 1 row (available)
- Numbers are separated by spaces
- New line means new row

### Example Output
![Output](output.png)