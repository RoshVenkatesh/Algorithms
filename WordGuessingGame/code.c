#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>
struct tree
{
	char value;
	struct tree *zero, *one, *two, *three;
};
struct node 
{
	char s[10];
	int score;
	struct node *next;
};
struct node *res=NULL;

typedef struct tree T;
struct tree *r, *l2, *l3, *new;

struct tree *create_node()
{
	new = (T*)malloc(sizeof(T));
	new->zero = NULL;
	new->one = NULL;
	new->two = NULL;
	new->three = NULL;
	return new;
}

struct tree * make_tree_4()
{
	
	r = create_node();
	r -> value = '4';

	//LEVEL 1
	r -> zero = create_node();
	r -> zero -> value = 'H';
	r -> one = create_node();
	r -> one -> value = 'T';
	r -> two = create_node();
	r -> two -> value = 'M';
	r -> three = create_node();
	r -> three -> value = 'S';

	//LEVEL 2
	r-> zero -> zero = create_node();
	r-> zero -> zero-> value = 'E';
	r-> zero -> one = create_node();
	r-> zero -> one -> value = 'A';
	r-> zero -> two = create_node();
	r-> zero -> two -> value = 'O';
	r-> zero -> three = create_node();
	r-> zero -> three-> value = 'I';
	
	r-> one -> zero = create_node();
	r-> one -> zero-> value = 'E';
	r-> one -> one = create_node();
	r-> one -> one -> value = 'A';
	r-> one -> two = create_node();
	r-> one -> two -> value = 'O';
	r-> one -> three = create_node();
	r-> one -> three-> value = 'I';

	r-> two -> zero = create_node();
	r-> two -> zero-> value = 'E';
	r-> two -> one = create_node();
	r-> two -> one -> value = 'A';
	r-> two -> two = create_node();
	r-> two -> two -> value = 'O';
	r-> two -> three = create_node();
	r-> two -> three-> value = 'I';

	r-> three -> zero = create_node();
	r-> three -> zero-> value = 'E';
	r-> three -> one = create_node();
	r-> three -> one -> value = 'A';
	r-> three -> two = create_node();
	r-> three -> two -> value = 'O';
	r-> three -> three = create_node();
	r-> three -> three-> value = 'I';

	//LEVEL 3
	//Under HE
	r->zero->zero->zero = create_node();
	r->zero->zero->zero->value = 'L';
	r->zero->zero->one = create_node();
	r->zero->zero->one->value = 'R';
	r->zero->zero->two = create_node();
	r->zero->zero->two->value = 'E';
	//Under HA
	r->zero->one->zero = create_node();
	r->zero->one->zero->value = 'T';
	r->zero->one->one = create_node();
	r->zero->one->one->value = 'N';
	r->zero->one->two = create_node();
	r->zero->one->two->value = 'L';
	//Under HO
	r->zero->two->zero = create_node();
	r->zero->two->zero->value = 'L';
	r->zero->two->one = create_node();
	r->zero->two->one->value = 'O';
	r->zero->two->two = create_node();
	r->zero->two->two->value = 'P';
	//Under HI
	r->zero->three->zero = create_node();
	r->zero->three->zero->value = 'N';
	r->zero->three->one = create_node();
	r->zero->three->one->value = 'L';
	r->zero->three->two = create_node();
	r->zero->three->two->value = 'S';
	//Under TE
	r->one->zero->zero = create_node();
	r->one->zero->zero->value = 'A';
	r->one->zero->one = create_node();
	r->one->zero->one->value = 'L';
	r->one->zero->two = create_node();
	r->one->zero->two->value = 'E';
	//Under TA
	r->one->one->zero = create_node();
	r->one->one->zero->value = 'L';
	r->one->one->one = create_node();
	r->one->one->one->value = 'C';
	r->one->one->two = create_node();
	r->one->one->two->value = 'R';
	//Under TO
	r->one->two->zero = create_node();
	r->one->two->zero->value = 'O';
	r->one->two->one = create_node();
	r->one->two->one->value = 'R';
	r->one->two->two = create_node();
	r->one->two->two->value = 'L';
	//Under TI
	r->one->three->zero = create_node();
	r->one->three->zero->value = 'L';
	r->one->three->one = create_node();
	r->one->three->one->value = 'N';
	r->one->three->two = create_node();
	r->one->three->two->value = 'E'; 
	
	//Under ME
	r->two->zero->zero = create_node();
	r->two->zero->zero->value = 'A';
	r->two->zero->one = create_node();
	r->two->zero->one->value = 'E';
	r->two->zero->two = create_node();
	r->two->zero->two->value = 'N';	


	//Under MA
	r->two->one->zero = create_node();
	r->two->one->zero->value = 'T';
	r->two->one->one = create_node();
	r->two->one->one->value = 'R';
	r->two->one->two = create_node();
	r->two->one->two->value = 'L'; 	
	//Under MO
	r->two->two->zero = create_node();
	r->two->two->zero->value = 'L';
	r->two->two->one = create_node();
	r->two->two->one->value = 'O';
	r->two->two->two = create_node();
	r->two->two->two->value = 'W';
	//Under MI
	r->two->three->zero = create_node();
	r->two->three->zero->value = 'S';
	r->two->three->one = create_node();
	r->two->three->one->value = 'L';
	r->two->three->two = create_node();
	r->two->three->two->value = 'C'; 
	//Under SE
	r->three->zero->zero = create_node();
	r->three->zero->zero->value = 'N';
	r->three->zero->one = create_node();
	r->three->zero->one->value = 'L';
	r->three->zero->two = create_node();
	r->three->zero->two->value = 'E';
	//Under SA
	r->three->one->zero = create_node();
	r->three->one->zero->value = 'N';
	r->three->one->one = create_node();
	r->three->one->one->value = 'L';
	r->three->one->two = create_node();
	r->three->one->two->value = 'G';
	//Under SO
	r->three->two->zero = create_node();
	r->three->two->zero->value = 'A';
	r->three->two->one = create_node();
	r->three->two->one->value = 'L';
	r->three->two->two = create_node();
	r->three->two->two->value = 'R';
	//Under SI
	r->three->three->zero = create_node();
	r->three->three->zero->value = 'N';
	r->three->three->one = create_node();
	r->three->three->one->value = 'G';
	r->three->three->two = create_node();
	r->three->three->two->value = 'T';

	//LEVEL 4
	//UNder HEL
	r->zero->zero->zero->zero=create_node();
	r->zero->zero->zero->zero->value='P';
	r->zero->zero->zero->one=create_node();
	r->zero->zero->zero->one->value='D';
	//UNder HER
	r->zero->zero->one->zero=create_node();
	r->zero->zero->one->zero->value='B';
	r->zero->zero->one->one=create_node();
	r->zero->zero->one->one->value='E';
	//UNder HEE
	r->zero->zero->two->zero=create_node();
	r->zero->zero->two->zero->value='L';
	r->zero->zero->two->one=create_node();
	r->zero->zero->two->one->value='D';

	//UNder HAT
	r->zero->one->zero->zero=create_node();
	r->zero->one->zero->zero->value='S';
	r->zero->one->zero->one=create_node();
	r->zero->one->zero->one->value='E';
	//UNder HAN
	r->zero->one->one->zero=create_node();
	r->zero->one->one->zero->value='G';
	r->zero->one->one->one=create_node();
	r->zero->one->one->one->value='D';
	//UNder HAL
	r->zero->one->two->zero=create_node();
	r->zero->one->two->zero->value='T';
	r->zero->one->two->one=create_node();
	r->zero->one->two->one->value='L';

	//UNder HOL
	r->zero->two->zero->zero=create_node();
	r->zero->two->zero->zero->value='Y';
	r->zero->two->zero->one=create_node();
	r->zero->two->zero->one->value='D';
	//UNder HOO
	r->zero->two->one->zero=create_node();
	r->zero->two->one->zero->value='D';
	r->zero->two->one->one=create_node();
	r->zero->two->one->one->value='K';
	//UNder HOP
	r->zero->two->two->zero=create_node();
	r->zero->two->two->zero->value='S';
	r->zero->two->two->one=create_node();
	r->zero->two->two->one->value='E';

	//UNder HIN
	r->zero->three->zero->zero=create_node();
	r->zero->three->zero->zero->value='T';
	r->zero->three->zero->one=create_node();
	r->zero->three->zero->one->value='D';
	//UNder HIL
	r->zero->three->one->zero=create_node();
	r->zero->three->one->zero->value='L';
	r->zero->three->one->one=create_node();
	r->zero->three->one->one->value='T';
	//UNder HIS
	r->zero->three->two->zero=create_node();
	r->zero->three->two->zero->value='S';
	r->zero->three->two->one=create_node();
	r->zero->three->two->one->value='T';


	//UNder TEA
	r->one->zero->zero->zero=create_node();
	r->one->zero->zero->zero->value='M';
	r->one->zero->zero->one=create_node();
	r->one->zero->zero->one->value='L';
	//UNder TEL
	r->one->zero->one->zero=create_node();
	r->one->zero->one->zero->value='L';
	r->one->zero->one->one=create_node();
	r->one->zero->one->one->value='S';
	//UNder TEE
	r->one->zero->two->zero=create_node();
	r->one->zero->two->zero->value='S';
	r->one->zero->two->one=create_node();
	r->one->zero->two->one->value='N';

	//UNder TAL
	r->one->one->zero->zero=create_node();
	r->one->one->zero->zero->value='E';
	r->one->one->zero->one=create_node();
	r->one->one->zero->one->value='C';
	//UNder TAC
	r->one->one->one->zero=create_node();
	r->one->one->one->zero->value='K';
	r->one->one->one->one=create_node();
	r->one->one->one->one->value='T';
	//UNder TAR
	r->one->one->two->zero=create_node();
	r->one->one->two->zero->value='T';
	r->one->one->two->one=create_node();
	r->one->one->two->one->value='E';

