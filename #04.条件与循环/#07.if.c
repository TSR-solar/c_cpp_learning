/*
编程不能仅限于输入输出，有时还要判断。
if函数就是用来做判断的；
一个基本的if语句由一个关键字if开头，跟上在圆括号里的一个表达条件的逻辑表达式；
然后是一对大括号之间的若干条语句；
*/
//具体怎样发挥作用，看下面的例子：
#include <stdio.h>
int main()
{
	int atk1 = 0;
	int atk2 = 0;
	const int ATK3 = 10;
	const int DEATH = 0;
	int originalhp = 100;

	printf("我现在有100滴血;\n\n现在有3名玩家要攻击我;\n\n已知玩家3的攻击为10;\n\n");

	printf("请输入玩家1的攻击:");

	scanf("%d", &atk1);

	printf("\n请输入玩家2的攻击:");

	scanf("%d", &atk2);

	int hp = originalhp - atk1 - atk2 - ATK3;

	if (hp> DEATH)
	{
		printf("\nOK，我现在还剩下%d-%d-%d-%d=%d滴血\n", originalhp, atk1, atk2, ATK3, hp);
		printf("\n好！我还没死！\n");
	}
	else
	{
		printf("\nOK，我现在还剩下%d-%d-%d-%d=...\n", originalhp, atk1, atk2, ATK3);
		printf("\n不！我的血量耗尽了！\n\n啊！我si了！\n");
	}

	if (hp <= 0)
	{
		printf("\n恭喜过关，再见！/(ㄒoㄒ)/~~\n");
	}
	return 0;
}

/*
if (hp>0)
	{
		printf("\nOK，我现在还剩下%d-%d-%d-%d=%d滴血\n", originalhp, atk1, atk2, ATK3, hp);
		printf("\n好！我还没死！\n");
	}
	else
	{
		printf("\nOK，我现在还剩下%d-%d-%d-%d=...\n", originalhp, atk1, atk2, ATK3);
		printf("\n不！我的血量耗尽了！\n\n啊！我si了！");
	}

	if (hp <= 0)
	{
		printf("\n恭喜过关，再见！/(ㄒoㄒ)/~~\n");
	}
——if函数如果条件为真，则执行大括号里的语句，否则跳过，继续执行下面的语句；
——但如果if函数后面出现了else，则若不满足条件，就会执行else大括号里的语句；
——
——如上面的if函数，若hp <= 0，会输出：
——
——									OK，我现在还剩下%d-%d-%d-%d=...
——
——									不！我的血量耗尽了！
——
——									啊！我si了！
——
——而下面的if函数，如hp > 0，则无事发生；
*/

/*
if函数离不开的就是关系运算符；以下是常见的关系运算符：
优先级         运算符         运算         结合关系
  6				 >            大于		   从左向右
  6				 >=		   大于或等于	   从左向右
  6				 <			  小于		   从左向右
  6				 <=		   小于或等于	   从左向右
  7				 ==		      等于		   从左向右
  7				 !=			 不等于		   从左向右
——当关系运算符所在的关系式为真时，输出1，反之输出0；
——实际上，if函数正是通过检验括号内是否0来决定要不要进行下面的内容的；

——注意：仍然遵循从左至右的结合关系；
——例如 5>4>3==1>3==0;

——但 5>3==4>2 却是另一种算法，因为等于和不等于的优先级略低；
——因此 5>3==4>2 等价于 1==1 ；
*/