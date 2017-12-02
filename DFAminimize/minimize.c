#include"minimize.h"
void minimize(int *fin)
{
	
//TAKING INPUT STARTS
	int i,j,s,t,e,lambda=0,n,states, inputs, initial,nfinal,p,count=0;	
	scanf("%d",&states);	 //Number of states
	scanf("%d",&inputs);	//Number of input symbols
	scanf("%d",&initial);	//Inital state number
	scanf("%d",&nfinal);	//Number of final states
	for (i=0; i< nfinal; i++)
		scanf("%d", &fin[i]);	//The state numbers of all final states
	
	int **arr=(int**)malloc(states*inputs*sizeof(int*));
	for(i=0;i<(states*inputs);i++)
	{
		arr[i]=(int*)malloc(3*sizeof(int));
	}
	int prodcount = 0;
	scanf("%d",&s);
	scanf("%d",&t);
	scanf("%d",&e);
	//Take input of production rule tables into arr 
	while(s>=0)
	{
		
		arr[prodcount][0] = s;
		arr[prodcount][1] = t;
		arr[prodcount][2] = e;
		s=-1;
		scanf("%d",&s);
		scanf("%d",&t);
		scanf("%d",&e);
		prodcount++;
	}

//TAKING INPUT ENDS

	//Create a unique alphabetical reference for each state
	struct dict * a ;
	a = (struct dict *)malloc(states * sizeof(struct dict));

	for (i=0; i<states; i++)
	{
			a[i].stateno = -1;
	}

	
	for(i=0; i<prodcount; i++)
	{
		for(j=0; j<states; j++)
		{
				if (arr[i][0] == a[j].stateno)
					break;				
				else
				{
					a[arr[i][0]].stateno = arr[i][0]; 
					a[arr[i][0]].stateid = 'A' + arr[i][0];
					break;
				}
		}
	}

	//Create permutations of 2 states at a time
	int sum = 0;
	for (i=1; i< states; i++)
		sum += i;

	struct table * b ;
	b = (struct table *)malloc(sum * sizeof(struct table));
	int table_index=0;
	for(i=0; i<states; i++)
	{
		//printf("\n%d %c", a[i].stateno, a[i].stateid);
		for (j=i+1; j<states; j++)
		{
			char combined[2];
			combined[0] = a[i].stateid;
			combined[1] = a[j].stateid;
			strcpy(b[table_index].permutation, combined);
			b[table_index].crossed = 0;
			table_index++; 
		}
		
	}
	
	//This function crosses out all pairs which are non-final and final states
	crossfnf(a,b,states,table_index,nfinal,fin);

	int change = 1;
	while (change == 1)
	{
	change = 0;
	//TRACK FOR CROSSING IMPOSSIBLE PAIRS
	int ipcount =0;
	//NEEDS TO CHECK PROD RULES FOR ALL INPUT SYMBOLS AND THEN CROSS OUT
	for (int ipcount = 0; ipcount <inputs; ipcount++)	
	{ 	
		for (i=0; i<table_index; i++)
		{
		//GET LETTERS OF THE CURRENT STATE IT IS AT
			int state1, state2;
			int final1, final2;
			char p1 = b[i].permutation[0];
			char p2 = b[i].permutation[1];
			char r1,r2;
			char q1, q2;
			//GET THE STATE NUMBER OF THOSE STATES
			for(j=0; j<states; j++)
			{
				if (p1 == a[j].stateid)
					state1 = a[j].stateno;
				else if (p2 == a[j].stateid)
					state2 = a[j].stateno;
			
			}
			//GET THE REACHING POINT OF THE PRODUCTION RULE CORRESPONDING TO GIVEN IP STATES AND SYBMBOLS
			for (int k = 0; k< prodcount; k++)
			{
				if (arr[k][0] == state1 && arr[k][1] == ipcount)
					 final1 = arr[k][2];
				if (arr[k][0] == state2 && arr[k][1] == ipcount)
					 final2 = arr[k][2];
			}
			//WE LAND UP WITH CASES WHERE THE REACHING STATES ARE IN DIFFERENT ORDER. EG. we get EB but only BE is there
			if (final1 > final2)
			{
				int t = final1;
				final1= final2;
				final2 =t;
			}
			//THIS IS TO SKIP THE 2 STATES WHICH END UP AT THE SAME REACHING STATE
			else if (final1 == final2)
				continue;

			//GET THE CORRESPONDING ALPHABETS FOR THE REACHING STATES
			for(j=0; j<states; j++)
			{
				if (final1 == a[j].stateno)
					q1 = a[j].stateid;
				else if (final2 == a[j].stateno)
					q2 = a[j].stateid;
			
			}
		
			//IF IT IS REACHING A COMBINATION OF STATES ALREADY CROSSED OUT THEN IT ALSO IS CROSSED OUT
			char combined[2];
			combined[0] = q1;
			combined[1] = q2;
		
			for(int l =0; l < table_index ; l++)
			{
				if (strcmp(combined, b[l].permutation)==0 && b[l].crossed == 1 && b[i].crossed == 0)
				{
					b[i].crossed = 1;
					change = 1;
					
				}
			}
	
		}
	}
	}

char list[table_index][3];	//STORE UNCROSSED SET OF 2 STATES
char combinedlist[100][states];
int clcount=0;
int c = 0;
//STORE UNCROSSED SET OF 2 STATES
	for(int l =0; l < table_index ; l++)
	{
		//printf("%s %d ", b[l].permutation, b[l].crossed);
		if (b[l].crossed == 0)
		{	
			//printf("%s ", b[l].permutation);
			strcpy(list[c++],b[l].permutation);
		}
	}

//STORE PERMUTATIONS OF ALL SETS OF STATES THAT CAN GO TOGETHER
for (int l=0;l<c; l++)
{
	char array[states];
	count =0;
	array[count++] = list[l][0];
	for (int k =l; k<c; k++)
	{
		if (list[l][0] == list[k][0] )
		{
			array[count++]	= list[k][1];
			//printf("%c", list[k][1]);
		}
		
	}
	array[count] = '\0';
	strcpy(combinedlist[clcount++],array);							
}

//STORE THE SINGLE LETTERS ALSO JUST IN CASE THEY AREN'T COMBINING WITH ANY OTHER STATES. THESE ARE NOT CONSIDERED PREVIOUSLY
for (i=0; i<states; i++)
{
	char array[2];
	array[0] = a[i].stateid;
	array[1]= '\0';
	strcpy(combinedlist[clcount++],array);
}

//NEXT 2 LOOPS FIND THOSE PERMUTATIONS THAT ARE NOT REDUNDANT.  eg. given ABC,AB,AC,BC,A,B,C. YOU need to keep only ABC
int visited[clcount];
//USING VISITED ARRAY REDUCES NUMBER OF COMPARISONS
for(i=0;i<clcount; i++)
{
	visited[i] = 0;
}	
int ans;
for(i=0;i<clcount; i++)
{
	for (j=i+1; j<clcount; j++)
	{
		if (visited[i]==0 && visited[j]==0)
		{
			ans = does_make(combinedlist[i], combinedlist[j]);
			if (ans ==1)
			{
				visited[j]=1;
				//printf(" %s %s", combinedlist[i], combinedlist[j]);
			}
		}
	}
}

int anscount=0;
int k;
char finalans[100][states];
//STORES NON REDUNDANT COMBINATIONS IN AN ARRAY finalans
for(i=0;i<clcount; i++)
{
	if (visited[i] == 0)
		strcpy(finalans[anscount++],combinedlist[i]);
}

int flag =0;

if (anscount == states)
	printf("CANNOT BE MINIMIZED\n");
//CONVERT TO STATE NUMBERS FROM LETTERS AND DISPLAY THEM. 
//IN CASE ONE OF THE STATES IS FINAL, THEN EVEN COMBINED STATE BECOMES FINAL. 
//THIS CONDITION OF BEING FINAL IS STORED IN flag=1 
// flag =0 if non-final
int answertable[anscount][3];
int combinedstates[anscount][10];
int memberofstate = 1; 
for (i=0; i<anscount; i++)
{	flag =0;
	memberofstate = 1; 
	combinedstates[i][0] = 0;
	//printf("%s ",finalans[i]);
	for (j=0; j<strlen(finalans[i]); j++)
	{
		for (k =0; k< table_index; k++)
		{
			if(finalans[i][j] == a[k].stateid)
			{
				if (a[k].stateno == 0)
					printf("THIS IS AN INITIAL STATE. ");
				printf("%d ,",a[k].stateno);
				combinedstates[i][memberofstate++] = a[k].stateno;
				combinedstates[i][0]++;
				for (int l=0; l<nfinal; l++)
				{
					if (a[k].stateno == fin[l])
						flag = 1;
				}
				
			}
		}
	}

//DESCTIPTIVE REPLY TO ANSWER
	
	if (strlen(finalans[i])==1)
		printf(" CAN BE KEPT AS ONE STATE as %d ",i);
	else
		printf(" CAN BE MERGED AS STATE %d ",i);
	if (flag == 1)
		printf("AND IS A FINAL STATE\n");
	else
		printf("AND IS NOT A FINAL STATE\n");
}	

printf("\n");

//MAKE PRODUCTION RULE TABLE FOR FINAL ANSWER 
int finalprodcount = 0;
for (i=0; i<anscount; i++)
{
	for(j=0; j<prodcount;j++)
	{
		if (arr[j][0] == combinedstates[i][1])
		{
			
			for (int k = 0; k< 3; k++)
			{
				answertable[finalprodcount][k] = arr[j][k];
			}
			++finalprodcount;
		}
	}
} 
printf("THE PRODUCTION RULES ARE:\n");

int check0 =0, check2 = 0;
i=0;
while (i<finalprodcount)
{
	for (j=0; j<anscount; j++) //total number of states that it is reduced to
	{
		for (int k=1; k<= combinedstates[j][0]; k++)
		{
			if (answertable[i][2] == combinedstates[j][k] && check2 == 0)
			{
				//printf("i= %d j = %d check0= %d check2 = %d\n",i,j,check0,check2);
				answertable[i][2] =  j;
				check2=1;				
			}
			if (answertable[i][0] == combinedstates[j][k] && check0== 0)
			{
				//printf("i= %d j = %d check0= %d check2 = %d\n",i,j,check0,check2);
				answertable[i][0] =  j;
				check0=1;
			}
					
		} 
		if (check2 == 1 && check0 == 1)
		{
			i++;
			j=0;
			check0=0;
			check2=0;
		}
			
	}
}

for (i=0; i< finalprodcount; i++)
{
	for (j=0; j< 3; j++)
		printf("%d ", answertable[i][j]);
	printf("\n");
}
free (arr);
free(a);
free(b);
}

