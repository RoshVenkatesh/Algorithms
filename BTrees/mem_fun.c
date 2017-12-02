#include"mem_header.h"

extern int globalcount;
extern struct node *root;

//Allocate contiguous memory for the tree
struct node * create() 
{
        struct node * newNode;
        newNode = (struct node *)malloc(sizeof(struct node)*150);
	for(int i=0; i<150;i++)
	{
		newNode[i].leaf = 1;
		newNode[i].count = 0;
		for (int j=0 ; j< (2*t) ;j++)
		{
			newNode[i].reference[j] = -1;
		}
			 
	}
        return newNode;
}

//If a node where insertion has to happen is full and a new node has to be formed
struct node *split(struct node *root, int curr)
{
	int i;
	int lval = globalcount +1;
	int rval = globalcount +2;
	struct node *temp = &root[curr];
	struct node *left = &root[lval];
	struct node *right = &root[rval];
	for (i=0; i< t-1; i++)
	{
		left->values[i] = temp->values[i];
		left->reference[i] = temp->reference[i];
		right->values[i] = temp->values[i+t];
		right->reference[i] = temp->reference[i+t];
	}
	left->reference[t-1] = temp->reference[t-1];
	right->reference[t-1] = temp->reference[(2*t)-1];

	if (left->reference[t-1] != -1)
		left->leaf = 0;

	if (right->reference[t-1] != -1)
		right->leaf = 0;

	left->count = t-1;
	right->count = t-1;
	temp->values[0] = temp->values[t-1];
	temp->reference[0] = lval;
	temp->reference[1] = rval; 
	temp->count = 1;

	globalcount+=2;	
	return temp;
	
}

//Once we finally narrow down which node the value goes into, the value is added in ascending order
void insert_final(struct node *root,int curr, struct data val)
{
	struct node *temp = &root[curr];
	int i = temp->count;
	int start = temp->count;
	if (val.index < temp->values[0].index)
		start = 0;
	
	else
	{
		while (i>0)
		{
			if( val.index > temp->values[i-1].index) 
			{
				start = i;
			
				break;
			}
			i--;
		}
	}

	for(i= temp->count-1; i>= start ; i--)
		temp->values[i+1] = temp->values[i];

	temp->values[start] = val;
	//temp->count++;
}

//If a node where insertion has to happen is full but there is a non full node in the above level that value can be pushed to
struct node *split_and_push(struct node *root,int curr,int prev)
{
	//Moving around and splitting curr
	int lval = globalcount+1;
	int rval = globalcount+2;
	struct node *parent = &root[prev];
	int i;
	int index_shift;
	struct node *temp = &root[curr];
	struct node *left = &root[lval];
	struct node *right = &root[rval];
	for (i=0; i< t-1; i++)
	{
		left->values[i] = temp->values[i];
		left->reference[i] = temp->reference[i];
		right->values[i] = temp->values[i+t];
		right->reference[i] = temp->reference[i+t];
	}
	left->count = t-1;
	right->count = t-1;
	left->reference[t-1] = temp->reference[t-1];
	right->reference[t-1] = temp->reference[(2*t)-1];

	if (left->reference[t-1] != -1)
		left->leaf = 0;

	if (right->reference[t-1] != -1)
		right->leaf = 0;

	
	//Insert median in parent
	struct data median = temp->values[t-1];

	if (median.index < parent->values[0].index)
		index_shift = 0;
	else if (median.index > parent->values[parent->count-1].index)
		index_shift = parent->count;
	else
	{
		for (i=0; i< parent->count -1  ; i++)
		{
			if (median.index > parent->values[i].index && median.index < parent->values[i+1].index)
			{
				index_shift = i+1;
				break;
			}
		}
	}

	//Fix node counts and references of parent
	for(i= parent->count-1; i>= index_shift ; i--)
		parent->values[i+1] = parent->values[i];

	for(i= parent->count; i>= index_shift ; i--)
		parent->reference[i+1] = parent->reference[i];

	parent->values[index_shift] = median;
	parent->reference[index_shift] = lval;
	parent->reference[index_shift+1] = rval;
	parent->count++;
	globalcount+=2;

	temp->count = 0;

	return parent;

}

