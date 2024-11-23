# Banker's Algorithm For Deadlock Avoidance

This program uses a text file, formatted in a specific way, as input. The text file contains
the data of the max matrix, allocation matrix, and available matrix. Once the program has properly
input these into 2-dimensional vectors, the need matrix can then be calculated. After that, the 
rest of the banker's algorithm is followed in order find out if the system is in a safe state,
and, if it is, print the safe sequence.

# Input File

The program supports text files in the following format as input:


Allocation

0 1 0

2 0 0

3 0 2

2 1 1

0 0 2

Max

7 5 3

3 2 2

9 0 2

2 2 2

4 3 3

Available

3 3 2

## Example Output

The safe sequence is: 

 P1, P3, P4, P0, P2

 ## Commands to Compile and Run

 g++ banker.cpp -o banker

 ./banker
