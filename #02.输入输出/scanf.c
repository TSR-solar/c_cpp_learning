#include<stdio.h>
int main()
{
	int atk=0;
	printf("我现在有100滴血，请对我攻击\n你的攻击力为：");
	scanf("%d",&atk);
	int hp = 100 - atk;
	printf("OK，我现在还剩下%d滴血\n", hp);
	return 0;
}