#include"minimize.h"
int main()
{
	int * fin = (int *)malloc(sizeof(int) * 10);
	printf("MINIMIZING DFA");
	minimize(fin);
	free(fin);
	return 0;
}