	//UNder TOO
	r->one->two->zero->zero=create_node();
	r->one->two->zero->zero->value='M';
	r->one->two->zero->one=create_node();
	r->one->two->zero->one->value='N';
	//UNder TOR
	r->one->two->one->zero=create_node();
	r->one->two->one->zero->value='E';
	r->one->two->one->one=create_node();
	r->one->two->one->one->value='N';
	//UNder TOL
	r->one->two->two->zero=create_node();
	r->one->two->two->zero->value='L';
	r->one->two->two->one=create_node();
	r->one->two->two->one->value='D';

	//UNder TIL
	r->one->three->zero->zero=create_node();
	r->one->three->zero->zero->value='T';
	r->one->three->zero->one=create_node();
	r->one->three->zero->one->value='L';
	//UNder TIN
	r->one->three->one->zero=create_node();
	r->one->three->one->zero->value='S';
	r->one->three->one->one=create_node();
	r->one->three->one->one->value='T';
	//UNder TIE
	r->one->three->two->zero=create_node();
	r->one->three->two->zero->value='S';
	r->one->three->two->one=create_node();
	r->one->three->two->one->value='R';

	
	//UNder MEA
	r->two->zero->zero->zero=create_node();
	r->two->zero->zero->zero->value='T';
	r->two->zero->zero->one=create_node();
	r->two->zero->zero->one->value='L';
	//UNder MEE
	r->two->zero->one->zero=create_node();
	r->two->zero->one->zero->value='T';
	r->two->zero->one->one=create_node();
	r->two->zero->one->one->value='K';
	//UNder MEN
	r->two->zero->two->zero=create_node();
	r->two->zero->two->zero->value='D';
	r->two->zero->two->one=create_node();
	r->two->zero->two->one->value='U';

	//UNder MAT
	r->two->one->zero->zero=create_node();
	r->two->one->zero->zero->value='E';
	r->two->one->zero->one=create_node();
	r->two->one->zero->one->value='S';
	//UNder MAR
	r->two->one->one->zero=create_node();
	r->two->one->one->zero->value='S';
	r->two->one->one->one=create_node();
	r->two->one->one->one->value='T';
	//UNder MAL
	r->two->one->two->zero=create_node();
	r->two->one->two->zero->value='L';
	r->two->one->two->one=create_node();
	r->two->one->two->one->value='E'; 

	//UNder MOL
	r->two->two->zero->zero=create_node();
	r->two->two->zero->zero->value='E';
	r->two->two->zero->one=create_node();
	r->two->two->zero->one->value='D';
	//UNder MOO
	r->two->two->one->zero=create_node();
	r->two->two->one->zero->value='N';
	r->two->two->one->one=create_node();
	r->two->two->one->one->value='S';
	//UNder MOW
	r->two->two->two->zero=create_node();
	r->two->two->two->zero->value='N';
	r->two->two->two->one=create_node();
	r->two->two->two->one->value='S';

	//UNder MIS
	r->two->three->zero->zero=create_node();
	r->two->three->zero->zero->value='S';
	r->two->three->zero->one=create_node();
	r->two->three->zero->one->value='T';
	//UNder MIL
	r->two->three->one->zero=create_node();
	r->two->three->one->zero->value='L';
	r->two->three->one->one=create_node();
	r->two->three->one->one->value='K';
	//UNder MIC
	r->two->three->two->zero=create_node();
	r->two->three->two->zero->value='A';
	r->two->three->two->one=create_node();
	r->two->three->two->one->value='E';
	

	//UNder SEN
	r->three->zero->zero->zero=create_node();
	r->three->zero->zero->zero->value='T';
	r->three->zero->zero->one=create_node();
	r->three->zero->zero->one->value='D';
	//UNder SEL
	r->three->zero->one->zero=create_node();
	r->three->zero->one->zero->value='F';
	r->three->zero->one->one=create_node();
	r->three->zero->one->one->value='L';
	//UNder SEE
	r->three->zero->two->zero=create_node();
	r->three->zero->two->zero->value='S';
	r->three->zero->two->one=create_node();
	r->three->zero->two->one->value='N';

	//UNder SAN
	r->three->one->zero->zero=create_node();
	r->three->one->zero->zero->value='G';
	r->three->one->zero->one=create_node();
	r->three->one->zero->one->value='E';
	//UNder SAL
	r->three->one->one->zero=create_node();
	r->three->one->one->zero->value='T';
	r->three->one->one->one=create_node();
	r->three->one->one->one->value='E';
	//UNder SAG
	r->three->one->two->zero=create_node();
	r->three->one->two->zero->value='A';
	r->three->one->two->one=create_node();
	r->three->one->two->one->value='E';

	//UNder SOA
	r->three->two->zero->zero=create_node();
	r->three->two->zero->zero->value='R';
	r->three->two->zero->one=create_node();
	r->three->two->zero->one->value='P';
	//UNder SOL
	r->three->two->one->zero=create_node();
	r->three->two->one->zero->value='E';
	r->three->two->one->one=create_node();
	r->three->two->one->one->value='O';
	//UNder SOR
	r->three->two->two->zero=create_node();
	r->three->two->two->zero->value='E';
	r->three->two->two->one=create_node();
	r->three->two->two->one->value='T';

	//UNder SIN
	r->three->three->zero->zero=create_node();
	r->three->three->zero->zero->value='K';
	r->three->three->zero->one=create_node();
	r->three->three->zero->one->value='G';
	//UNder SIG
	r->three->three->one->zero=create_node();
	r->three->three->one->zero->value='N';
	r->three->three->one->one=create_node();
	r->three->three->one->one->value='H';
	//UNder SIT
	r->three->three->two->zero=create_node();
	r->three->three->two->zero->value='S';
	r->three->three->two->one=create_node();
	r->three->three->two->one->value='E'; 	
	return r;
}

struct tree *make_tree_5()
{
	r = create_node();
	r -> value = '5';

	//LEVEL 1
	r -> zero = create_node();
	r -> zero -> value = 'A';
	r -> one = create_node();
	r -> one -> value = 'D';
	r -> two = create_node();
	r -> two -> value = 'S';
	r -> three = create_node();
	r -> three -> value = 'P';

	//LEVEL 2
	r-> zero -> zero = create_node();
	r-> zero -> zero-> value = 'U';
	r-> zero -> one = create_node();
	r-> zero -> one -> value = 'L';
	r-> zero -> two = create_node();
	r-> zero -> two -> value = 'S';
	r-> zero -> three = create_node();
	r-> zero -> three-> value = 'D';
	
	r-> one -> zero = create_node();
	r-> one -> zero-> value = 'O';
	r-> one -> one = create_node();
	r-> one -> one -> value = 'R';
	r-> one -> two = create_node();
	r-> one -> two -> value = 'E';
	r-> one -> three = create_node();
	r-> one -> three-> value = 'I';

	r-> two -> zero = create_node();
	r-> two -> zero-> value = 'C';
	r-> two -> one = create_node();
	r-> two -> one -> value = 'H';
	r-> two -> two = create_node();
	r-> two -> two -> value = 'N';
	r-> two -> three = create_node();
	r-> two -> three-> value = 'O';

	r-> three -> zero = create_node();
	r-> three -> zero-> value = 'A';
	r-> three -> one = create_node();
	r-> three -> one -> value = 'L';
	r-> three -> two = create_node();
	r-> three -> two -> value = 'R';
	r-> three -> three = create_node();
	r-> three -> three-> value = 'U';

	//LEVEL 3
	//Under AU
	r->zero->zero->zero = create_node();
	r->zero->zero->zero->value = 'D';
	r->zero->zero->zero->zero = create_node();
	r->zero->zero->zero->zero->value = 'I';
	r->zero->zero->one = create_node();
	r->zero->zero->one->value = 'N';
	r->zero->zero->one->zero = create_node();
	r->zero->zero->one->zero->value = 'T';
	r->zero->zero->two = create_node();
	r->zero->zero->two->value = 'R';
	r->zero->zero->two->zero = create_node();
	r->zero->zero->two->zero->value = 'A';
	//Under AL
	r->zero->one->zero = create_node();
	r->zero->one->zero->value = 'O';
	r->zero->one->zero->zero = create_node();
	r->zero->one->zero->zero->value = 'N';
	r->zero->one->one = create_node();
	r->zero->one->one->value = 'K';
	r->zero->one->one->zero = create_node();
	r->zero->one->one->zero->value = 'Y';
	r->zero->one->two = create_node();
	r->zero->one->two->value = 'G';
	r->zero->one->two->zero = create_node();
	r->zero->one->two->zero->value = 'A';
	//Under AS
	r->zero->two->zero = create_node();
	r->zero->two->zero->value = 'S';
	r->zero->two->zero->zero = create_node();
	r->zero->two->zero->zero->value = 'E';
	r->zero->two->one = create_node();
	r->zero->two->one->value = 'P';
	r->zero->two->one->zero = create_node();
	r->zero->two->one->zero->value = 'E';
	r->zero->two->two = create_node();
	r->zero->two->two->value = 'H';
	r->zero->two->two->zero = create_node();
	r->zero->two->two->zero->value = 'E';
	//Under AD
	r->zero->three->zero = create_node();
	r->zero->three->zero->value = 'A';
	r->zero->three->zero->zero = create_node();
	r->zero->three->zero->zero->value = 'P';
	r->zero->three->one = create_node();
	r->zero->three->one->value = 'O';
	r->zero->three->one->zero = create_node();
	r->zero->three->one->zero->value = 'R';
	r->zero->three->two = create_node();
	r->zero->three->two->value = 'M';
	r->zero->three->two->zero = create_node();
	r->zero->three->two->zero->value = 'I';
	//Under DO
	r->one->zero->zero = create_node();
	r->one->zero->zero->value = 'R';
	r->one->zero->zero->zero = create_node();
	r->one->zero->zero->zero->value = 'K';
	r->one->zero->one = create_node();
	r->one->zero->one->value = 'P';
	r->one->zero->one->zero = create_node();
	r->one->zero->one->zero->value = 'E';
	r->one->zero->two = create_node();
	r->one->zero->two->value = 'T';
	r->one->zero->two->zero = create_node();
	r->one->zero->two->zero->value = 'E';
	//Under DR
	r->one->one->zero = create_node();
	r->one->one->zero->value = 'E';
	r->one->one->zero->zero = create_node();
	r->one->one->zero->zero->value = 'A';
	r->one->one->one = create_node();
	r->one->one->one->value = 'I';
	r->one->one->one->zero = create_node();
	r->one->one->one->zero->value = 'E';
	r->one->one->two = create_node();
	r->one->one->two->value = 'O';
	r->one->one->two->zero = create_node();
	r->one->one->two->zero->value = 'O';
	//Under DE
	r->one->two->zero = create_node();
	r->one->two->zero->value = 'M';
	r->one->two->zero->zero = create_node();
	r->one->two->zero->zero->value = 'O';
	r->one->two->one = create_node();
	r->one->two->one->value = 'A';
	r->one->two->one->zero = create_node();
	r->one->two->one->zero->value = 'L';
	r->one->two->two = create_node();
	r->one->two->two->value = 'C';
	r->one->two->two->zero = create_node();
	r->one->two->two->zero->value = 'A';
	//Under DI
	r->one->three->zero = create_node();
	r->one->three->zero->value = 'N';
	r->one->three->zero->zero = create_node();
	r->one->three->zero->zero->value = 'E';
	r->one->three->one = create_node();
	r->one->three->one->value = 'C';
	r->one->three->one->zero = create_node();
	r->one->three->one->zero->value = 'E';
	r->one->three->two = create_node();
	r->one->three->two->value = 'M'; 
	r->one->three->two->zero = create_node();
	r->one->three->two->zero->value = 'E';
	
