#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i=0;
	int *a=&i;
	a=(int*) malloc(4*sizeof(int));
	free(a);
	return 0;
}