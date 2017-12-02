#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct dict
{
	int stateno;
	char stateid;
};

struct table
{
	char permutation[2];
	int crossed;
};
void minimize(int *fin);
void crossfnf(struct dict * a, struct table *b, int count, int table_index, int nfinal, int * fin);
int does_make(char* string1, char* string2);

