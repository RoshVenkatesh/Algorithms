This code uses transition rules given for an NFA and converts into a DFA, giving the output in the same format that input was given

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

Note: 	Lambda transitions are represented with a -1 in the input column.
	Lambda transitions entail being able to move to the start state itself as well
	Array of integers (0 and 1) has been used to represent all states that can be reached from a start state.


RUN COMMANDS:
gcc -c dfaconvmain.c -lm
gcc -c dfaconvfun.c -lm
gcc dfaconvmain.o dfaconvfun.o -lm


./a.out < input1.txt