int does_make(char* string1, char* string2)
{
	int fin_len,sec_len;
	int flag = 0;
	if(strlen(string1) < strlen(string2))
	{
        	return 0;
    	}
	else
	{
        	fin_len = strlen(string1);
        	sec_len = strlen(string2);
   	}
    	
	for(int i = 0; i < sec_len; i++)
	{
        	flag = 0;
        	for(int j=0; j< fin_len; j++)
		{
            		if(string2[i] == string1[j]) //If string 2 can be made from string 1
			{
                		flag = 1;
                		break;
            		}
			else
			{
                		flag = 0;
           		}
       		}
    	}
    return flag;
}

void crossfnf(struct dict *a, struct table *b, int states, int table_index, int nfinal,int *fin)
{
	int i,j	;
	printf("\n");
	//CROSS OUT FINAL NON FINAL PAIRS
	for (i=0; i<table_index; i++)
	{
		int state1, state2;
		//printf("\n%s %d", b[i].permutation, b[i].crossed);
		char p1 = b[i].permutation[0];
		char p2 = b[i].permutation[1];
		for(j=0; j<states; j++)
		{
			if (p1 == a[j].stateid)
				state1 = a[j].stateno;
			else if (p2 == a[j].stateid)
				state2 = a[j].stateno;
			
		}
		//printf("%d%d", state1,state2);
		if (nfinal == 1)
		{
			if (state1 == fin[0] || state2 == fin[0])
				b[i].crossed = 1;
		}
		else
		{
			int s=0,r=0;
			for(int k=0;k<nfinal;k++)
			{
				if(state1==fin[k])
					s=1;
				else if(state2==fin[k])
					r=1;
			}
			if((s==1 && r==0)||(s==0 && r==1))
				b[i].crossed=1;

		}
	}	
}
