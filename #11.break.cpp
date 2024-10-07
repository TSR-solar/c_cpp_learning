/*
循环在解决实际问题方面有很广泛的应用；
然而，要想发挥其最大作用，必须引入控制循环的元素，即break和continue；
此外，函数goto也可以控制循环，
但由于其权限太大，可以跳到代码任意位置，破坏了代码的逻辑，故在此不做介绍；

简单来说，函数break可以跳出其所在循环；
而函数continue可以无视其所在循环体中接下来的所有内容，直接进入下一轮循环；
（对于for循环，仍会执行圆括号中的第三条语句）
*/
//具体可以看下面的例子:
#include <stdio.h>
int main()
{
	int atk1 = 0;
	int atk2 = 0;
	int atk3 = 0;
	int a, b, c;
	int solution = 0;
	const int hp = 100;

	printf("我现在有100滴血，现在有3名玩家要攻击我；\n");

	printf("\n但不同的是，每个人可以攻击1-10次；\n");

	printf("\n只有让我的血量刚好降为0才能过关；\n");

	printf("\n你能完成挑战吗？\n");

	do
	{
		printf("\n请输入玩家1的攻击:");

		scanf_s("%d", &atk1);

		while (atk1 <= 0)
		{
			printf("\n你一定是在逗我玩！怎么设置“%d”这么一个攻击！还想不想过关了！\n", atk1);

			printf("\n请重新输入：");

			scanf_s("%d", &atk1);
		}

		printf("\n请输入玩家2的攻击:");

		scanf_s("%d", &atk2);

		while (atk2 <= 0)
		{
			printf("\n你一定是在逗我玩！怎么设置“%d”这么一个攻击！还想不想过关了！\n", atk2);

			printf("\n请重新输入：");

			scanf_s("%d", &atk2);
		}

		printf("\n请输入玩家3的攻击:");

		scanf_s("%d", &atk3);

		while (atk3 <= 0)
		{
			printf("\n你一定是在逗我玩！怎么设置“%d”这么一个攻击！还想不想过关了！\n", atk3);

			printf("\n请重新输入：");

			scanf_s("%d", &atk3);
		}

		for (a = 1; a <= 10; a++)
		{
			for (b = 1; b <= 10; b++)
			{
				for (c = 1; c <= 10; c++)
				{
					if (a * atk1 + b * atk2 + c * atk3 == hp)
					{
						solution = 1;
						break;
					}
				}
				if (solution == 1)break;
			}
			if (solution == 1)break;
		}
		if(solution==0)

		printf("\n很遗憾......\n\n玩家们尝试了很多次，都没能过关。\n\n请重新尝试；\n\n");
	} while (solution == 0);

	printf("\n恭喜！\n\n玩家1攻击%d次，玩家2攻击%d次，玩家3攻击%d次刚好可以战胜我；\n\n你过关！！！", a, b, c);

	return 0;
}
/*
这里我们要根据三个玩家的攻击来判定是否能刚好战胜“我”；
而每个人最多能攻击10次；
因此我们采用穷举法，判定是否有解法符合条件；

		for (a = 1; a <= 10; a++)
		{
			for (b = 1; b <= 10; b++)
			{
				for (c = 1; c <= 10; c++)
				{
					if (a * atk1 + b * atk2 + c * atk3 == hp)
					{
						solution = 1;
						break;
					}
				}
				if (solution == 1)break;
			}
			if (solution == 1)break;
		}
——以上便是具体操作；
——使用嵌套循环，用排列组合的方式一个个判定结果是否符合；
—— 一旦遇到符合的情况，就让solution=1，说明可以过关；
——之后，便用break结束循环；
——但要注意的是，函数break只能跳出其所在循环，而上面共有3个循环；
——因此，在剩下两个循环下面设置了两个 if (solution == 1)break 语句；
——表明如果找到解法就一次性结束3个循环；
——这样，3个break接力完成了对循环的控制；
*/