//THIS IS THE BASE FUNCTION FOR CALLING INSERTION
void insert(struct node *root,int curr,int prev, struct data val)
{
	struct node *temp;
	temp = &root[curr];
	if (temp->count == ((2*t) - 1))
	{
		if (prev == -1)
		{
			//SPLIT THE NODE IF IT IS FULL and the parent is null
			temp->leaf = 0;
			temp = split(root,curr);
		}
		else
		{
			//Push up to parent if parent is not null
			temp = split_and_push(root,curr,prev);
		}
	}


	if (temp->leaf == 1)
	{
		//NORMAL INSERT INTO LEAF NODE
		insert_final(root,curr, val);
		temp->count++;
	}
		
	
	else
	{
		//RECURSE TO THE CORRECT CHILD
		int i = 0;
		int child;

		if (val.index < temp->values[0].index)
			child = 0;
		else if(val.index > temp->values[temp->count-1].index)
			child = temp->count;

		else
		{
			while (i< temp->count-1)
			{
				if( val.index > temp->values[i].index && val.index < temp->values[i+1].index ) 
				{
					child = i+1;
					break;
				}
				i++;
			}
		}
		prev = curr;
		int curef =temp->reference[child]; 
		temp = &root[curef];
		insert(root,curef, prev, val);
	}
}	

//DEALLOCATE MEMORY
void freefunction(struct node *root)
{
   free(root);
}

//BASE FUNCTION FOR SEARCHING
struct data search (struct node * root, int curr, long long int val)
{
	struct node * temp = &root[curr];
	while (temp->reference[0]!=-1)
	{
		int i = 0, flag = 0;
		int child;

		if (val < temp->values[0].index)
			child = 0;
		else if(val > temp->values[temp->count-1].index)
			child = temp->count;

		else
		{
			for (int j=0; j< temp->count; j++)
			{
				if( val == temp->values[j].index)
				{
					flag = 1;
					return (temp->values[j]);					
					
				} 
			}


			if (flag!= 1)
			{
				
				while (i< temp->count-1)
				{
				
					if( val > temp->values[i].index && val < temp->values[i+1].index ) 
					{
						child = i+1;
						break;
					}
					i++;
				}
			}
		}
		
		//curr = child;
		int curef =temp->reference[child];
		temp = &root[curef];
		if (temp->reference[0]==-1)
			break;
		search(temp,curef, val);
	
	}
	for (int j=0; j< temp->count; j++)
	{
		if( val == temp->values[j].index)
			return (temp->values[j]);					
		
	}
	
}

//Once we know which node has the element we call this function to delete the element 
void delete_final(struct node *root, int curr ,struct data val, int loc)
{
	struct node * child = &root[curr];
	//If value to be deleted is in a non minimal leaf node 
	if (child->leaf == 1 && child->count > (t-1))
	{
		child->values[loc].index = -1;
		for (int i = loc+1; i< child->count; i++)
		{
			child->values[i-1] = child->values[i];
		}
		for (int i = loc+1; i<= child->count; i++)
		{
			child->reference[i-1] = child->reference[i];
		}
		child->reference[child->count] = -1;
		child->count--;
	}
		
	//If value to be deleted is in an internal node
	else if(child -> leaf != 1)
	{
		int m;
		struct node *t1;
		struct node *t2;
		struct node *p1;
		t1 = &root[child->reference[loc]];
		t2 = &root[child->reference[loc+1]];

		//If the left child of the node where deletion has to happen can spare an element we replace with its predecessor
		if (t1->count > (t-1))
		{
			m = child->reference[loc];
			while (t1->leaf != 1)
			{
				p1 = t1;
				m = t1->reference[t1->count];
				t1 = &root[t1->reference[t1->count]];
			}
			struct data pred = t1->values[t1->count-1];
			delete_final(root,m,pred,t1->count-1);
			child->values[loc] = pred;
		}
		//If the right child of the node where deletion has to happen can spare an element we replace with its successor
		else if (t2->count > (t-1))
		{
			child->reference[loc+1];
			while (t2->leaf != 1)
			{
				p1 = t2;
				m = t2->reference[0];
				t2 = &root[t2->reference[0]];
			}
			struct data succ = t2->values[0];	
			delete_final(root,m,succ,0);
			child->values[loc] = succ;
		}
		//If both children of the node are at their minimum, children are merged and a value is moved down from parent
		else
		{
			t1->values[t-1] = child->values[loc];
			for (int i=0; i< t2->count; i++)
				t1->values[t+i] =t2->values[i];
			
			for (int i=0; i<= t2->count; i++)
				t1->reference[t+i] =t2->reference[i];
		
			for (int i =loc+1; i< child->count; i++)
				child->values[i-1] = child->values[i];

			for(int i= loc+2; i<= child->count; i++)
				child->reference[i-1] = child->reference[i];

			t1->count+= t2->count;
			t1->count+=1;
			child->reference[child->count] = -1;
			child->count--;				
			delete_final(root,child->reference[loc],t1->values[t-1],t-1);
		}
				
	}
}

