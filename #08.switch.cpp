/*
当需要进行多次判断时，常用嵌套的if函数来解决；
但这样做有个坏处，就是会由于多个if的存在使得代码显得非常杂乱，还容易出错；
这时，就可以使用switch函数来解决问题；
*/
//如下面的例子：
#include <stdio.h>
int main()
{
	int atk1 = 0;
	int atk2 = 0;
	const int ATK3 = 10;
	int originalhp = 100;

	printf("我现在有100滴血;\n\n现在有3名玩家要攻击我;\n\n已知玩家3的攻击为10;\n\n");

	printf("请输入玩家1的攻击:");

	scanf("%d", &atk1);

	printf("\n请输入玩家2的攻击:");

	scanf("%d", &atk2);

	int hp = originalhp - atk1 - atk2 - ATK3;

	int level = hp / 10;

	printf("\nOK，我现在还剩下%d-%d-%d-%d=", originalhp, atk1, atk2, ATK3);
	if (hp <= 0)
	{
		printf("...\n\n不！我的血量耗尽了！\n\n啊！我si了！\n");

		printf("\n恭喜过关，再见！/(ㄒoㄒ)/~~\n");
	}
	else
	switch (level)
	{
	case 9:printf("%d滴血；\n\n我猜你并没有想攻击我！\n\nthank you very much!\n", hp); break;

	case 8:case 7:case 6:printf("%d滴血；\n\n我还很健康！感谢您的仁慈！\n", hp); break;

	case 5:case 4:case 3:case 2:printf("%d滴血；\n\n我残血了，但我还活着！\n", hp); break;

	case 1:case 0:printf("%d滴血；\n\n哦！真幸运！我猜我再被打一次就si了！\n", hp); break;

	default:printf("...\n\n不！我的血量耗尽了！\n\n啊！我si了！\n");

		printf("\n恭喜过关，再见！/(ㄒoㄒ)/~~\n");

		break;
	}
	
	return 0;
}
/*
这里要根据“我”的剩余血量来触发对话内容，有多个判定节点；
因此如果要用if函数，就必须要嵌套；
*/
/*下面是一种可能的例子：

if(hp>=90)
{...}
else if(hp>=60)
{...}
else if(hp>=20)
{...}
else if(hp>0)
{...}
else
{...}
*/

/*
这样写，编译器必须从上读到下，而且我们也难以第一时间读懂代码想表达什么；
因此，这时，就可以使用switch函数来解决问题，这时编译器只需读取一种情况就可以了；
*/

/*

switch (level)
	{
	case 9:printf("%d滴血；\n\n我猜你并没有想攻击我！\n\nthank you very much!\n", hp); break;

	case 8:case 7:case 6:printf("%d滴血；\n\n我还很健康！感谢您的仁慈！\n", hp); break;

	case 5:case 4:case 3:case 2:printf("%d滴血；\n\n我残血了，但我还活着！\n", hp); break;

	case 1:case 0:printf("%d滴血；\n\n哦！真幸运！我猜我再被打一次就si了！\n", hp); break;

	default:printf("...\n\n不！我的血量耗尽了！\n\n啊！我si了！\n"); break;
	}
	
——switch函数由switch 和 case default组成；
——与if一致，switch函数也需要圆括号，它会检测圆括号里面的变量数值来执行case里面的内容；
——注：case里面的数必须是正整数，这是switch相对于if的局限性；
——
——对于此代码，我们可以将100种hp换算为10种level，用hp/10就可以了！
——不然，要我写100个case，还不如用if函数！
——
——case后面也要加大括号；
——想要表示一种情况，case和数之间要加空格，之后要有冒号；
——在冒号后面加上想要添加的代码，满足case后就可以执行以下的代码内容；
——
——在每种case最后，要加上 break; ，否则就会直接执行下一个case里面的内容；
——不过，也可以利用这个特性，合并多种case，使它们执行相同的内容；
——如上面就将case01；case2345；case678合并了；
——
——在switch函数的最后，还有一个必不可少的东西，就是default；
——当条件都不满足case时，执行default里面的内容；
*/

/*
小技巧：如果想要使用switch函数，但又没有正整数，可以尝试将其化为正整数；
如利用关系运算符输出的结果只有0和1，把区间化为整数；
*/