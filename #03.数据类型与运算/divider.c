#include <stdio.h>
int main()
{
    int a = 0, b = 0, c = 0, d = 0;
	double g = 0;
	printf("It's a calculator for division.\n");
	printf("input dividend and divisor in order:");
	scanf("%d %d", &a, &b);
	c = a / b; d = a % b; g = a *1.0/ b;
	printf("%d/%d=%d...%d\n", a, b, c, d);
	printf("%d/%d=%f\n",a,b,g );
    return 0;
}