	//Under SC
	r->two->zero->zero = create_node();
	r->two->zero->zero->value = 'O';
	r->two->zero->zero->zero = create_node();
	r->two->zero->zero->zero->value = 'O';
	r->two->zero->one = create_node();
	r->two->zero->one->value = 'E';
	r->two->zero->one->zero = create_node();
	r->two->zero->one->zero->value = 'N';
	r->two->zero->two = create_node();
	r->two->zero->two->value = 'R';	
	r->two->zero->two->zero = create_node();
	r->two->zero->two->zero->value = 'A';
	//Under SH
	r->two->one->zero = create_node();
	r->two->one->zero->value = 'E';
	r->two->one->zero->zero = create_node();
	r->two->one->zero->zero->value = 'E';
	r->two->one->one = create_node();
	r->two->one->one->value = 'O';
	r->two->one->one->zero = create_node();
	r->two->one->one->zero->value = 'R';
	r->two->one->two = create_node();
	r->two->one->two->value = 'U';	
	r->two->one->two->zero = create_node();
	r->two->one->two->zero->value = 'N';
	//Under SN
	r->two->two->zero = create_node();
	r->two->two->zero->value = 'O';
	r->two->two->zero->zero = create_node();
	r->two->two->zero->zero->value = 'R';
	r->two->two->one = create_node();
	r->two->two->one->value = 'A';
	r->two->two->one->zero = create_node();
	r->two->two->one->zero->value = 'K';
	r->two->two->two = create_node();
	r->two->two->two->value = 'I';
	r->two->two->two->zero = create_node();
	r->two->two->two->zero->value = 'P';
	//Under SO
	r->two->three->zero = create_node();
	r->two->three->zero->value = 'L';
	r->two->three->zero->zero = create_node();
	r->two->three->zero->zero->value = 'E';
	r->two->three->one = create_node();
	r->two->three->one->value = 'A';
	r->two->three->one->zero = create_node();
	r->two->three->one->zero->value = 'P';
	r->two->three->two = create_node();
	r->two->three->two->value = 'L'; 
	r->two->three->two->zero = create_node();
	r->two->three->two->zero->value = 'A';
	
	//Under PA
	r->three->zero->zero = create_node();
	r->three->zero->zero->value = 'C';
	r->three->zero->zero->zero = create_node();
	r->three->zero->zero->zero->value = 'E';
	r->three->zero->one = create_node();
	r->three->zero->one->value = 'I';
	r->three->zero->one->zero = create_node();
	r->three->zero->one->zero->value = 'N';
	r->three->zero->two = create_node();
	r->three->zero->two->value = 'L';
	r->three->zero->two->zero = create_node();
	r->three->zero->two->zero->value = 'M';
	//Under PL
	r->three->one->zero = create_node();
	r->three->one->zero->value = 'I';
	r->three->one->zero->zero = create_node();
	r->three->one->zero->zero->value = 'E';
	r->three->one->one = create_node();
	r->three->one->one->value = 'A';
	r->three->one->one->zero = create_node();
	r->three->one->one->zero->value = 'N';
	r->three->one->two = create_node();
	r->three->one->two->value = 'E';
	r->three->one->two->zero = create_node();
	r->three->one->two->zero->value = 'A';
	//Under PR
	r->three->two->zero = create_node();
	r->three->two->zero->value = 'I';
	r->three->two->zero->zero = create_node();
	r->three->two->zero->zero->value = 'C';
	r->three->two->one = create_node();
	r->three->two->one->value = 'O';
	r->three->two->one->zero = create_node();
	r->three->two->one->zero->value = 'N';
	r->three->two->two = create_node();
	r->three->two->two->value = 'A';
	r->three->two->two->zero = create_node();
	r->three->two->two->zero->value = 'N';
	//Under PU
	r->three->three->zero = create_node();
	r->three->three->zero->value = 'N';
	r->three->three->zero->zero = create_node();
	r->three->three->zero->zero->value = 'K';
	r->three->three->one = create_node();
	r->three->three->one->value = 'L';
	r->three->three->one->zero = create_node();
	r->three->three->one->zero->value = 'P';
	r->three->three->two = create_node();
	r->three->three->two->value = 'R';
	r->three->three->two->zero = create_node();
	r->three->three->two->zero->value = 'E';

	//LEVEL 5
	//UNDER AUDI
	r->zero->zero->zero->zero->zero = create_node();
	r->zero->zero->zero->zero->zero->value = 'T';
	r->zero->zero->zero->zero->one = create_node();
	r->zero->zero->zero->zero->one->value = 'O';
	//UNDER AUNT
	r->zero->zero->one->zero->zero = create_node();
	r->zero->zero->one->zero->zero->value = 'S';
	r->zero->zero->one->zero->one = create_node();
	r->zero->zero->one->zero->one->value = 'Y';
	//UNDER AURA
	r->zero->zero->two->zero->zero = create_node();
	r->zero->zero->two->zero->zero->value = 'S';
	r->zero->zero->two->zero->one = create_node();
	r->zero->zero->two->zero->one->value = 'L';
	//UNDER ALON
	r->zero->one->zero->zero->zero = create_node();
	r->zero->one->zero->zero->zero->value = 'G';
	r->zero->one->zero->zero->one = create_node();
	r->zero->one->zero->zero->one->value = 'E';
	//UNDER ALKY
	r->zero->one->one->zero->zero = create_node();
	r->zero->one->one->zero->zero->value = 'L';
	r->zero->one->one->zero->one = create_node();
	r->zero->one->one->zero->one->value = 'D';
	//UNDER ALGA
	r->zero->one->two->zero->zero = create_node();
	r->zero->one->two->zero->zero->value = 'E';
	r->zero->one->two->zero->one = create_node();
	r->zero->one->two->zero->one->value = 'L';
	//UNDER ASSE
	r->zero->two->zero->zero->zero = create_node();
	r->zero->two->zero->zero->zero->value = 'S';
	r->zero->two->zero->zero->one = create_node();
	r->zero->two->zero->zero->one->value = 'T';
	//UNDER ASPE
	r->zero->two->one->zero->zero = create_node();
	r->zero->two->one->zero->zero->value = 'N';
	r->zero->two->one->zero->one = create_node();
	r->zero->two->one->zero->one->value = 'R';
	//UNDER ASHE
	r->zero->two->two->zero->zero = create_node();
	r->zero->two->two->zero->zero->value = 'S';
	r->zero->two->two->zero->one = create_node();
	r->zero->two->two->zero->one->value = 'N';
	//UNDER ADAP
	r->zero->three->zero->zero->zero = create_node();
	r->zero->three->zero->zero->zero->value = 'A';
	r->zero->three->zero->zero->one = create_node();
	r->zero->three->zero->zero->one->value = 'T';
	//UNDER ADOR
	r->zero->three->one->zero->zero = create_node();
	r->zero->three->one->zero->zero->value = 'E';
	r->zero->three->one->zero->one = create_node();
	r->zero->three->one->zero->one->value = 'N';
	//UNDER ADMI
	r->zero->three->two->zero->zero = create_node();
	r->zero->three->two->zero->zero->value = 'N';
	r->zero->three->two->zero->one = create_node();
	r->zero->three->two->zero->one->value = 'T';
	//UNDER DORK
	r->one->zero->zero->zero->zero = create_node();
	r->one->zero->zero->zero->zero->value = 'S';
	r->one->zero->zero->zero->one = create_node();
	r->one->zero->zero->zero->one->value = 'Y';
	//UNDER DOPE
	r->one->zero->one->zero->zero = create_node();
	r->one->zero->one->zero->zero->value = 'S';
	r->one->zero->one->zero->one = create_node();
	r->one->zero->one->zero->one->value = 'D';
	//UNDER DOTE
	r->one->zero->two->zero->zero = create_node();
	r->one->zero->two->zero->zero->value = 'D';
	r->one->zero->two->zero->one = create_node();
	r->one->zero->two->zero->one->value = 'S';
	//UNDER DREA
	r->one->one->zero->zero->zero = create_node();
	r->one->one->zero->zero->zero->value = 'D';
	r->one->one->zero->zero->one = create_node();
	r->one->one->zero->zero->one->value = 'M';
	//UNDER DRIE
	r->one->one->one->zero->zero = create_node();
	r->one->one->one->zero->zero->value = 'S';
	r->one->one->one->zero->one = create_node();
	r->one->one->one->zero->one->value = 'R';
	//UNDER DROO
	r->one->one->two->zero->zero = create_node();
	r->one->one->two->zero->zero->value = 'P';
	r->one->one->two->zero->one = create_node();
	r->one->one->two->zero->one->value = 'L';
	//UNDER DEMO
	r->one->two->zero->zero->zero = create_node();
	r->one->two->zero->zero->zero->value = 'N';
	r->one->two->zero->zero->one = create_node();
	r->one->two->zero->zero->one->value = 'S';
	//UNDER DEAL
	r->one->two->one->zero->zero = create_node();
	r->one->two->one->zero->zero->value = 'S';
	r->one->two->one->zero->one = create_node();
	r->one->two->one->zero->one->value = 'T';
	//UNDER DECA
	r->one->two->two->zero->zero = create_node();
	r->one->two->two->zero->zero->value = 'F';
	r->one->two->two->zero->one = create_node();
	r->one->two->two->zero->one->value = 'Y';
	//UNDER DINE
	r->one->three->zero->zero->zero = create_node();
	r->one->three->zero->zero->zero->value = 'D';
	r->one->three->zero->zero->one = create_node();
	r->one->three->zero->zero->one->value = 'R';
	//UNDER DICE
	r->one->three->one->zero->zero = create_node();
	r->one->three->one->zero->zero->value = 'S';
	r->one->three->one->zero->one = create_node();
	r->one->three->one->zero->one->value = 'D';
	//UNDER DIME
	r->one->three->two->zero->zero = create_node();
	r->one->three->two->zero->zero->value = 'R';
	r->one->three->two->zero->one = create_node();
	r->one->three->two->zero->one->value = 'S';

