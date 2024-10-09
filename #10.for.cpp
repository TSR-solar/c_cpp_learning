/*
在C语言中，除了while循环和do-while循环，还存在第三种循环，即for循环；
作为最早的循环，for循环结构简单，也更难被理解；
*/
//以下就是一个使用for循环的例子：

#include <stdio.h>
int main()
{
	int atk;
	const int ATK10 = 10;
	int sumatk=0;
	int originalhp = 0;
	int hp = 0;
	int n = 0;
	int player = 0;

	printf("现在有10名玩家要攻击我;\n已知玩家10的攻击为10;\n请输入我的血量：");
	scanf("%d", &originalhp);
	while (originalhp <= 10)
	{
		printf("你一定是在逗我玩！怎么给我设置“%d”这么一个血量！那我不一碰就si啦！\n请重新输入：", originalhp);
		scanf("%d", &originalhp);
	}
	printf("好的，");
	hp = originalhp;

	do
	{
		printf("第%d回合开始！\n", n + 1);
		sumatk = 0;
		for (player = 1; player <= 9; player++)
		{
			printf("请输入玩家%d的攻击:", player);
			scanf("%d", &atk);
			for (atk < 0; atk < 0;)
			{
				printf("我知道你不想攻击我，但也别把玩家1的攻击设置成“%d”啊！\n", atk);
				printf("这可是个负数！我不接受治疗！请重新输入：");
				scanf("%d", &atk);
			}
			sumatk += atk;
		}
		sumatk += ATK10;
		hp -= sumatk;
		printf("OK，本回合我共计受到%d点伤害；\n我现在还剩下",sumatk);

		int level = hp * 10 / originalhp;
		if (hp >= originalhp - 10)
			printf("%d滴血；\n我猜你并没有想攻击我！\nthank you very much!\n", hp);
		else if (level >= 6)
			printf("%d滴血；\n我还很健康！感谢您的仁慈！\n", hp);
		else if (level >= 1)
			printf("%d滴血；\n我残血了，但我还活着！\n", hp);
		else if (hp > 0)
			printf("%d滴血；\n哦！真幸运！我猜我再被打一次就si了！\n", hp);
		n++;

		if (hp > 0)
			printf("虽然我很不想si掉，但是你一定要过关！\n请继续攻击！\n\n\n\n");
	} while (hp > 0);

	printf("...\n不！我的血量耗尽了！\n啊！我si了！\n\n\n");
	printf("你只用了%d回合就战胜了我；\n", n);
	printf("恭喜过关，再见！/(ㄒoㄒ)/~~\n");

	return 0;

}

/*
如果把玩家人数提升到10位，使用for循环就会显得比while循环更加方便与简洁；

		for (player = 1; player <= 9; player++)
		{
			printf("\n请输入玩家%d的攻击:", player);

			scanf("%d", &atk);

			for (atk < 0; atk < 0;)
			{
				printf("\n我知道你不想攻击我，但也别把玩家1的攻击设置成“%d”啊！\n", atk);

				printf("\n这可是个负数！我不接受治疗！请重新输入：");

				scanf("%d", &atk);
			}
			sumatk += atk;
		}
——for循环与其它判断语句类似，也是由小括号和大括号组成；
——但不同的是，for循环的小括号里面有3条语句，中间用两个分号隔开；
——即
——	for(a;b;c)
——	{d}
——三条语句分别代表初始动作，循环继续的条件和每次循环结束做的动作；
——大括号里和其它循环相同，都用来做每次循环中做的动作；
——例如第一个for，它的流程如下：
——1.初始化player的值为1；
——2.判定player的值是否大于10，若大于，则继续进行下面的步骤，反之直接结束循环；
——3.执行大括号内的代码；
——4.让player的值加1，以便输入下一名玩家的攻击；
——5.重复2-4步骤；
——
——为了理解方便，可将for翻译为“对于”；
——这样，for循环的流程可以理解为：
—— 对于 一开始的player=1，如果player<10，就重复执行大括号里的内容，并让player的值加1，直到player>=10为止；
——																		（注意：循环结束时，player==11）
——用字母来表示就是：
——对于for(a;b;c)
——	{d}
——执行顺序为a b d c b d c b d c...（直到b不满足为止）；
*/

/*
此外，for循环小括号里的三条语句都可以省略，但是两个分号不可以省略；
如第二个for：

			for (atk < 0; atk < 0;)
			{
				printf("\n我知道你不想攻击我，但也别把玩家1的攻击设置成“%d”啊！\n", atk);

				printf("\n这可是个负数！我不接受治疗！请重新输入：");

				scanf("%d", &atk);
			}

就省略了第三条语句；
*/

