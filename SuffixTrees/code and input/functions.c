#include"header.h"

int count_arr= 0;
int arr [20];
int count_ind = 0;
int arr_ind[20];
int min_count = 0;
int arr_min[20];

//Function to add a node to the suffix tree
//Each node has 256 links and 3 integer values (the start of sublabel from there, end of sublabel before split and the suffix number (if any))
struct Node *newNode(int start, int end, int is_leaf)
{
	struct Node *node =(struct Node*) malloc(sizeof( struct Node));
	int i;
	//Set all child nodes to NULL initially. Each number represents the ASCII value of the next letter of the string which forms the next label
    	for (i = 0; i < 256; i++)
        	node->children[i] = NULL;
  
    	node->start = start;
    	node->end = end;
	node->leaf_suf_number = is_leaf;
  
    return node;
}

//Create an entry for a suffix within the suffix tree
void add_node(struct Node *root, int start_index, char *text)
{
	struct Node *temp = root;
	//In case that there in no substring starting from the root for that letter before hand
	if (temp -> children[tolower(text[start_index])] == NULL)
	{
		//Create a new node
		temp -> children[tolower(text[start_index])] = newNode(start_index,strlen(text)-1,start_index);
	}
	else
	{
		int flag = 0;
		struct Node * next = NULL;
		int match_len = 0;
		int start_index_copy = start_index;
		//In case the node for that letter already exists and there needs to be traversal and splitting
		next = temp -> children[tolower(text[start_index])];
		while (1)
		{
			int sub_len = (next -> end) - (next-> start) + 1;
			match_len = 0;
			//Match letters along the particular label incrementing match_len every time there is a match
			for (int i = 0 ; i< sub_len ; i++)
			{
				if (tolower(text[next-> start + i]) == tolower(text[start_index_copy + i]))
					match_len++;
				else
					break;
			}
			
			// We know that a split is needed now
			if (match_len < sub_len)
				break;
			//We know that split is needed but the next letter (1st one that did not match) does not yet have a node under it
			if (next -> children[tolower(text[start_index_copy + match_len])] == NULL)
			{
				next -> children[tolower(text[start_index+ match_len])] = newNode(start_index+ match_len,strlen(text)-1,start_index);
				flag = 1;
				break;
			}
			//All letters for that label have matched, move on to the next node and start matching again
			else if (match_len == sub_len)
			{
				temp = next;
				next = next ->  children[tolower(text[start_index_copy + match_len])];
				start_index_copy += match_len;
			}

		}
		//If new node has not already been created (except case 2 above)
		if (flag != 1)
		{
			//This type of splitting happens when the current node already has some nodes under it. End will be != strlen(text)-1
			//The split needs to take care of all nodes under the current node as well
			if (next -> end != strlen(text)-1)
			{
				struct Node *split1 = NULL;	
				struct Node *split2 = NULL;
				split1 = newNode(next -> start , next -> start + match_len - 1 , -1) ;
				split2 = newNode(start_index_copy + match_len, strlen(text)-1 , start_index);
				split1 ->children[tolower(text[split2 -> start])] = split2;
				next ->start = (next ->start) + match_len;
				split1 -> children[tolower(text[next -> start])] = next;
				temp -> children[tolower(text[split1 -> start])] = split1;
			 
			}
			//This type of splitting happens when the current node has no nodes under it. End will be == strlen(text)-1
			else if (next -> end == strlen(text)-1)
			{
			struct Node *split1 = NULL;	
			struct Node *split2 = NULL;
			split1 = newNode(next -> start + match_len, strlen(text)-1, next -> leaf_suf_number);
			next -> children[tolower(text[next -> start + match_len])] = split1;
			next -> end = (next ->start) + match_len - 1;
			if (start_index_copy + match_len < strlen(text))
			{
				split2 = newNode(start_index_copy + match_len, strlen(text)-1 , start_index);
				next -> children[tolower(text[start_index_copy + match_len])] = split2;
				next -> leaf_suf_number = -1;
			}
			else
				//In case we are at the end of the string when the split happens, only one node needs to be created 
				next -> leaf_suf_number = start_index;
			}
			
		}
	}
	
	//free(temp);
}