	//UNDER SCOO
	r->two->zero->zero->zero->zero = create_node();
	r->two->zero->zero->zero->zero->value = 'T';
	r->two->zero->zero->zero->one = create_node();
	r->two->zero->zero->zero->one->value = 'P';
	//UNDER SCEN
	r->two->zero->one->zero->zero = create_node();
	r->two->zero->one->zero->zero->value = 'T';
	r->two->zero->one->zero->one = create_node();
	r->two->zero->one->zero->one->value = 'E';
	//UNDER SCRA
	r->two->zero->two->zero->zero = create_node();
	r->two->zero->two->zero->zero->value = 'M';
	r->two->zero->two->zero->one = create_node();
	r->two->zero->two->zero->one->value = 'T';
	//UNDER SHEE
	r->two->one->zero->zero->zero = create_node();
	r->two->one->zero->zero->zero->value = 'P';
	r->two->one->zero->zero->one = create_node();
	r->two->one->zero->zero->one->value = 'N';
	//UNDER SHOR
	r->two->one->one->zero->zero = create_node();
	r->two->one->one->zero->zero->value = 'E';
	r->two->one->one->zero->one = create_node();
	r->two->one->one->zero->one->value = 'T';
	//UNDER SHUN
	r->two->one->two->zero->zero = create_node();
	r->two->one->two->zero->zero->value = 'S';
	r->two->one->two->zero->one = create_node();
	r->two->one->two->zero->one->value = 'T';
	//UNDER SNOR
	r->two->two->zero->zero->zero = create_node();
	r->two->two->zero->zero->zero->value = 'E';
	r->two->two->zero->zero->one = create_node();
	r->two->two->zero->zero->one->value = 'T';
	//UNDER SNAK
	r->two->two->one->zero->zero = create_node();
	r->two->two->one->zero->zero->value = 'Y';
	r->two->two->one->zero->one = create_node();
	r->two->two->one->zero->one->value = 'E';
	//UNDER SNIP
	r->two->two->two->zero->zero = create_node();
	r->two->two->two->zero->zero->value = 'S';
	r->two->two->two->zero->one = create_node();
	r->two->two->two->zero->one->value = 'Y';
	//UNDER SOLE
	r->two->three->zero->zero->zero = create_node();
	r->two->three->zero->zero->zero->value = 'S';
	r->two->three->zero->zero->one = create_node();
	r->two->three->zero->zero->one->value = 'D';
	//UNDER SOAP
	r->two->three->one->zero->zero = create_node();
	r->two->three->one->zero->zero->value = 'S';
	r->two->three->one->zero->one = create_node();
	r->two->three->one->zero->one->value = 'Y';
	//UNDER SOLA
	r->two->three->two->zero->zero = create_node();
	r->two->three->two->zero->zero->value = 'N';
	r->two->three->two->zero->one = create_node();
	r->two->three->two->zero->one->value = 'R';

	//UNDER PACE
	r->three->zero->zero->zero->zero = create_node();
	r->three->zero->zero->zero->zero->value = 'D';
	r->three->zero->zero->zero->one = create_node();
	r->three->zero->zero->zero->one->value = 'R';
	//UNDER PAIN 
	r->three->zero->one->zero->zero = create_node();
	r->three->zero->one->zero->zero->value = 'S';
	r->three->zero->one->zero->one = create_node();
	r->three->zero->one->zero->one->value = 'T';
	//UNDER PALM
	r->three->zero->two->zero->zero = create_node();
	r->three->zero->two->zero->zero->value = 'S';
	r->three->zero->two->zero->one = create_node();
	r->three->zero->two->zero->one->value = 'Y';
	//UNDER PLIE
	r->three->one->zero->zero->zero = create_node();
	r->three->one->zero->zero->zero->value = 'D';
	r->three->one->zero->zero->one = create_node();
	r->three->one->zero->zero->one->value = 'R';
	//UNDER PLAN
	r->three->one->one->zero->zero = create_node();
	r->three->one->one->zero->zero->value = 'T';
	r->three->one->one->zero->one = create_node();
	r->three->one->one->zero->one->value = 'S';
	//UNDER PLEA
	r->three->one->two->zero->zero = create_node();
	r->three->one->two->zero->zero->value = 'T';
	r->three->one->two->zero->one = create_node();
	r->three->one->two->zero->one->value = 'D';
	//UNDER PRIC
	r->three->two->zero->zero->zero = create_node();
	r->three->two->zero->zero->zero->value = 'E';
	r->three->two->zero->zero->one = create_node();
	r->three->two->zero->zero->one->value = 'K';
	//UNDER PRON
	r->three->two->one->zero->zero = create_node();
	r->three->two->one->zero->zero->value = 'E';
	r->three->two->one->zero->one = create_node();
	r->three->two->one->zero->one->value = 'G';
	//UNDER PRAN
	r->three->two->two->zero->zero = create_node();
	r->three->two->two->zero->zero->value = 'G';
	r->three->two->two->zero->one = create_node();
	r->three->two->two->zero->one->value = 'K';
	//UNDER PUNK
	r->three->three->zero->zero->zero = create_node();
	r->three->three->zero->zero->zero->value = 'S';
	r->three->three->zero->zero->one = create_node();
	r->three->three->zero->zero->one->value = 'Y';
	//UNDER PULP
	r->three->three->one->zero->zero = create_node();
	r->three->three->one->zero->zero->value = 'S';
	r->three->three->one->zero->one = create_node();
	r->three->three->one->zero->one->value = 'Y';
	//UNDER PURE
	r->three->three->two->zero->zero = create_node();
	r->three->three->two->zero->zero->value = 'E';
	r->three->three->two->zero->one = create_node();
	r->three->three->two->zero->one->value = 'R';
	return r;
	
}

struct tree * make_tree_6()
{
	r = create_node();
	r -> value = '6';

	//LEVEL 1
	r -> zero = create_node();
	r -> zero -> value = 'S';
	r -> one = create_node();
	r -> one -> value = 'A';
	
	//LEVEL 2
	r-> zero -> zero = create_node();
	r-> zero -> zero-> value = 'H';
	r-> zero -> one = create_node();
	r-> zero -> one -> value = 'P';
	r-> zero -> two = create_node();
	r-> zero -> two -> value = 'T';
	r-> zero -> three = create_node();
	r-> zero -> three-> value = 'E';
	
	r-> one -> zero = create_node();
	r-> one -> zero-> value = 'L';
	r-> one -> one = create_node();
	r-> one -> one -> value = 'R';
	r-> one -> two = create_node();
	r-> one -> two -> value = 'T';
	r-> one -> three = create_node();
	r-> one -> three-> value = 'S';

	//LEVEL 3
	r-> zero -> zero -> zero = create_node();
	r-> zero -> zero-> zero-> value = 'A';
	r-> zero -> zero -> one = create_node();
	r-> zero -> zero-> one-> value = 'O';
	r-> zero -> one -> zero = create_node();
	r-> zero -> one-> zero-> value = 'A';
	r-> zero -> one -> one = create_node();
	r-> zero -> one-> one-> value = 'E';
	r-> zero -> two -> zero = create_node();
	r-> zero -> two-> zero-> value = 'A';
	r-> zero -> two -> one = create_node();
	r-> zero -> two-> one-> value = 'E';
	r-> zero -> three -> zero = create_node();
	r-> zero -> three-> zero-> value = 'A';
	r-> zero -> three -> one = create_node();
	r-> zero -> three-> one-> value = 'R';