/*
同为循环，for和while稍加改动就可以等价互换；
如第二个for：

			for (atk < 0; atk < 0;)
			{
				printf("\n我知道你不想攻击我，但也别把玩家1的攻击设置成“%d”啊！\n", atk);

				printf("\n这可是个负数！我不接受治疗！请重新输入：");

				scanf("%d", &atk);
			}
就和之前的
			while (atk<0)
			{
				printf("\n我知道你不想攻击我，但也别把玩家1的攻击设置成“%d”啊！\n",atk);

				printf("\n这可是个负数！我不接受治疗！请重新输入：");

				scanf("%d", &atk);
			}
完全等价；

值得一提的是，for语句在省略第一条和第三条语句的情况下，单词“for”完全可以被平替为单词“while”；
*/

/*
在有三种循环时，用哪种循环最好呢？
一般遵循以下原则：
如果有固定次数，用for
如果必须执行一次，用do_while
如果必须先进行判断，用while
*/
/*
这里展示一种测试时终端输出的样例：

现在有10名玩家要攻击我;

已知玩家10的攻击为10;

请输入我的血量：-1

你一定是在逗我玩！怎么给我设置“-1”这么一个血量！那我不一碰就si啦！

请重新输入：5

你一定是在逗我玩！怎么给我设置“5”这么一个血量！那我不一碰就si啦！

请重新输入：1000

好的，第1回合开始！

请输入玩家1的攻击:-1

我知道你不想攻击我，但也别把玩家1的攻击设置成“-1”啊！

这可是个负数！我不接受治疗！请重新输入：0

请输入玩家2的攻击:-1

我知道你不想攻击我，但也别把玩家1的攻击设置成“-1”啊！

这可是个负数！我不接受治疗！请重新输入：0

请输入玩家3的攻击:0

请输入玩家4的攻击:0

请输入玩家5的攻击:0

请输入玩家6的攻击:0

请输入玩家7的攻击:0

请输入玩家8的攻击:0

请输入玩家9的攻击:0

OK，本回合我共计受到10点伤害；

我现在还剩下990滴血；

我猜你并没有想攻击我！

thank you very much!

虽然我很不想si掉，但是你一定要过关！

请继续攻击！



第2回合开始！

请输入玩家1的攻击:10

请输入玩家2的攻击:10

请输入玩家3的攻击:10

请输入玩家4的攻击:10

请输入玩家5的攻击:10

请输入玩家6的攻击:10

请输入玩家7的攻击:10

请输入玩家8的攻击:10

请输入玩家9的攻击:10

OK，本回合我共计受到100点伤害；

我现在还剩下890滴血；

我还很健康！感谢您的仁慈！

虽然我很不想si掉，但是你一定要过关！

请继续攻击！



第3回合开始！

请输入玩家1的攻击:4

请输入玩家2的攻击:40

请输入玩家3的攻击:40

请输入玩家4的攻击:50

请输入玩家5的攻击:4

请输入玩家6的攻击:40

请输入玩家7的攻击:50

请输入玩家8的攻击:50

请输入玩家9的攻击:40

OK，本回合我共计受到328点伤害；

我现在还剩下562滴血；

我残血了，但我还活着！

虽然我很不想si掉，但是你一定要过关！

请继续攻击！



第4回合开始！

请输入玩家1的攻击:60

请输入玩家2的攻击:60

请输入玩家3的攻击:60

请输入玩家4的攻击:60

请输入玩家5的攻击:60

请输入玩家6的攻击:60

请输入玩家7的攻击:60

请输入玩家8的攻击:60

请输入玩家9的攻击:20

OK，本回合我共计受到510点伤害；

我现在还剩下52滴血；

哦！真幸运！我猜我再被打一次就si了！

虽然我很不想si掉，但是你一定要过关！

请继续攻击！



第5回合开始！

请输入玩家1的攻击:52

请输入玩家2的攻击:20

请输入玩家3的攻击:20

请输入玩家4的攻击:20

请输入玩家5的攻击:20

请输入玩家6的攻击:20

请输入玩家7的攻击:20

请输入玩家8的攻击:20

请输入玩家9的攻击:20

OK，本回合我共计受到222点伤害；

我现在还剩下...

不！我的血量耗尽了！

啊！我si了！

你只用了5回合就战胜了我；

恭喜过关，再见！/(ㄒoㄒ)/~~
*/