#include"header.h"

//Generate sequence of inserts and deletes where I stands for insert and D for delete
char * generate_seq(int n)
{
	char* sequence = (char*) malloc(n*sizeof(char));
	srand(time(NULL));
	int c=0, i;
	for (i = 0; i< n; i++)
	{
		sequence[i] = "IID"[rand() %3];	//IID is used so that we try to make sure insert capacity is reached
		if (sequence[i] == 'I')
			c++;
		if (c == n/2)	//Assume that inserts and deletes are equally likely. Change to n/4 means only 25% of ops will be insert
			break;
	}
	for (int j = i; j< n; j++)
	{
		sequence[j] == 'D';	//If limit reached fill rest with deletes
	}
	return sequence;
}

//Set initial factors for dynamic table
struct dynamic_table_info initialise(struct dynamic_table_info base)
{
	base.max_size = 1;	//Initial size and how many elements it can hold at that time
	base.numbers = (int*)malloc(sizeof(int)* base.max_size);	//Dynamic Array
	base.current_size = 0;	//How many elements are there now
	base.increase_factor = 1.5;	//Factor by which size of dynamic table should increase 
	base.decrease_factor = 0.75;	//Factor by which size of dynamic table should decrease 
	return base;
}

//Insert into dynamic table
struct dynamic_table_info add(struct dynamic_table_info base, int element)
{
	if (base.current_size == base.max_size)	//If size reaches max
	{
		base = make_bigger(base);
	}
	base.numbers[base.current_size] = element;	//Add to table
	base.current_size++;				//Change current size
	for (int k =0; k< base.current_size; k++)	//Display current contents
		printf("%d ", base.numbers[k]);
	
	printf("\tCurrently: %d, Max: %d", base.current_size, base.max_size);	//Display summary of current stack
	printf("\n");
	return base;
	
}

//Increase the size of dynamic table if needed
struct dynamic_table_info make_bigger(struct dynamic_table_info base)
{
	int old_size = base.max_size;
	base.max_size = (int)(old_size*base.increase_factor) + 1;	//Change max size
	int * old_numbers= (int*)malloc(sizeof(int)* old_size);
	//In case realloc returns different address, copy numbers so you dont lose them
	memcpy(old_numbers, base.numbers, sizeof(int)* old_size);	
	base.numbers = (int *)realloc(base.numbers, sizeof(int)*base.max_size);
	for(int i =0; i< old_size ; i++)
	{
		base.numbers[i] = old_numbers[i];
	}
	free(old_numbers);
	return base;
}

//Function to remove element from dynamic table
struct dynamic_table_info remove1(struct dynamic_table_info base)
{
	if (base.current_size == 0)	//If empty
		printf("EMPTY");
	else
	{
		base.numbers[base.current_size-1] = 0;	//Change value to 0
		base.current_size--;	//Reduce current size
		if (base.current_size == 0)	//If it just became empty print this
			printf("BECAME EMPTY NOW");
		else if ((int)(base.max_size*base.decrease_factor) > base.current_size)
		{
			base = make_smaller(base); //Reduce size if needed
		}
	}
			
	for (int k =0; k< base.current_size; k++)	//Display current stack
		printf("%d ", base.numbers[k]);

	printf("\tCurrently: %d, Max: %d", base.current_size, base.max_size);	//Summary of current stack

	printf("\n");
	return base;
}

//Reduce size if needed
struct dynamic_table_info make_smaller(struct dynamic_table_info base)
{
	int old_size = base.current_size;
	base.max_size = base.current_size;	//Reduce size
	int * old_numbers= (int*)malloc(sizeof(int)* old_size);
	//In case realloc returns different address, copy numbers so you dont lose them
	memcpy(old_numbers, base.numbers, sizeof(int)* old_size);
	base.numbers = (int *)realloc(base.numbers, sizeof(int)*base.max_size);
	for(int i =0; i< old_size ; i++)
	{
		base.numbers[i] = old_numbers[i];
	}
	free(old_numbers);
	return base;
}

//Freedom from allocation!
void deallocate(struct dynamic_table_info base)
{
	free(base.numbers);
}

//Return time
long int print_time(struct timespec start,struct timespec end)
{
	if (end.tv_nsec	> start.tv_nsec)
		return end.tv_nsec - start.tv_nsec;
	else
		return (1000000000 - start.tv_nsec) + end.tv_nsec;

}





		
	















