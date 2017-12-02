#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct dynamic_table_info
{
	int *numbers;
	int max_size;
	int current_size;
	float increase_factor;
	float decrease_factor;
};

struct dynamic_table_info add(struct dynamic_table_info base, int element);
struct dynamic_table_info remove1(struct dynamic_table_info base);
struct dynamic_table_info make_bigger(struct dynamic_table_info base);
struct dynamic_table_info initialise(struct dynamic_table_info base);
struct dynamic_table_info make_smaller(struct dynamic_table_info base);
void deallocate(struct dynamic_table_info base);
char* generate_seq(int n);
long int print_time(struct timespec start,struct timespec end);

