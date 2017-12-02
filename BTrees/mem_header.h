#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define t 3

struct data
{
	long long int index;
	char string1[4];
	char string2[5];
	int val1;
	int val2;
	//long long int index;
};

struct node
{ 
	struct data values[(2 * t) - 1];
	int reference[(2 * t)];
	int count;
	int leaf;

};

struct node * create() ;
struct node *split(struct node *root, int curr);
struct node *split_and_push(struct node *root,int curr,int prev);
void insert(struct node *root,int curr,int prev, struct data val);
void freefunction(struct node *root);
struct data search (struct node * root, int curr, long long int val);
void delete_final(struct node *root, int curr ,struct data val, int loc);
struct node* merge(struct node * root, int curr, int prev);
void delete_value (struct node * root, int curr, int prev, long long int val);