	r-> one -> zero -> zero = create_node();
	r-> one -> zero-> zero-> value = 'D';
	r-> one -> zero -> one = create_node();
	r-> one -> zero-> one-> value = 'L';
	r-> one -> one -> zero = create_node();
	r-> one -> one-> zero-> value = 'C';
	r-> one -> one -> one = create_node();
	r-> one -> one-> one-> value = 'M';
	r-> one -> two -> zero = create_node();
	r-> one -> two-> zero-> value = 'T';
	r-> one -> two -> one = create_node();
	r-> one -> two-> one-> value = 'O';
	r-> one -> three -> zero = create_node();
	r-> one -> three-> zero-> value = 'H';
	r-> one -> three -> one = create_node();
	r-> one -> three-> one-> value = 'T';

	//LEVEL 4
	r-> zero -> zero -> zero->zero = create_node();
	r-> zero -> zero-> zero->zero-> value = 'M';
	r-> zero -> zero -> zero->one = create_node();
	r-> zero -> zero-> zero->one-> value = 'R';
	r-> zero -> zero -> one->zero = create_node();
	r-> zero -> zero-> one->zero-> value = 'R';
	r-> zero -> zero -> one->one = create_node();
	r-> zero -> zero-> one->one-> value = 'O';
	r-> zero -> one -> zero->zero = create_node();
	r-> zero -> one-> zero->zero-> value = 'D';
	r-> zero -> one -> zero->one = create_node();
	r-> zero -> one-> zero->one-> value = 'R';
	r-> zero -> one -> one->zero = create_node();
	r-> zero -> one-> one->zero-> value = 'E';
	r-> zero -> one -> one->one = create_node();
	r-> zero -> one-> one->one-> value = 'A';
	r-> zero -> two -> zero->zero = create_node();
	r-> zero -> two-> zero->zero-> value = 'N';
	r-> zero -> two -> zero->one = create_node();
	r-> zero -> two-> zero->one-> value = 'R';
	r-> zero -> two -> one->zero = create_node();
	r-> zero -> two-> one->zero-> value = 'A';
	r-> zero -> two -> one->one = create_node();
	r-> zero -> two-> one->one-> value = 'L';
	r-> zero -> three -> zero->zero = create_node();
	r-> zero -> three-> zero->zero-> value = 'R';
	r-> zero -> three -> zero->one = create_node();
	r-> zero -> three-> zero->one-> value = 'M';
	r-> zero -> three -> one-> zero = create_node();
	r-> zero -> three-> one-> zero-> value = 'I';
	r-> zero -> three -> one->one = create_node();
	r-> zero -> three-> one->one-> value = 'V';

	r-> one -> zero -> zero->zero = create_node();
	r-> one -> zero-> zero->zero-> value = 'E';
	r-> one -> zero -> zero->one = create_node();
	r-> one -> zero-> zero->one-> value = 'O';
	r-> one -> zero -> one->zero = create_node();
	r-> one -> zero-> one->zero-> value = 'E';
	r-> one -> zero -> one->one = create_node();
	r-> one -> zero-> one->one-> value = 'I';
	r-> one -> one -> zero->zero = create_node();
	r-> one -> one-> zero->zero-> value = 'H';
	r-> one -> one -> zero->one = create_node();
	r-> one -> one-> zero->one-> value = 'A';
	r-> one -> one -> one->zero = create_node();
	r-> one -> one-> one->zero-> value = 'I';
	r-> one -> one -> one->one = create_node();
	r-> one -> one-> one->one-> value = 'O';
	r-> one -> two -> zero->zero = create_node();
	r-> one -> two-> zero->zero-> value = 'A';
	r-> one -> two -> zero->one = create_node();
	r-> one -> two-> zero->one-> value = 'E';
	r-> one -> two -> one->zero = create_node();
	r-> one -> two-> one->zero-> value = 'N';
	r-> one -> two -> one->one = create_node();
	r-> one -> two-> one->one-> value = 'K';
	r-> one -> three -> zero->zero = create_node();
	r-> one -> three-> zero->zero-> value = 'I';
	r-> one -> three -> zero->one = create_node();
	r-> one -> three-> zero->one-> value = 'M';
	r-> one -> three -> one-> zero = create_node();
	r-> one -> three-> one-> zero-> value = 'R';
	r-> one -> three -> one->one = create_node();
	r-> one -> three-> one->one-> value = 'E';

	//LEVEL 5
	r-> zero -> zero -> zero->zero->zero = create_node();
	r-> zero -> zero-> zero->zero->zero-> value = '0';
	r-> zero -> zero -> zero->zero->one = create_node();
	r-> zero -> zero-> zero->zero->one-> value = 'E';
	r-> zero -> zero -> zero->one->zero = create_node();
	r-> zero -> zero-> zero->one->zero-> value = 'E';
	r-> zero -> zero -> zero->one->one = create_node();
	r-> zero -> zero-> zero->one->one-> value = 'P';
	r-> zero -> zero -> one->zero->zero = create_node();
	r-> zero -> zero-> one->zero->zero-> value = 'E';
	r-> zero -> zero -> one->zero->one = create_node();
	r-> zero -> zero-> one->zero->one-> value = 'T';
	r-> zero -> zero -> one->one->zero = create_node();
	r-> zero -> zero-> one->one->zero-> value = 'E';
	r-> zero -> zero -> one->one->one = create_node();
	r-> zero -> zero-> one->one->one-> value = 'L';
	r-> zero -> one -> zero->zero->zero = create_node();
	r-> zero -> one-> zero->zero->zero-> value = 'E';
	r-> zero -> one -> zero->zero->one = create_node();
	r-> zero -> one-> zero->zero->one-> value = 'I';
	r-> zero -> one -> zero->one->zero = create_node();
	r-> zero -> one-> zero->one->zero-> value = 'R';
	r-> zero -> one -> zero->one->one = create_node();
	r-> zero -> one-> zero->one->one-> value = 'T';
	r-> zero -> one -> one->zero->zero = create_node();
	r-> zero -> one-> one->zero->zero-> value = 'D';
	r-> zero -> one -> one->zero->one = create_node();
	r-> zero -> one-> one->zero->one-> value = 'L';
	r-> zero -> one -> one->one->zero = create_node();
	r-> zero -> one-> one->one->zero-> value = 'N';
	r-> zero -> one -> one->one->one = create_node();
	r-> zero -> one-> one->one->one-> value = 'R';
	r-> zero -> two -> zero->zero->zero = create_node();
	r-> zero -> two-> zero->zero->zero-> value = 'Z';
	r-> zero -> two -> zero->zero->one = create_node();
	r-> zero -> two-> zero->zero->one-> value = 'C';
	r-> zero -> two -> zero->one->zero = create_node();
	r-> zero -> two-> zero->one->zero-> value = 'R';
	r-> zero -> two -> zero->one->one = create_node();
	r-> zero -> two-> zero->one->one-> value = 'E';
	r-> zero -> two -> one->zero->zero = create_node();
	r-> zero -> two-> one->zero->zero-> value = 'L';
	r-> zero -> two -> one->zero->one = create_node();
	r-> zero -> two-> one->zero->one-> value = 'M';
	r-> zero -> two -> one->one->zero = create_node();
	r-> zero -> two-> one->one->zero-> value = 'A';
	r-> zero -> two -> one->one->one = create_node();
	r-> zero -> two-> one->one->one-> value = 'L';
	r-> zero -> three -> zero->zero->zero = create_node();
	r-> zero -> three-> zero->zero->zero-> value = 'E';
	r-> zero -> three -> zero->zero->one = create_node();
	r-> zero -> three-> zero->zero->one-> value = 'C';
	r-> zero -> three -> zero->one->zero = create_node();
	r-> zero -> three-> zero->one->zero-> value = 'E';
	r-> zero -> three -> zero->one->one = create_node();
	r-> zero -> three-> zero->one->one-> value = 'E';
	r-> zero -> three -> one->zero->zero = create_node();
	r-> zero -> three-> one->zero->zero-> value = 'N';
	r-> zero -> three -> one->zero->one = create_node();
	r-> zero -> three-> one->zero->one-> value = 'E';
	r-> zero -> three -> one->one->zero = create_node();
	r-> zero -> three-> one->one->zero-> value = 'E';
	r-> zero -> three -> one->one->one = create_node();
	r-> zero -> three-> one->one->one-> value = 'A';

