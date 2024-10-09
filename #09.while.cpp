/*
无论是if还是switch函数，编译器都只会读取1次；
当需要多次执行判断时，使用if或switch都会显得非常麻烦；
特别是当不知道判断的次数时，if和switch都会无能为力；
这时，就需要while：循环函数来帮忙；
*/
//如下面的例子，当我们需要攻击多轮且记录“我”被战胜前攻击的回合数时，就需要用到while函数：  
#include <stdio.h>
int main()
{
	int atk1 = 0;
	int atk2 = 0;
	const int ATK3 = 10;
	int originalhp = 0;
	int hp = 0;
	int n = 0;

	printf("现在有3名玩家要攻击我;\n\n已知玩家3的攻击为10;\n\n请输入我的血量：");

	scanf("%d", &originalhp);

	while (originalhp <= 10)
	{
		printf("\n你一定是在逗我玩！怎么给我设置“%d”这么一个血量！那我不一碰就si啦！\n\n请重新输入：", originalhp);

		scanf("%d", &originalhp);
	}

	printf("\n好的，");

	hp = originalhp;

	do
	{
		printf("第%d回合开始！\n", n + 1);

		printf("\n现在我有%d滴血；\n\n",hp);

		printf("请输入玩家1的攻击:");

		scanf("%d", &atk1);

		while (atk1<0)
		{
			printf("\n我知道你不想攻击我，但也别把玩家1的攻击设置成“%d”啊！\n",atk1);

			printf("\n这可是个负数！我不接受治疗！请重新输入：");

			scanf("%d", &atk1);
		}

		printf("\n请输入玩家2的攻击:");

		scanf("%d", &atk2);

		while (atk2 < 0)
		{
			printf("\n我知道你不想攻击我，但也别把玩家2的攻击设置成“%d”啊！\n", atk2);

			printf("\n这可是个负数！我不接受治疗！请重新输入：");

			scanf("%d", &atk2);
		}

		hp = hp - atk1 - atk2 - ATK3;

		printf("\nOK，我现在还剩下");

		int level = hp * 10 / originalhp;

		if (hp >= originalhp - 10)

			printf("%d滴血；\n\n我猜你并没有想攻击我！\n\nthank you very much!\n", hp);

		else if (level >= 6)

			printf("%d滴血；\n\n我还很健康！感谢您的仁慈！\n", hp);

		else if (level >= 1)

			printf("%d滴血；\n\n我残血了，但我还活着！\n", hp);

		else if (hp > 0)

			printf("%d滴血；\n\n哦！真幸运！我猜我再被打一次就si了！\n", hp);
		
		else;
		
		n++;

		if(hp > 0)

			printf("\n虽然我很不想si掉，但是你一定要过关！\n\n请继续攻击！\n\n\n\n");
		
	}while (hp > 0);
			
	printf("...\n\n不！我的血量耗尽了！\n\n啊！我si了！\n");

	printf("\n你只用了%d回合就战胜了我；\n", n);
			
	printf("\n恭喜过关，再见！/(ㄒoㄒ)/~~\n");

	return 0;
}	

/*
while循环包含两个重要组成部分，一是循环条件，二是循环内容；
循环条件指判断是否开始或继续循环的内容，需要在while后面用圆括号括起来，与if类似；
循环内容也与if类似，用大括号括起来；
*/

/*
循环成功搭建后，只要满足循环条件，就会不断的执行循环内容，直到条件不满足为止；
因此，一定要有条件让系统有机会脱离循环，否则就会陷入死循环！
*/

/*
循环分为两种，一种循环条件写在前；另一种写在后面；
第一种：

while (originalhp <= 10)
	{...}

第二种：
do
	{...}
	while (hp > 0);

在必须先判定时，应该用第一种；在必须要执行一次循环时，应该用第二种；
需要注意的是，第二种最后依然需要分号，因为结尾不是大括号，不能成为语句；
*/

/*
先看第一个循环：

while (originalhp <= 10)
	{
		printf("\n你一定是在逗我玩！怎么给我设置“%d”这么一个血量！那我不一碰就si啦！\n\n请重新输入：", originalhp);

		scanf("%d", &originalhp);
	}
	printf("\n好的，");

——如果你没有输入正确的血量，程序就无法继续进行；
——因此设置了这个循环来提醒输错的玩家，并引导他们纠正；
——
——在这个循环中，先判断玩家有没有输对，如果不对，则报错提示玩家正确输入；
——如再次输错，则循环此命令，直到玩家输对为止，再执行下面的程序；
——后面关于atk1和atk2的处理也是如此；
——这里一定要先判断，所以使用第一种循环；
*/

