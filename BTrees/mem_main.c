#include"mem_header.h"

int globalcount = 0;
struct node *root;

void main()
{
	FILE *f;
	int curr = 0, prev = -1;
	root = create();

	struct data input[100];
	char *line;
	f = fopen("dataset.csv", "r");
	int count = 0;

	//Take input from CSV
	for (; count < sizeof(input)/sizeof(input[0]); ++count)
	{
    		int got = fscanf(f, "%lld,%[^,],%[^,],%d,%d", &input[count].index, input[count].string1, input[count].string2, &input[count].val1, &input[count].val2);
    		if (got != 5) 
			break; 
	}

	int i;
	
	//Insert first 70 values from CSV into tree
	for (i = 0; i<70; i++)
	{
		insert(root,curr,prev,input[i]);
	}

	//Displaying references for each array node
	for(int m=0; m<= globalcount; m++)
	{
		if (root[m].count != 0)
		{
			printf("%d ", m);
			for (int k =0; k<= root[m].count ; k++)
				printf("%d ", root[m].reference[k]);
			printf("\n");
		}
	}

	printf("\n");
	//Displaying values for each array node
	for(int m=0; m<= globalcount; m++)
	{
		if (root[m].count != 0)
		{
			printf("%d ", m);
			for (int k =0; k< root[m].count ; k++)
				printf("%lld ", root[m].values[k].index);
			printf("\n");
		}
	}		
	

	//Search for any random already inserted value 
	struct data result;
	/*for (int j =0 ; j<70; j++)
	{
		result = search(root,curr,input[j].index);

		if (result.index != 0)
			printf("FOUND %lld, %s, %s, %d, %d\n", result.index, result.string1,result.string2,result.val1,result.val2);

		else
			printf("Not Found in Btree\n");
	}*/

	//Searching for a random value 990171
	int cont;
	do
	{
		printf("\nEnter 1 for search, 2 for delete, 3 for exit: ");
		int choice;
		scanf("%d",&choice);
		if (choice == 1)
		{
			long long int mval;
			printf("\nEnter value to be searched for: ");
			scanf("%lld",&mval);
			result = search(root,curr,mval);

			if (result.index != 0)
				printf("FOUND %lld, %s, %s, %d, %d\n", result.index, result.string1,result.string2,result.val1,result.val2);

			else
				printf("Not Found in Btree\n");
		}
		else if (choice == 2)
		{
			long long int mval;
			printf("\nEnter value to be deleted: ");
			scanf("%lld",&mval);
			delete_value(root,curr,prev,mval);
		}
		else 
		{
			exit(0);
		}

		printf("Press 1 to continue: ");
		scanf("%d", &cont); 
	}while(cont == 1);


	//Deleting a random value 990171
	//Case 1: leafnode: eg 543278 
	//Case 2a: Predecessor
	//Case 2b: Sucessor
	//Case 2c: Merge the node with both its children
	//Case 3a,3b: If we need to split a node on the way
	//delete_value(root,curr,prev,335197);

	//DISPLAY AFTER A DELETION for debugging
	/*for(int m=0; m<= globalcount; m++)
	{
		if (root[m].count != 0)
		{
			printf("%d ", m);
			for (int k =0; k<= root[m].count ; k++)
				printf("%d ", root[m].reference[k]);
			printf("\n");
		}
	}

	printf("\n");
	for(int m=0; m<= globalcount; m++)
	{
		if (root[m].count != 0)
		{
			printf("%d ", m);
			for (int k =0; k< root[m].count ; k++)
				printf("%lld ", root[m].values[k].index);
			printf("\n");
		}
	}*/

	//Deallocating memory
	freefunction(root);

}
