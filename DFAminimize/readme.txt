This code uses transition rules given for DFA and minimizes, giving the output in the same format that input was given

Inputs:
1. Number of states
2. Number of input variables
3. Which is the initial state
4. The number of final states'
5. All the final states
For each transition function:
	1. Where the transition starts,
	2. The input symbol scanned,
	3. Where the transition function ends.

RUN COMMANDS:
gcc -c minimize.c 
gcc -c minimizemain.c 
gcc minimize.o minimizemain.o 


./a.out < ip2.txt