	r-> one -> zero -> zero->zero->zero = create_node();
	r-> one -> zero-> zero->zero->zero-> value = 'A';
	r-> one -> zero -> zero->zero->one = create_node();
	r-> one -> zero-> zero->zero->one-> value = 'R';
	r-> one -> zero -> zero->one->zero = create_node();
	r-> one -> zero-> zero->one->zero-> value = 'S';
	r-> one -> zero -> zero->one->one = create_node();
	r-> one -> zero-> zero->one->one-> value = 'L';
	r-> one -> zero -> one->zero->zero = create_node();
	r-> one -> zero-> one->zero->zero-> value = 'G';
	r-> one -> zero -> one->zero->one = create_node();
	r-> one -> zero-> one->zero->one-> value = 'L';
	r-> one -> zero -> one->one->zero = create_node();
	r-> one -> zero-> one->one->zero-> value = 'E';
	r-> one -> zero -> one->one->one = create_node();
	r-> one -> zero-> one->one->one-> value = 'U';
	r-> one -> one -> zero->zero->zero = create_node();
	r-> one -> one-> zero->zero->zero-> value = 'E';
	r-> one -> one -> zero->zero->one = create_node();
	r-> one -> one-> zero->zero->one-> value = 'L';
	r-> one -> one -> zero->one->zero = create_node();
	r-> one -> one-> zero->one->zero-> value = 'D';
	r-> one -> one -> zero->one->one = create_node();
	r-> one -> one-> zero->one->one-> value = 'N';
	r-> one -> one -> one->zero->zero = create_node();
	r-> one -> one-> one->zero->zero-> value = 'N';
	r-> one -> one -> one->zero->one = create_node();
	r-> one -> one-> one->zero->one-> value = 'E';
	r-> one -> one -> one->one->zero = create_node();
	r-> one -> one-> one->one->zero-> value = 'U';
	r-> one -> one -> one->one->one = create_node();
	r-> one -> one-> one->one->one-> value = 'R';
	r-> one -> two -> zero->zero->zero = create_node();
	r-> one -> two-> zero->zero->zero-> value = 'C';
	r-> one -> two -> zero->zero->one = create_node();
	r-> one -> two-> zero->zero->one-> value = 'I';
	r-> one -> two -> zero->one->zero = create_node();
	r-> one -> two-> zero->one->zero-> value = 'N';
	r-> one -> two -> zero->one->one = create_node();
	r-> one -> two-> zero->one->one-> value = 'S';
	r-> one -> two -> one->zero->zero = create_node();
	r-> one -> two-> one->zero->zero-> value = 'I';
	r-> one -> two -> one->zero->one = create_node();
	r-> one -> two-> one->zero->one-> value = 'E';
	r-> one -> two -> one->one->zero = create_node();
	r-> one -> two-> one->one->zero-> value = 'A';
	r-> one -> two -> one->one->one = create_node();
	r-> one -> two-> one->one->one-> value = 'E';
	r-> one -> three -> zero->zero->zero = create_node();
	r-> one -> three-> zero->zero->zero-> value = 'N';
	r-> one -> three -> zero->zero->one = create_node();
	r-> one -> three-> zero->zero->one-> value = 'E';
	r-> one -> three -> zero->one->zero = create_node();
	r-> one -> three-> zero->one->zero-> value = 'A';
	r-> one -> three -> zero->one->one = create_node();
	r-> one -> three-> zero->one->one-> value = 'E';
	r-> one -> three -> one->zero->zero = create_node();
	r-> one -> three-> one->zero->zero-> value = 'U';
	r-> one -> three -> one->zero->one = create_node();
	r-> one -> three-> one->zero->one-> value = 'A';
	r-> one -> three -> one->one->zero = create_node();
	r-> one -> three-> one->one->zero-> value = 'R';
	r-> one -> three -> one->one->one = create_node();
	r-> one -> three-> one->one->one-> value = 'L';
	
	//LEVEL 6
	
	r-> zero -> zero -> zero->zero->zero->zero = create_node();
	r-> zero -> zero-> zero->zero->zero->zero-> value = 'Y';
	r-> zero -> zero -> zero->zero->zero->one = create_node();
	r-> zero -> zero-> zero->zero->zero->one-> value = 'S';
	r-> zero -> zero -> zero->zero->one->zero = create_node();
	r-> zero -> zero-> zero->zero->one->zero-> value = 'D';
	r-> zero -> zero -> zero->zero->one->one = create_node();
	r-> zero -> zero-> zero->zero->one->one-> value = 'S';
	r-> zero -> zero -> zero->one->zero->zero = create_node();
	r-> zero -> zero-> zero->one->zero->zero-> value = 'D';
	r-> zero -> zero -> zero->one->zero->one = create_node();
	r-> zero -> zero-> zero->one->zero->one-> value = 'S';
	r-> zero -> zero -> zero->one->one->zero = create_node();
	r-> zero -> zero-> zero->one->one->zero-> value = 'Y';
	r-> zero -> zero -> zero->one->one->one = create_node();
	r-> zero -> zero-> zero->one->one->one-> value = 'S';

	r-> zero -> zero -> one->zero->zero->zero = create_node();
	r-> zero -> zero-> one->zero->zero->zero-> value = 'R';
	r-> zero -> zero -> one->zero->zero->one = create_node();
	r-> zero -> zero-> one->zero->zero->one-> value = 'S';
	r-> zero -> zero -> one->zero->one->zero = create_node();
	r-> zero -> zero-> one->zero->one->zero-> value = 'Y';
	r-> zero -> zero -> one->zero->one->one = create_node();
	r-> zero -> zero-> one->zero->one->one-> value = 'S';
	r-> zero -> zero -> one->one->zero->zero = create_node();
	r-> zero -> zero-> one->one->zero->zero-> value = 'D';
	r-> zero -> zero -> one->one->zero->one = create_node();
	r-> zero -> zero-> one->one->zero->one-> value = 'D';
	r-> zero -> zero -> one->one->one->zero = create_node();
	r-> zero -> zero-> one->one->one->zero-> value = 'E';
	r-> zero -> zero -> one->one->one->one = create_node();
	r-> zero -> zero-> one->one->one->one-> value = 'S';

	r-> zero -> one -> zero->zero->zero->zero = create_node();
	r-> zero -> one-> zero->zero->zero->zero-> value = 'R';
	r-> zero -> one -> zero->zero->zero->one = create_node();
	r-> zero -> one-> zero->zero->zero->one-> value = 'S';
	r-> zero -> one -> zero->zero->one->zero = create_node();
	r-> zero -> one-> zero->zero->one->zero-> value = 'X';
	r-> zero -> one -> zero->zero->one->one = create_node();
	r-> zero -> one-> zero->zero->one->one-> value = 'X';
	r-> zero -> one -> zero->one->zero->zero = create_node();
	r-> zero -> one-> zero->one->zero->zero-> value = 'Y';
	r-> zero -> one -> zero->one->zero->one = create_node();
	r-> zero -> one-> zero->one->zero->one-> value = 'E';
	r-> zero -> one -> zero->one->one->zero = create_node();
	r-> zero -> one-> zero->one->one->zero-> value = 'H';
	r-> zero -> one -> zero->one->one->one = create_node();
	r-> zero -> one-> zero->one->one->one-> value = 'S';

	r-> zero -> one -> one->zero->zero->zero = create_node();
	r-> zero -> one-> one->zero->zero->zero-> value = 'O';
	r-> zero -> one -> one->zero->zero->one = create_node();
	r-> zero -> one-> one->zero->zero->one-> value = 'Y';
	r-> zero -> one -> one->zero->one->zero = create_node();
	r-> zero -> one-> one->zero->one->zero-> value = 'S';
	r-> zero -> one -> one->zero->one->one = create_node();
	r-> zero -> one-> one->zero->one->one-> value = 'S';
	r-> zero -> one -> one->one->zero->zero = create_node();
	r-> zero -> one-> one->one->zero->zero-> value = 'S';
	r-> zero -> one -> one->one->zero->one = create_node();
	r-> zero -> one-> one->one->zero->one-> value = 'S';
	r-> zero -> one -> one->one->one->zero = create_node();
	r-> zero -> one-> one->one->one->zero-> value = 'Y';
	r-> zero -> one -> one->one->one->one = create_node();
	r-> zero -> one-> one->one->one->one-> value = 'S';
	
	r-> zero -> two -> zero->zero->zero->zero = create_node();
	r-> zero -> two-> zero->zero->zero->zero-> value = 'A';
	r-> zero -> two -> zero->zero->zero->one = create_node();
	r-> zero -> two-> zero->zero->zero->one-> value = 'E';
	r-> zero -> two -> zero->zero->one->zero = create_node();
	r-> zero -> two-> zero->zero->one->zero-> value = 'E';
	r-> zero -> two -> zero->zero->one->one = create_node();
	r-> zero -> two-> zero->zero->one->one-> value = 'H';
	r-> zero -> two -> zero->one->zero->zero = create_node();
	r-> zero -> two-> zero->one->zero->zero-> value = 'Y';
	r-> zero -> two -> zero->one->zero->one = create_node();
	r-> zero -> two-> zero->one->zero->one-> value = 'S';
	r-> zero -> two -> zero->one->one->zero = create_node();
	r-> zero -> two-> zero->one->one->zero-> value = 'R';
	r-> zero -> two -> zero->one->one->one = create_node();
	r-> zero -> two-> zero->one->one->one-> value = 'D';

	r-> zero -> two -> one->zero->zero->zero = create_node();
	r-> zero -> two-> one->zero->zero->zero-> value = 'S';
	r-> zero -> two -> one->zero->zero->one = create_node();
	r-> zero -> two-> one->zero->zero->one-> value = 'T';
	r-> zero -> two -> one->zero->one->zero = create_node();
	r-> zero -> two-> one->zero->one->zero-> value = 'Y';
	r-> zero -> two -> one->zero->one->one = create_node();
	r-> zero -> two-> one->zero->one->one-> value = 'S';
	r-> zero -> two -> one->one->zero->zero = create_node();
	r-> zero -> two-> one->one->zero->zero-> value = 'E';
	r-> zero -> two -> one->one->zero->one = create_node();
	r-> zero -> two-> one->one->zero->one-> value = 'E';
	r-> zero -> two -> one->one->one->zero = create_node();
	r-> zero -> two-> one->one->one->zero-> value = 'A';
	r-> zero -> two -> one->one->one->one = create_node();
	r-> zero -> two-> one->one->one->one-> value = 'S';
	