void global_init_function()
{
	count_arr = 0;
	for (int i =0; i<20; i++)
		arr[i] = 9999;
	min_count = 0;
	for (int i =0; i<20; i++)
		arr_min[i] = 9999;
}

//For memory deallocation				
void freefunction(struct Node *n)
{
    if (n == NULL)
        return;
    int i;
    for (i = 0; i < 256; i++)
    {
        if (n->children[i] != NULL)
        {
            freefunction(n->children[i]);
        }
    }
    free(n);
}

//Match lables of pattern with tree 
void exists(char *pattern, struct Node * root, char *text, char *title, int sub_part)
{
	count_ind = 0;
	for (int i =0; i<20; i++)
		arr_ind[i] = 9999;
	int min1 = 9999;
	struct Node *temp = root;
	int matched = 0;
	int matched_after_moving = 0;
	int flag = 0;
	temp = temp->children[tolower(pattern[matched])];
	while (temp!= NULL && matched < strlen(pattern) )
	{
		//String match between a node and a pattern sequence
		int sub_len = (temp -> end) - (temp -> start) + 1;
		for (int i = 0; i< sub_len ; i++)
		{
			if (tolower(pattern[matched_after_moving + i]) == tolower(text[temp-> start + i]))
				matched++;	
			else
				break;
		}
		matched_after_moving =matched;
		//If there is a full match
		if (matched == strlen(pattern))
		{
			//Call recursive function to find leaf notes and print the required string
			if (sub_part == 1)
				leaf(temp,text,title);
			else if (sub_part == 3)
			{
				leaf3( temp,text,title);
				min1 = min(arr_ind, count_ind);
				arr_min[min_count] = min1;
				min_count++;
			}
								
			flag = 1;
		}
		//Move to next node if everything in that node matched
		temp = temp->children[pattern[matched]];
		if (temp == NULL && flag != 1);
			
	}
	
}

//Function to recursively check for leaf nodes under a particular node.
void leaf(struct Node *root,char * text, char * title)
{
	if (!root)
		return;
 
    	if (root-> leaf_suf_number != -1)
   	{
		//Displaying result
		int i;
		int loc = 0;
		int j = root-> leaf_suf_number;
		while (j >= 0)
		{
			if (text[j] == '.')
			{
				loc = j;
				break;
			}
			j--;
		}
		printf("The string is there from %d\n", root-> leaf_suf_number);
		j = loc + 1;		
		while (j < strlen(text))
		{
			if (text[j] == '.')
				break;
			printf("%c", text[j]);
			j++;
		}
		printf("%c",text[j]);
		printf("\n\n");
	}
  
	for (int i = 0; i< 256; i++)
    		leaf(root->children[i],text,title);
}


			
//Function to return length of longest substring matched
int longest_match(char *pattern, struct Node * root, char *text, char *title)
{
	
	struct Node *temp = root;
	int matched = 0;
	int matched_after_moving = 0;
	int flag = 0;
	temp = temp->children[tolower(pattern[matched])];
	while (temp!= NULL && matched < strlen(pattern) )
	{
		int sub_len = (temp -> end) - (temp -> start) + 1;
		for (int i = 0; i< sub_len ; i++)
		{
			if (tolower(pattern[matched_after_moving + i]) == tolower(text[temp-> start + i]))
				matched++;	
			else
				break;
		}
		matched_after_moving =matched;
		if (matched == strlen(pattern))
		{
			leaf2(temp,text,title);
			flag = 1;
			return strlen(pattern);
		}
		temp = temp->children[pattern[matched]];
		if (temp == NULL && flag != 1)
			return 0;
			
	}
	
}	

