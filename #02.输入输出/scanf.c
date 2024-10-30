#include<stdio.h>
int main()
{
	int atk=0;
	printf("I have 100 hp now,and please attack me.\n All you need to do is to input your attack here:");
	scanf("%d",&atk);
	int hp = 100 - atk;
	printf("OK,now I only have %d hp.\n", hp);
	return 0;
}