/*
接下来是第二个循环：

	do
	{
		printf("第%d回合开始！\n", n + 1);

		printf("\n现在我有%d滴血；\n\n",hp);

		printf("请输入玩家1的攻击:");

		scanf("%d", &atk1);

		while (atk1<0)
		{
			printf("\n我知道你不想攻击我，但也别把玩家1的攻击设置成“%d”啊！\n",atk1);

			printf("\n这可是个负数！我不接受治疗！请重新输入：");

			scanf("%d", &atk1);
		}

		printf("\n请输入玩家2的攻击:");

		scanf("%d", &atk2);

		while (atk2 < 0)
		{
			printf("\n我知道你不想攻击我，但也别把玩家2的攻击设置成“%d”啊！\n", atk2);

			printf("\n这可是个负数！我不接受治疗！请重新输入：");

			scanf("%d", &atk2);
		}

		hp = hp - atk1 - atk2 - ATK3;

		printf("\nOK，我现在还剩下");

		int level = hp * 10 / originalhp;

		if (hp >= originalhp - 10)

			printf("%d滴血；\n\n我猜你并没有想攻击我！\n\nthank you very much!\n", hp);

		else if (level >= 6)

			printf("%d滴血；\n\n我还很健康！感谢您的仁慈！\n", hp);

		else if (level >= 1)

			printf("%d滴血；\n\n我残血了，但我还活着！\n", hp);

		else if (hp > 0)

			printf("%d滴血；\n\n哦！真幸运！我猜我再被打一次就si了！\n", hp);

		else;
		
		n++;

		if(hp > 0)

			printf("\n虽然我很不想si掉，但是你一定要过关！\n\n请继续攻击！\n\n\n\n");

	}while (hp > 0);
——1.先输入玩家1和2的攻击，必须为正，否则报错；
——2.根据玩家123的攻击计算玩家的剩余血量；
——3.输出“我”的剩余血量，并根据“我”的剩余血量来触发对话内容；
——	（这里没有用switch而选择if else级联的原因是switch函数不好对hp=0的情况进行判定）
——4.回合数+1；
——5.若hp>0，提示玩家继续攻击，并重复1-4步骤；直到hp<=0为止；
——6.结束循环；
——
——这里一定要进行第一回合，所以使用第二种循环；
*/

/*

	printf("...\n\n不！我的血量耗尽了！\n\n啊！我si了！\n");

	printf("\n你只用了%d回合就战胜了我；\n", n);

	printf("\n恭喜过关，再见！/(ㄒoㄒ)/~~\n");

——结算阶段，不完成上面的循环无法执行最后的结算代码；
——用printf输出回合数；
*/

/*
这里展示一种测试时终端输出的样例：


		现在有3名玩家要攻击我;

		已知玩家3的攻击为10;

		请输入我的血量：-1

		你一定是在逗我玩！怎么给我设置“-1”这么一个血量！那我不一碰就si啦！

		请重新输入：5

		你一定是在逗我玩！怎么给我设置“5”这么一个血量！那我不一碰就si啦！

		请重新输入：100

		好的，第1回合开始！

		现在我有100滴血；

		请输入玩家1的攻击:-1

		我知道你不想攻击我，但也别把玩家1的攻击设置成“-1”啊！

		这可是个负数！我不接受治疗！请重新输入：0

		请输入玩家2的攻击:-1

		我知道你不想攻击我，但也别把玩家2的攻击设置成“-1”啊！

		这可是个负数！我不接受治疗！请重新输入：0

		OK，我现在还剩下90滴血；

		我猜你并没有想攻击我！

		thank you very much!

		虽然我很不想si掉，但是你一定要过关！

		请继续攻击！



		第2回合开始！

		现在我有90滴血；

		请输入玩家1的攻击:5

		请输入玩家2的攻击:5

		OK，我现在还剩下70滴血；

		我还很健康！感谢您的仁慈！

		虽然我很不想si掉，但是你一定要过关！

		请继续攻击！



		第3回合开始！

		现在我有70滴血；

		请输入玩家1的攻击:10

		请输入玩家2的攻击:10

		OK，我现在还剩下40滴血；

		我残血了，但我还活着！

		虽然我很不想si掉，但是你一定要过关！

		请继续攻击！



		第4回合开始！

		现在我有40滴血；

		请输入玩家1的攻击:10

		请输入玩家2的攻击:15

		OK，我现在还剩下5滴血；

		哦！真幸运！我猜我再被打一次就si了！

		虽然我很不想si掉，但是你一定要过关！

		请继续攻击！



		第5回合开始！

		现在我有5滴血；

		请输入玩家1的攻击:10

		请输入玩家2的攻击:10

		OK，我现在还剩下...

		不！我的血量耗尽了！

		啊！我si了！

		你只用了5回合就战胜了我；

		恭喜过关，再见！/(ㄒoㄒ)/~~
*/