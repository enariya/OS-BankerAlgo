# OS-BankerAlgo
**Banker’s Algorithm for deadlock avoidance:**

Implementing the Banker’s algorithm and checking if the system in a safe state? If Yes, then what is the safe sequence will be printed.

**Compile Instruction:**

c++ banker.cpp

./a.out file1.txt  //or replace the file name

**Example:**

Ektas-MacBook-Air:OS-BankerAlgo ektanariya$ c++ banker.cpp
Ektas-MacBook-Air:OS-BankerAlgo ektanariya$ ./a.out file1.txt
Process          Allocation      Max     Need
P0       0 1 0          7 5 3           7 4 3
P1       2 0 0          3 2 2           1 2 2
P2       3 0 2          9 0 2           6 0 0
P3       2 1 1          2 2 2           0 1 1
P4       0 0 2          4 3 3           4 3 1
Safe State. Safe Sequence: 
p1 p3 p4 p0 p2 

<img width="438" alt="Screen Shot 2022-04-22 at 1 50 43 PM" src="https://user-images.githubusercontent.com/60280129/164768222-b99c3427-2de9-460c-b849-3ce57f247dfe.png">
