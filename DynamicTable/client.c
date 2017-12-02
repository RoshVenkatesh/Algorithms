#include"header.h"
int main()
{
	int n = 1000;	//This is a fixed value of number of operations (inserts and deletes that will happen)
	int ins = 0, del = 0;	//Count for number of inserts and deletes
	srand(time(NULL));	//Randomize numbers getting put in a list
	long long int sum_time_ins = 0,sum_time_del = 0; //Store total time taken for insertions and deletions
	long int max_ins = 0, max_del = 0 ; //Store max time taken for an insertion and and a deletion
	char* sequence = generate_seq(n); 	//DS to store the sequence of operations IID means 2 inserts and a delete 
	struct dynamic_table_info table1;	//DS to host the array and some other factors
	struct timespec start, end;	//Vaiables for time checking
	table1 = initialise(table1);	//Function to set initial parameters for the dynamic table
	int element;
	for (int i = 0; i< n; i++)
	{
		if (sequence[i] == 'I') 	//If sequence operation read is an insert
		{
			printf("Element you want to enter: ");
			element = rand()%1000;
			printf("%d\n", element);
			printf("INSERTING- ");
			clock_gettime(CLOCK_REALTIME, &start);
			table1 = add(table1, element);
			clock_gettime(CLOCK_REALTIME, &end);
			long int tym = print_time(start,end);
			printf("FOR INSERTION TIME: %ld nanoseconds\n", tym );
			ins++;
			if (tym > max_ins)	//To find max insertion time
				max_ins = tym;
			sum_time_ins+= tym;	//Find total time
			printf("\n");
		}
		else	//If sequence operation is a deletion
		{
			printf("DELETING- ");
			clock_gettime(CLOCK_REALTIME, &start);
			table1 = remove1(table1);
			clock_gettime(CLOCK_REALTIME, &end);
			long int tym = print_time(start,end);
			printf("FOR DELETION TIME: %ld nanoseconds\n", tym);
			del++;
			if (tym > max_del)
				max_del = tym;
			sum_time_del+= print_time(start,end);
			printf("\n");
		}
	}
	free(sequence); //Deallocate memory for the sequence
	printf("\n");
	//Final summary
	printf("\n SUMMARY:\n");
	printf("%d inserts, %lld nanoseconds \n%d deletes, %lld nanoseconds\n", ins, sum_time_ins, del, sum_time_del);
	printf("Max time for Insertion: %ld nanoseconds\n", max_ins);
	printf("Max time for Deletion: %ld nanoseconds\n", max_del);
	printf("TOTAL TIME: %lld nanoseconds\n", sum_time_ins + sum_time_del); 
	printf("AVERAGE time for Insertion: %lld nanoseconds\n", sum_time_ins/ ins);
	printf("AVERAGE time for Deletion: %lld nanoseconds\n", sum_time_del / del);
	printf("OVERALL AVERAGE TIME: %lld nanoseconds\n", (sum_time_ins + sum_time_del) / n); 
	printf("\n");
	printf("Please refer to Summary.ods for matrix and calculations\n");
	printf("We see that the optimum value for increase_factor is 1.5 and decrease_factor is 0.25\n");
	printf("Also, we can conclude that insertion operations take more time than deletions because, more the insertions, more is the average time\n")  ;
	deallocate(table1);	//Free the array (What is left of it!)

	
}

	
	
