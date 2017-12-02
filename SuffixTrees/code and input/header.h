#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Node{
	struct Node* children[256];
	int start;
	int end;
	int leaf_suf_number;
};
struct data
{
	char title[100];
	char tale[5000];
	int score;
};
struct Node *newNode(int start, int end, int is_leaf);
void add_node(struct Node *root,int start_index, char *text);
void freefunction(struct Node *root);
void exists(char *pattern, struct Node * root, char *text, char * title, int sub_part);
void leaf(struct Node *root, char *text, char * title);
void caller_longest_match(char *pattern, struct Node * root, char *text, char *title);
int longest_match(char *pattern, struct Node * root, char *text, char *title);
void leaf2(struct Node *root, char * text, char * title);
int min(int * arr, int count_arr);
void global_init_function();
int evaluate(char *text, int word_count);
int ordered(int * arr_min, int min_count);
void leaf3(struct Node *root,char * text, char * title);
void seq_sort(struct data *tales, int n);
void display(struct data *tales, int n);
