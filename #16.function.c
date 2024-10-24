/*
在此之前，我们已经知道了printf、scanf、if、while、for等函数；
然而，这些函数的定义是本来就有的；
如果要创造一个自己定义的函数，该怎么做呢？
*/
//具体看下面的例子：
#include <stdio.h>
int sumatk(int hp);
void judge(int hp, int originalhp);
int main()
{
	int originalhp,hp,n=0;
	const int ATK10 = 10;
	printf("现在有10名玩家要攻击我;\n已知玩家10的攻击为10；\n请输入我的血量：");
	scanf("%d", &originalhp);
	while (originalhp <= 0)
	{
		printf("\n你一定是在逗我玩！怎么给我设置“%d”这么一个血量！那我不是一碰就si啦！\n\n请重新输入：", originalhp);
		scanf("%d", &originalhp);
	}
	printf("好的，我现在一共有%d滴血；",originalhp);
	hp = originalhp;
	do
	{
		printf("第%d回合开始！\n", n + 1);
		int sum = sumatk(hp)+ATK10;
		hp -= sum;
		printf("OK，本回合我共计受到%d点伤害；\n我现在还剩下", sum);
		judge(hp, originalhp);
		n++;
		if (hp > 0)
			printf("虽然我很不想si掉，但是你一定要过关！\n请继续攻击！\n\n\n\n");
	} while (hp > 0);
	printf("...\n不！我的血量耗尽了！\n啊！我si了！\n");
	printf("你只用了%d回合就战胜了我；\n", n);
	printf("恭喜过关，再见！/(ㄒoㄒ)/~~\n");
	return 0;
}
int sumatk(int hp)
{
	int sumatk=0, player, atk;
	for (player = 1; player <= 10; player++)
	{
		printf("请输入玩家%d的攻击:", player);
		scanf("%d", &atk);
		while (atk < 0)
		{
			printf("\n我知道你不想攻击我，但也别把玩家1的攻击设置成“%d”啊！\n", atk);
			printf("\n这可是个负数！我不接受治疗！请重新输入：");
			scanf("%d", &atk);
		}
		sumatk += atk;
	}
	return sumatk;
}
void judge(int hp, int originalhp)
{
	int level = hp * 10 / originalhp;
	if (hp == originalhp)
		printf("%d滴血；\n我猜你并没有想攻击我！\nthank you very much!\n", hp);
	else if (level >= 6)
		printf("%d滴血；\n我还很健康！感谢您的仁慈！\n", hp);
	else if (level >= 1)
		printf("%d滴血；\n我残血了，但我还活着！\n", hp);
	else if (hp > 0)
		printf("%d滴血；\n哦！真幸运！我猜我再被打一次就si了！\n", hp);
}
/*
函数一般由声明，定义组成；

声明要讲出函数的返回类型和输入类型，必须写在主程序前，格式如下：
返回类型 函数名(输入类型若干)
其中返回类型与变量类型相似，可以填int、double等；
那么在函数的最后，就要使用return语句返回一个值给主程序，它的类型就是返回类型；
但有一种返回类型例外，它就是void，它代表“没有”，用void做返回类型不需要return语句返回值；
注意：任何函数最多只能返回1个值，因为函数的自变量只能有唯一的因变量对应；

输入类型指主程序向函数传递的若干值，与定义变量类似；
输入类型仍然可以是void，这时主程序无需向函数输入任何值；

如void judge(int hp, int originalhp)
就是声明一个函数名为judge的函数，主程序将向其传递2个值，它们将会依次定义给变量hp和originalhp，最终不返回任何值；

声明最后要加上分号；
*/

/*
函数的定义则是指在函数内部利用输入的变量进行的一系列代码；
其第一行必须是函数的声明，因此可以将函数的定义和声明写在一起；
但一般不这么做，因为把定义放在后面显得代码更加美观；
之后用大括号括起要执行的代码，构成定义；
*/

/*
函数与主程序以及函数之间是完全不相干的，它们只以互相输入的值来联系；
这就是说，你可以在主程序和函数中定义两个完全相同的变量，但它们是互不影响的；
函数中的变量有自己的起作用范围，就是在大括号外面；
一旦离开了大括号，变量就会不复存在，直到下一次调用该函数时才会出现；
*/

/*
在调用函数时，无需输入函数类型，只要输入函数名，后面跟小括号输入要传递的若干个值即可；
*/

/*
值得注意的是，main也是函数；
因为计算机内部的一些计算，main函数也要返回值，所以int main返回0；
在小括号里面，本可以放进去void，然而由于种种原因，还是不加为好；
*/