//Find longest substring that matches by reducing one character at a time and find leftmost match
void caller_longest_match(char *pattern, struct Node * root, char *text, char *title)
{
	int length = 0;
	length = longest_match(pattern, root, text, title);
	if (length!= 0)
	{
		int m = min(arr, count_arr);
		printf("The string's leftmost is there from %d\n", m);
		printf("TITLE: %s\n", title);
		for (int i = m ; i< strlen(text) ; i++)
			printf("%c",text[i]);
		printf("\n\n");
		
	}
	else
	{
		int flag_done = 0;
		int j = 1;
		while ( j < strlen(pattern))
		{
			int i;
			char pattern_new[100];
			int target = strlen(pattern) - j; 
			for (i = 0; i< target ; i++)
				pattern_new[i] = pattern[i];
			pattern_new[i] = '\0';
 
			length = longest_match(pattern_new, root, text, title);
			if (length!= 0)
			{
				int m = min(arr, count_arr);
				printf("The substring %s leftmost match is there from %d\n", pattern_new, m);
				printf("TITLE: %s\n", title);
				for (int i = m ; i< strlen(text) ; i++)
					printf("%c",text[i]);
				printf("\n\n");
				flag_done = 1;
				break;
			}
			j++;
		}
		if (flag_done == 0)
		{
			printf("No substring matches here\n");
			printf("TITLE: %s\n", title);
		}
					
	}
}
			
//Add to an array which has all the substring start positions that matched for that substring
void leaf2(struct Node *root,char * text, char * title)
{
	if (!root)
		return;
 
    	if (root-> leaf_suf_number != -1)
   	{
		arr[count_arr] = root-> leaf_suf_number;
		count_arr++;
	}
  
	for (int i = 0; i< 256; i++)
    		leaf2(root->children[i],text,title);
}

//Find left most by finding miniimum in array created above 
int min(int * arr, int count_arr)
{
	int m = 9999;
	for (int i =0; i< count_arr; i++)
	{
		if(arr[i] < m)
			m = arr[i];
	}
	return m;
}

int evaluate(char *text, int word_count)
{
	int ratio;
	if (count_arr != 0)
	{
		ratio = strlen(text)/count_arr;
		printf("Len/ times %d\n", ratio);
	}
	else 
	{
		printf("Len/ times NOT APPLICABLE (no matches)\n");
		ratio = -1;
	}
	int sorted = ordered(arr_min, min_count);
	printf("min_count %d\n", min_count);
	printf("SORTED %d\n", sorted);

	//SCORING CRITERIA
	int score = 100;
	
	if (ratio == -1)
		score -= 30;
	else if (ratio >= 200)
		score -= 20;
	else if (ratio < 200 && ratio > 100)
		score -= 10;
	
	if (min_count != word_count)
		score-= 30;
	
	if (sorted == 0)
		score -= 30;

	printf("SCORE %d / 100\n", score);
	return score;
		 
}

//Used for part 3 
int ordered(int * arr, int count)
{
	int check_count = 0;
	for (int i = 0; i< count - 1; i++)
	{
		if (arr[i] < arr[i+1]) 
			check_count++;
	}
	if (check_count == count - 1)
		return 1;
	else
		return 0;
}


//Add to an array which has all the substring start positions that matched for that substring
void leaf3(struct Node *root,char * text, char * title)
{
	if (!root)
		return;
 
    	if (root-> leaf_suf_number != -1)
   	{
		arr[count_arr] = root-> leaf_suf_number;
		count_arr++;
		arr_ind[count_ind] = root-> leaf_suf_number;
		count_ind++;
	}
  
	for (int i = 0; i< 256; i++)
    		leaf3(root->children[i],text,title);
}

//Used for sorting by rank
void seq_sort(struct data *tales, int n)
{
	int i, j;
	struct data t;
	for (i = 0; i < n-1; i++)      
  		for (j = 0; j < n-i-1; j++) 
			if (tales[j].score > tales[j+1].score)
			{
		 		t = tales[j];
				tales[j] = tales[j+1];
				tales[j+1] = t;
			}
	display(tales, n);
}

void display(struct data *tales, int n)
{
	for (int i = 0; i < n; i++)
		printf("TITLE : %s, Rank: %d\n", tales[i].title, tales[i].score); 
}
	