	r-> zero -> three -> zero->zero->zero->zero = create_node();
	r-> zero -> three-> zero->zero->zero->zero-> value = 'R';
	r-> zero -> three -> zero->zero->zero->one = create_node();
	r-> zero -> three-> zero->zero->zero->one-> value = 'D';
	r-> zero -> three -> zero->zero->one->zero = create_node();
	r-> zero -> three-> zero->zero->one->zero-> value = 'E';
	r-> zero -> three -> zero->zero->one->one = create_node();
	r-> zero -> three-> zero->zero->one->one-> value = 'H';
	r-> zero -> three -> zero->one->zero->zero = create_node();
	r-> zero -> three-> zero->one->zero->zero-> value = 'D';
	r-> zero -> three -> zero->one->zero->one = create_node();
	r-> zero -> three-> zero->one->zero->one-> value = 'N';
	r-> zero -> three -> zero->one->one->zero = create_node();
	r-> zero -> three-> zero->one->one->zero-> value = 'R';
	r-> zero -> three -> zero->one->one->one = create_node();
	r-> zero -> three-> zero->one->one->one-> value = 'S';

	r-> zero -> three -> one->zero->zero->zero = create_node();
	r-> zero -> three-> one->zero->zero->zero-> value = 'S';
	r-> zero -> three -> one->zero->zero->one = create_node();
	r-> zero -> three-> one->zero->zero->one-> value = 'G';
	r-> zero -> three -> one->zero->one->zero = create_node();
	r-> zero -> three-> one->zero->one->zero-> value = 'S';
	r-> zero -> three -> one->zero->one->one = create_node();
	r-> zero -> three-> one->zero->one->one-> value = 'S';
	r-> zero -> three -> one->one->zero->zero = create_node();
	r-> zero -> three-> one->one->zero->zero-> value = 'S';
	r-> zero -> three -> one->one->zero->one = create_node();
	r-> zero -> three-> one->one->zero->one-> value = 'R';
	r-> zero -> three -> one->one->one->zero = create_node();
	r-> zero -> three-> one->one->one->zero-> value = 'L';
	r-> zero -> three -> one->one->one->one = create_node();
	r-> zero -> three-> one->one->one->one-> value = 'L';



	r-> one -> zero -> zero->zero->zero->zero = create_node();
	r-> one -> zero-> zero->zero->zero->zero-> value = 'S';
	r-> one -> zero -> zero->zero->zero->one = create_node();
	r-> one -> zero-> zero->zero->zero->one-> value = 'S';
	r-> one -> zero -> zero->zero->one->zero = create_node();
	r-> one -> zero-> zero->zero->one->zero-> value = 'N';
	r-> one -> zero -> zero->zero->one->one = create_node();
	r-> one -> zero-> zero->zero->one->one-> value = 'S';
	r-> one -> zero -> zero->one->zero->zero = create_node();
	r-> one -> zero-> zero->one->zero->zero-> value = 'E';
	r-> one -> zero -> zero->one->zero->one = create_node();
	r-> one -> zero-> zero->one->zero->one-> value = 'E';
	r-> one -> zero -> zero->one->one->zero = create_node();
	r-> one -> zero-> zero->one->one->zero-> value = 'S';
	r-> one -> zero -> zero->one->one->one = create_node();
	r-> one -> zero-> zero->one->one->one-> value = 'S';

	r-> one -> zero -> one->zero->zero->zero = create_node();
	r-> one -> zero-> one->zero->zero->zero-> value = 'E';
	r-> one -> zero -> one->zero->zero->one = create_node();
	r-> one -> zero-> one->zero->zero->one-> value = 'E';
	r-> one -> zero -> one->zero->one->zero = create_node();
	r-> one -> zero-> one->zero->one->zero-> value = 'S';
	r-> one -> zero -> one->zero->one->one = create_node();
	r-> one -> zero-> one->zero->one->one-> value = 'E';
	r-> one -> zero -> one->one->zero->zero = create_node();
	r-> one -> zero-> one->one->zero->zero-> value = 'D';
	r-> one -> zero -> one->one->zero->one = create_node();
	r-> one -> zero-> one->one->zero->one-> value = 'S';
	r-> one -> zero -> one->one->one->zero = create_node();
	r-> one -> zero-> one->one->one->zero-> value = 'M';
	r-> one -> zero -> one->one->one->one = create_node();
	r-> one -> zero-> one->one->one->one-> value = 'M';

	r-> one -> one -> zero->zero->zero->zero = create_node();
	r-> one -> one-> zero->zero->zero->zero-> value = 'R';
	r-> one -> one -> zero->zero->zero->one = create_node();
	r-> one -> one-> zero->zero->zero->one-> value = 'S';
	r-> one -> one -> zero->zero->one->zero = create_node();
	r-> one -> one-> zero->zero->one->zero-> value = 'Y';
	r-> one -> one -> zero->zero->one->one = create_node();
	r-> one -> one-> zero->zero->one->one-> value = 'Y';
	r-> one -> one -> zero->one->zero->zero = create_node();
	r-> one -> one-> zero->one->zero->zero-> value = 'E';
	r-> one -> one -> zero->one->zero->one = create_node();
	r-> one -> one-> zero->one->zero->one-> value = 'E';
	r-> one -> one -> zero->one->one->zero = create_node();
	r-> one -> one-> zero->one->one->zero-> value = 'A';
	r-> one -> one -> zero->one->one->one = create_node();
	r-> one -> one-> zero->one->one->one-> value = 'E';

	r-> one -> one -> one->zero->zero->zero = create_node();
	r-> one -> one-> one->zero->zero->zero-> value = 'G';
	r-> one -> one -> one->zero->zero->one = create_node();
	r-> one -> one-> one->zero->zero->one-> value = 'G';
	r-> one -> one -> one->zero->one->zero = create_node();
	r-> one -> one-> one->zero->one->zero-> value = 'S';
	r-> one -> one -> one->zero->one->one = create_node();
	r-> one -> one-> one->zero->one->one-> value = 'S';
	r-> one -> one -> one->one->zero->zero = create_node();
	r-> one -> one-> one->one->zero->zero-> value = 'R';
	r-> one -> one -> one->one->zero->one = create_node();
	r-> one -> one-> one->one->zero->one-> value = 'R';
	r-> one -> one -> one->one->one->zero = create_node();
	r-> one -> one-> one->one->one->zero-> value = 'Y';
	r-> one -> one -> one->one->one->one = create_node();
	r-> one -> one-> one->one->one->one-> value = 'S';
	
	r-> one -> two -> zero->zero->zero->zero = create_node();
	r-> one -> two-> zero->zero->zero->zero-> value = 'K';
	r-> one -> two -> zero->zero->zero->one = create_node();
	r-> one -> two-> zero->zero->zero->one-> value = 'H';
	r-> one -> two -> zero->zero->one->zero = create_node();
	r-> one -> two-> zero->zero->one->zero-> value = 'N';
	r-> one -> two -> zero->zero->one->one = create_node();
	r-> one -> two-> zero->zero->one->one-> value = 'N';
	r-> one -> two -> zero->one->zero->zero = create_node();
	r-> one -> two-> zero->one->zero->zero-> value = 'D';
	r-> one -> two -> zero->one->zero->one = create_node();
	r-> one -> two-> zero->one->zero->one-> value = 'T';
	r-> one -> two -> zero->one->one->zero = create_node();
	r-> one -> two-> zero->one->one->zero-> value = 'T';
	r-> one -> two -> zero->one->one->one = create_node();
	r-> one -> two-> zero->one->one->one-> value = 'T';

	r-> one -> two -> one->zero->zero->zero = create_node();
	r-> one -> two-> one->zero->zero->zero-> value = 'C';
	r-> one -> two -> one->zero->zero->one = create_node();
	r-> one -> two-> one->zero->zero->one-> value = 'A';
	r-> one -> two -> one->zero->one->zero = create_node();
	r-> one -> two-> one->zero->one->zero-> value = 'D';
	r-> one -> two -> one->zero->one->one = create_node();
	r-> one -> two-> one->zero->one->one-> value = 'S';
	r-> one -> two -> one->one->zero->zero = create_node();
	r-> one -> two-> one->one->zero->zero-> value = 'L';
	r-> one -> two -> one->one->zero->one = create_node();
	r-> one -> two-> one->one->zero->one-> value = 'L';
	r-> one -> two -> one->one->one->zero = create_node();
	r-> one -> two-> one->one->one->zero-> value = 'S';
	r-> one -> two -> one->one->one->one = create_node();
	r-> one -> two-> one->one->one->one-> value = 'S';
	
	r-> one -> three -> zero->zero->zero->zero = create_node();
	r-> one -> three-> zero->zero->zero->zero-> value = 'E';
	r-> one -> three -> zero->zero->zero->one = create_node();
	r-> one -> three-> zero->zero->zero->one-> value = 'G';
	r-> one -> three -> zero->zero->one->zero = create_node();
	r-> one -> three-> zero->zero->one->zero-> value = 'R';
	r-> one -> three -> zero->zero->one->one = create_node();
	r-> one -> three-> zero->zero->one->one-> value = 'R';
	r-> one -> three -> zero->one->zero->zero = create_node();
	r-> one -> three-> zero->one->zero->zero-> value = 'N';
	r-> one -> three -> zero->one->zero->one = create_node();
	r-> one -> three-> zero->one->zero->one-> value = 'N';
	r-> one -> three -> zero->one->one->zero = create_node();
	r-> one -> three-> zero->one->one->zero-> value = 'N';
	r-> one -> three -> zero->one->one->one = create_node();
	r-> one -> three-> zero->one->one->one-> value = 'N';

	r-> one -> three -> one->zero->zero->zero = create_node();
	r-> one -> three-> one->zero->zero->zero-> value = 'T';
	r-> one -> three -> one->zero->zero->one = create_node();
	r-> one -> three-> one->zero->zero->one-> value = 'T';
	r-> one -> three -> one->zero->one->zero = create_node();
	r-> one -> three-> one->zero->one->zero-> value = 'Y';
	r-> one -> three -> one->zero->one->one = create_node();
	r-> one -> three-> one->zero->one->one-> value = 'L';
	r-> one -> three -> one->one->zero->zero = create_node();
	r-> one -> three-> one->one->zero->zero-> value = 'S';
	r-> one -> three -> one->one->zero->one = create_node();
	r-> one -> three-> one->one->zero->one-> value = 'N';
	r-> one -> three -> one->one->one->zero = create_node();
	r-> one -> three-> one->one->one->zero-> value = 'Y';
	r-> one -> three -> one->one->one->one = create_node();
	r-> one -> three-> one->one->one->one-> value = 'Y';

