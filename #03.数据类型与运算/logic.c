#include <stdio.h>
int main()
{
	int a = 1;
	int b = 0;
	int c;
	c = (a==0) && (b+=1);
	printf("%d\n", b);
	return 0;
}