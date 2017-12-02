#include"header.h"

int main()
{
	FILE *q;
 	struct data tales[500];
	int data_count = 0;
	int count = 1;
 	q = fopen("AesopTales.txt", "r");
	char line[200];
	char story[10000];
	while (fgets(line, sizeof(line), q) != 0)
   	{ 	
		//if (line[strlen(line)-2] != ' ')
			line[strlen(line)-2] = '\0';
		if (strlen(line) <= 3)
		{
			if (strlen(story)==0)
			{
				count = 0;
				data_count++;
			}
			else if (count == 1)
			{
				strcpy(tales[data_count].title,story);
			}
			else if (count == 2)
			{
				strcpy(tales[data_count].tale,story);
			}
			else
			{
				strcat(tales[data_count].tale,story);
			}
			count++;	
			story[0] = '\0';
		}	   	
		else
		{
			strcat(story," ");
			strcat(story,line);
		}
	}
	char * string_to_search;
	printf("ENTER THE STRING: ");
	string_to_search = fgets(line, sizeof(line), stdin);
	int len = strlen(string_to_search);
	for (int i=0; i< len; i++)
		string_to_search[i] = tolower(string_to_search[i]);
	if (len > 0 && string_to_search[len-1] == '\n')
		string_to_search[len-1] = '\0';

	for (int j = 0; j<data_count; j++)
	{
		tales[j].score = 0;
	}

	int option;
	printf("DO YOU WANT THE SOLUTION TO PART 1,2 or 3? Enter just the number:\n");
	scanf("%d", &option);
	printf("\n\n");
	if (option == 1)
	{
		for (int j = 0; j<data_count; j++)
		{
			struct Node *root = NULL;
			root = newNode(-1,-1,-1);
			printf("TITLE: %s\n", tales[j].title);
			for (int i = 0 ; i< strlen(tales[j].tale); i++)
				add_node(root,i,tales[j].tale);

			exists(string_to_search,root, tales[j].tale, tales[j].title, option);
			printf("\n____________________________\n");
			freefunction(root);
		}
	}
	else if (option == 2)
	{
		for (int j = 0; j<data_count; j++)
		{
			global_init_function();
			struct Node *root = NULL;
			root = newNode(-1,-1,-1);
			for (int i = 0 ; i< strlen(tales[j].tale); i++)
				add_node(root,i,tales[j].tale);

			caller_longest_match(string_to_search,root, tales[j].tale, tales[j].title);
			printf("\n____________________________\n");
			freefunction(root);
		}
	}
	else if (option == 3)
	{
		//Scoring Criteria
		//1. Ratio of length of tale/ no. of times needed words appear (the lower this value the better)
		//2. Number of words in the query that were there in the tale
		//3. Whether the sequence of the words appearing in the tale was same as the query string 
		//Each of these criteria has 30 points
		printf("Refer to comments in main.c line 94 for scoring criteria\n");
		printf("Higher the score the more relavance the document has.\n");
		for (int j = 0; j<data_count; j++)
		{
			global_init_function();
			int word_count = 0;
			struct Node *root = NULL;
			root = newNode(-1,-1,-1);
			printf("TITLE: %s\n", tales[j].title);
			for (int i = 0 ; i< strlen(tales[j].tale); i++)
				add_node(root,i,tales[j].tale);
			int i = 0,mm = 0;
			char word[20];
			while (i < strlen(string_to_search)) 
			{
		      		if (string_to_search[i] == ' ') 
				{
		                	word[mm] = '\0';
					word_count++;
		                	exists(word,root, tales[j].tale, tales[j].title,option);
		                	mm = 0;
		        	} 
			else
		                word[mm++] = string_to_search[i];
		        i++;
	       		}
			word[mm] = '\0';
			word_count++;
			exists(word,root, tales[j].tale, tales[j].title,option);
			int score = evaluate(tales[j].tale, word_count);
			tales[j].score = 11 - (score/10);
			printf("\n____________________________\n");
			freefunction(root);
		}
		seq_sort(tales, data_count);
		printf("Refer to comments in main.c line 94 for scoring criteria\n");
	}
	
	else
	{
		printf("INVALID OPTION ENTERED\n");
	}
}