	return r;
}	
void four(struct tree * temp)
{
	int queue4[4], front = 0, rear = 0;
	int corr,rest,i,j,same,c,d,l;
	char word[5];
	struct node *q,*q1;
	q1=res;
	q=(struct node*)malloc(sizeof(struct node));
	q->score=12;
	q->next=NULL;
	if(res==NULL)
		res=q;
	else
	{
		while(q1->next!=NULL)
			q1=q1->next;
		q1->next=q;
	}
	srand(time(NULL));
	int r1 = rand() % 4;	int r2 = rand() % 4;	int r3 = rand() % 3;	int r4 = rand() % 2;
	
	if(r1 == 0)
		temp = temp->zero;
	else if (r1 == 1)
		temp = temp->one;
	else if (r1 == 2)
		temp = temp->two;
	else 
		temp = temp->three;
	queue4[rear] = temp->value;
	word[0]=temp->value;
	//word+='\n';
	//printf("%s",word);
	

	if (r2 == 0)
		temp = temp->zero;
	else if (r2 == 1)
		temp = temp->one;
	else if (r2 == 2)
		temp = temp->two;
	else
		temp = temp->three;
	queue4[++rear] = temp->value;
	word[1]=temp->value;

	if (r3 == 0)
		temp = temp->zero;
	else if (r3 == 1)
		temp = temp->one;
	else 
		temp = temp->two;
	
	queue4[++rear] = temp->value;
	word[2]=temp->value;

	if (r4 == 0)
		temp = temp->zero;
	else 
		temp = temp->one;
	
	queue4[++rear] = temp->value;
	word[3]=temp->value;
	word[4]='\0';
	strcpy(q->s,word);
	guess(queue4,3,q);
	
}

void five(struct tree *temp)
{
	int queue5[5], front = 0, rear = 0;
	int corr,rest,i,j,same,c,d,l;
	char word[6];
	struct node *q,*q1;
	q1=res;
	q=(struct node*)malloc(sizeof(struct node));
	q->score=15;
	q->next=NULL;
	if(res==NULL)
		res=q;
	else
	{
		while(q1->next!=NULL)
			q1=q1->next;
		q1->next=q;
	}
	srand(time(NULL));
	int r1 = rand() % 4;	int r2 = rand() % 4;	int r3 = rand() % 3;	int r5 = rand() % 2;
	
	if(r1 == 0)
		temp = temp->zero;
	else if (r1 == 1)
		temp = temp->one;
	else if (r1 == 2)
		temp = temp->two;
	else 
		temp = temp->three;
	queue5[rear] = temp->value;
	word[0]=temp->value;
	

	if (r2 == 0)
		temp = temp->zero;
	else if (r2 == 1)
		temp = temp->one;
	else if (r2 == 2)
		temp = temp->two;
	else
		temp = temp->three;
	queue5[++rear] = temp->value;
	word[1]=temp->value;

	if (r3 == 0)
		temp = temp->zero;
	else if (r3 == 1)
		temp = temp->one;
	else 
		temp = temp->two;
	
	queue5[++rear] = temp->value;
	word[2]=temp->value;
	temp = temp->zero;
	queue5[++rear] = temp->value;
	word[3]=temp->value;

	if (r5 == 0)
		temp = temp->zero;
	else 
		temp = temp->one;
	
	queue5[++rear] = temp->value;
	word[4]=temp->value;
	word[5]='\0';
	strcpy(q->s,word);
	guess(queue5,4,q);
	
}

void six(struct tree *temp)
{
	int queue6[6], front = 0, rear = 0;
	int corr,rest,i,j,same,c,d,l;
	char word[7];
	struct node *q,*q1;
	q1=res;
	q=(struct node*)malloc(sizeof(struct node));
	q->score=18;
	q->next=NULL;
	if(res==NULL)
		res=q;
	else
	{
		while(q1->next!=NULL)
			q1=q1->next;
		q1->next=q;
	}
	srand(time(NULL));
	int r1 = rand() % 2;	int r2 = rand() % 4;	int r3 = rand() % 2;	
	int r4 = rand() % 2;	int r5 = rand() %2;	int r6 =rand() % 2;
	
	if(r1 == 0)
		temp = temp->zero;

	else 
		temp = temp->one;
	queue6[rear] = temp->value;
	word[0]=temp->value;
	

	if (r2 == 0)
		temp = temp->zero;
	else if (r2 == 1)
		temp = temp->one;
	else if (r2 == 2)
		temp = temp->two;
	else
		temp = temp->three;
	queue6[++rear] = temp->value;
	word[1]=temp->value;

	if (r3 == 0)
		temp = temp->zero;
	else 
		temp = temp->one;
	
	queue6[++rear] = temp->value;
	word[2]=temp->value;
	
	if (r4 == 0)
		temp = temp->zero;
	else 
		temp = temp->one;
	
	queue6[++rear] = temp->value;
	word[3]=temp->value;

	if (r5 == 0)
		temp = temp->zero;
	else 
		temp = temp->one;
	
	queue6[++rear] = temp->value;
	word[4]=temp->value;

	if (r6 == 0)
		temp = temp->zero;
	else 
		temp = temp->one;
	
	queue6[++rear] = temp->value;
	word[5]=temp->value;
	word[6]='\0';
	strcpy(q->s,word);
	guess(queue6,5,q);
	
}

void results()
{
	int totalscore = 0;
	printf("\n--RESULTS--\n");
	while(res!=NULL)
	{
		printf("WORD:%s\n",res->s);
		if(res-> score>= 0)
			printf("SCORE: %d\n",res->score);
		else printf("SCORE: 0\n");
		totalscore+= res->score;
		printf("\n");	
		res=res->next;
	}
	printf("Your total score is: %d \n", totalscore);
}
void guess(int *queue4, int rear, struct node *q)
{
	char t;
	int front = 0;
	int corr,rest,j,same,c,d,l;
	char guesses[10][10];
	int fnode = 0;
	while(fnode <= rear)
	{
		int r[4];
		for (j =0; j<=3; j++)
			{
				
				r[j] = rand() %26;
				r[j] +=65;
				for (same =0; same<j; same++)
					if ((r[j] == r[same]) || (r[j] == queue4[fnode]))
							r[j]+=2; 
				guesses[fnode][j] = (char)r[j];
				guesses[fnode][3] = queue4[fnode];
			}
		//SORTING SO THAT PERSON DOES NOT KNOW WHERE THE LETTER IS IN THE OPTIONS
		for (c = 0 ; c < 4 ; c++) 
  			for (d = 0 ; d < 3; d++)
   				if (guesses[fnode][d] > guesses[fnode][d+1]) 
				{
        				t       = guesses[fnode][d];
        				guesses[fnode][d]   = guesses[fnode][d+1];
        				guesses[fnode][d+1] = t;
      				}
  		printf("\nCHOICES: ");
		//MAKING USER GUESS
		for (l =0;l<4; l++)
			printf("%c ", guesses[fnode][l]);
			printf("\n");
		char a;
		do
		{				
			printf("Enter your guess: ");
			scanf(" %c",&a);
		if (toupper(a) == guesses[fnode][0] ||toupper(a) == guesses[fnode][1]||toupper(a) == guesses[fnode][2]||toupper(a) == guesses[fnode][3])
			{
			if (toupper(a) != queue4[fnode])
				{
					printf("TRY AGAIN. Wrong choice\n");
					--(q->score);
				}
			}
		else printf("INCORRECT CHOICE ENTERED\n");
						
		}while(toupper(a) != queue4[fnode]);
		printf("YOU GUESSED THAT LETTER RIGHT!\t\t");
		for (corr = 0; corr<= fnode; corr++)
			printf("%c",queue4[corr]);
		for (rest =fnode+1; rest<=rear; rest++)
			printf("_");
		fnode++;
	}
	printf("\n");
}
void main()
{
	printf("Welcome to HANGWORD\n");
	printf("_____________________________________________________________________________\n\n");
	printf("This is a word guessing game, don't think it is easy, neither you nor me know\n what the word is. Its all the compiler's decision\n\n");
	printf("On choosing a level, you will be given 4 choices of letters, only one of these\n is the correct first letter of the word selected\n\n");
	printf("This will continue until you guess all the letters of the word correctly and\n you will be asked if you would like to play again\n\n");
	printf("4 letter words are scored on 12 pointS, 5 letter words on 15 points and 6\n letter words on 18 points. Wrong guesses cause a reduction in points\n\n");
	printf("ENJOY! and All the Best\n\n"); 
	T *temp;
	temp=r;
	int ch, level;
	do
	{
	printf("Enter level: \n 1. for 4 letter words \n 2. for 5 letter words \n 3. for 6 letter words\n");
	scanf("%d",&level);
	if (level == 1)
	{
		r = make_tree_4();
		four(r);
	}
	else if (level == 2)
	{
		l2 = make_tree_5();
		five(l2);
	}
	else if (level == 3)
	{
		l3 = make_tree_6();
		six(l3);
	}
	else printf("Invalid Level entered");
	printf("Do you want to continue?\n");
	printf("Enter 1 to continue and 0 to quit\n");
	scanf("%d",&ch);
	if (ch== 0 )
		printf("You have chosen to end the game thank you for playing\n");
	else if(ch != 1)
		printf("You have Entered an invalid input and the game has ended. Thank you for playing\n");
	}while(ch==1);
	results();
	
}