//IN case 2 nodes have to be merged when we encounter a non leaf node that is at its min
struct node* merge(struct node * root, int curr, int prev)
{
	struct node *child = &root[curr];
	struct node *parent = &root[prev];
	int loc;
	//FInding the child that may contain the needed value
	for (int i=0; i<= parent->count; i++)
	{
		
		if(parent->reference[i] == curr)
		{
			loc = i;
			break;
		}
	}

		//If the node can be merged withits left sibling
		if(loc < parent->count && (root[parent->reference[loc+1]].count) > t-1)
		{
			
			struct node *t1 = &root[parent->reference[loc+1]];
			child->values[child->count] = parent->values[loc];
			child->count++;
			child->reference[child->count] = t1->reference[0];

			parent->values[loc] = t1->values[0];

			for(int i=1; i< t1->count; i++)
				t1->values[i-1] = t1->values[i];

			for(int i=1; i<= t1->count; i++)
				t1->reference[i-1] = t1->reference[i];

			t1->values[t1->count-1].index = -1;
			t1->reference[t1->count] = -1;

			t1->count--;
		}

		//If the node can be merged with its right sibling
		else if(loc > 0 && (root[parent->reference[loc-1]].count) > t-1)
		{
			struct node *t1 = &root[parent->reference[loc-1]];
			for(int i = child->count - 1; i>= 0; i--)
				child->values[i+1] = child->values[i];

			for(int i = child->count; i>= 0; i--)
				child->reference[i+1] = child->reference[i];
		
			child->count++;
			child->values[0] = parent->values[loc-1];
			child->reference[0] = t1->reference[t1->count];
			t1->reference[t1->count] = -1;
			parent->values[loc-1] = t1->values[t1->count-1]; 
		
			t1->values[t1->count-1].index = -1;
			t1->count--;
		
		}

		//If both left and right siblings are at min
		else
		{
			struct node *t1;
			if(loc == parent->count)
			{
				t1 = &root[parent->reference[loc-1]];
				struct node * temporary = child;
				child = t1;
				t1 = temporary;
			}
			else
			{
				t1 = &root[parent->reference[loc+1]];
			}	
			
			child->values[t-1] = parent->values[loc];

			int i;		
			for(i=0; i< t1->count; i++)
				child->values[t+i] = t1->values[i];
	
			for(i=0; i<= t1->count; i++)
				child->reference[t+i] = t1->reference[i];

			for(i=loc+1; i< parent->count; i++)
				parent->values[i] = parent->values[i+1];
		
			for(i=loc+1; i<= parent->count; i++)
				parent->reference[i] = parent->reference[i+1];

			parent->reference[parent->count] = -1;
			child->count = (2*t) - 1;
			parent->count--;
		}
	
	return child;

}			
				
//Base function for deletion
void delete_value (struct node * root, int curr, int prev, long long int val)
{
	struct node * temp = &root[curr];
	int flag = 0;
	if (temp->count == (t - 1) && curr!= 0)
	{
		temp = merge(root,curr,prev);
		if(temp->leaf == 1)
		{
			for (int j =0 ; j< temp->count; j++)
			{
				if (temp->values[j].index == val)
				{
					flag = 1;
					delete_final(root,curr,temp->values[j],j);
					break;
				}
			}
		}
	}
	
	if (flag == 0)
	{
		int flag = 0;
		for (int j =0 ; j< temp->count; j++)
		{
			if (temp->values[j].index == val)
			{
				flag = 1;
				delete_final(root,curr,temp->values[j],j);
			}
		}
		//RECURSE TO THE CORRECT CHILD

		if (flag==0 && temp->leaf ==1)
		{
			printf("NOT FOUND\n");
		}

		else if (flag ==0)
		{
			int i = 0;
			int child;

			if (val < temp->values[0].index)
				child = 0;
			else if(val > temp->values[temp->count-1].index)
				child = temp->count;

			else
			{
				while (i< temp -> count-1)
				{
					if( val > temp->values[i].index && val < temp->values[i+1].index ) 
					{
						child = i+1;
						break;
					}
					i++;
				}
			}
			prev = curr;
			int curef = temp->reference[child]; 
			temp = &root[curef];
			
			delete_value(root,curef, prev, val);
		}
	}
}
