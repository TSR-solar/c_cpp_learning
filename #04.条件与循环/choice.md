在这一章里面，你将化身数个玩家来攻击**solxr**。  
为了更好的**折磨solxr**，你需要设计一些程序，来模拟**solxr**的**痛苦**；  
可是，在你设计程序的时候，却在面对**选择**和**循环**时无从下手；  
幸运的是，你找到了下面这个教程，来帮助你快速掌握**选择**与**循环**的相应知识；

## if/else : 条件判断
编程不能仅限于输入输出，有时还要判断。  
if函数就是用来**做判断**的；  
一个基本的if语句由一个关键字if开头，跟上在圆括号()里的一个表达条件的逻辑表达式；  
然后是一对大括号{}之间的若干条语句；  
具体怎样发挥作用，看下面的例子：(if.c)  
```c
#include <stdio.h>
int main()
{
	int atk1 = 0;
	int atk2 = 0;
	const int ATK3 = 10;
	const int DEATH = 0;
	int originalhp = 100;

	printf("I have 100 hp now.\nThere have 3 players that will attack me.\nWe have known player3's attack is 10.\n");
	printf("input player1's attack:");
	scanf("%d", &atk1 );
	printf("input player2's attack:");
	scanf("%d", &atk2 );

	int hp = originalhp - atk1 - atk2 - ATK3;

	if (hp> DEATH)
	{
		printf("OK,Now I only have %d-%d-%d-%d=%d hp.\n", originalhp, atk1, atk2, ATK3, hp);
		printf("Fantastic! I'm still ALIVE!\n");
	}
	else
	{
		printf("OK,Now I only have %d-%d-%d-%d=...\n", originalhp, atk1, atk2, ATK3);
		printf("No!!My hp come to the bottom!\nOops!I DEAD!\n");
	}

	if (hp <= 0)
	{
		printf("Congratulation to your success!Goodbye!!\n");
	}
	return 0;
}
```
输入样例1：
>10  
20

输出结果1：
>OK,Now I only have 100-10-20-10=60 hp.  
Fantastic! I'm still ALIVE!

输入样例2：
>50  
90

输出结果：
>OK,Now I only have 100-50-90-10=...  
No!!My hp come to the bottom!  
Oops! I DIED!  
Congratulation to your success! Goodbye!!

```c
if (hp> DEATH)
{
	printf("OK,Now I only have %d-%d-%d-%d=%d hp.\n", originalhp, atk1, atk2, ATK3, hp);
	printf("Fantastic! I'm still ALIVE!\n");
}
else
{
	printf("OK,Now I only have %d-%d-%d-%d=...\n", originalhp, atk1, atk2, ATK3);
	printf("No!!My hp come to the bottom!\nOops!I DEAD!\n");
}

if (hp <= 0)
{
	printf("Congratulation to your success!Goodbye!!\n");
}
```
if函数如果**条件为真**，则执行大括号里的语句，**否则跳过**，继续执行下面的语句；  
但如果if函数后面**出现了else**，则若不满足条件，就会执行**else大括号里的语句**，保证不会出现遗漏条件的情况；

>如上面的if函数，若hp <= 0，会输出死亡对话；否则输出存活对话；
而下面的if函数，如hp > 0，则无事发生；

## switch/case : 条件选择
if和else之间可以**嵌套使用**，形成形如下面的代码：
```c
if()
{...}
else if()
{...}
else if()
{...}
.
.
.
else
{...}
```

当需要进行多次判断时，常用嵌套的if-else函数来解决；   
但这样做有个坏处，就是会由于多个if的存在使得代码显得非常**杂乱**，还容易出错；  
这时，就可以使用switch函数来解决问题；
如下面的例子：使用switch函数来判定solxr的血量范围，进而输出对应的对话；(switch.c)
```c
#include <stdio.h>
int main()
{
	int atk1 = 0;
	int atk2 = 0;
	const int ATK3 = 10;
	int originalhp = 100;

	printf("I have 100 hp now.\nThere have 3 players that will attack me.\nWe have known player3's attack is 10.\n");
	printf("input player1's attack:");
	scanf("%d", &atk1 );
	printf("input player2's attack:");
	scanf("%d", &atk2 );

	int hp = originalhp - atk1 - atk2 - ATK3;

	int level = hp / 10;

	printf("OK,Now I only have %d-%d-%d-%d=", originalhp, atk1, atk2, ATK3);
	switch (level)
	{
	case 9:printf("%d hp;\nI guess you didn't want to hurt me.\nthank you very much!\n", hp); break;
	case 8:case 7:case 6:printf("%d hp;\nMy hp is still high now!\nThanks for your mercy!\n", hp); break;
	case 5:case 4:case 3:case 2:printf("%d hp.\nIt's really hurt... But I'm still alive!\n", hp); break;
	case 1:case 0:printf("%d hp;\nGood! I think I'm so lucky that I made it with such few hp!\n", hp); break;
	default:
		printf("...No!!My hp come to the bottom!\nOops!I DIED!\n");
		printf("Congratulation to your success! Goodbye!!\n");
		break;
	}
	
	return 0;
}
```
输入样例1：
>0  
0


输出结果1：
>OK,Now I only have 100-0-0-10=90 hp;  
I guess you didn't want to hurt me.  
thank you very much!

输入样例2：
>5  
10

输出结果2：
>OK,Now I only have 100-5-10-10=75 hp;  
My hp is still high now!  
Thanks for your mercy!

输入样例3：
>30  
30

输出结果3：
>OK,Now I only have 100-30-30-10=30 hp.  
It's really hurt... But I'm still alive!

输入样例4：
>50  
45

输出结果4：
>OK,Now I only have 100-50-45-10=-5 hp;  
Good! I think I'm so lucky that I made it with such few hp!

输入样例5：
>100  
200

输出结果5：
>OK,Now I only have 100-100-200-10=...No!! My hp come to the bottom!  
Oops!I DIED!  
Congratulation to your success! Goodbye!!

这里要根据“我”的剩余血量来触发对话内容，有多个判定节点；  
因此如果要用if函数，就必须要嵌套；  
下面是一种可能的例子：

```c
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
```

这样写，编译器必须从上读到下，而且我们也难以第一时间读懂代码想表达什么；  
因此，这时，就可以使用**switch函数**来解决问题，这时编译器只需读取一种情况就可以了；

```c
switch (level)
{
case 9:printf("%d hp;\nI guess you didn't want to hurt me.\nthank you very much!\n", hp); break;
case 8:case 7:case 6:printf("%d hp;\nMy hp is still high now!\nThanks for your mercy!\n", hp); break;
case 5:case 4:case 3:case 2:printf("%d hp.\nIt's really hurt... But I'm still alive!\n", hp); break;
case 1:case 0:printf("%d hp;\nGood! I think I'm so lucky that I made it with such few hp!\n", hp); break;
default:
    printf("No!!My hp come to the bottom!\nOops!I DIED!\n");
    printf("Congratulation to your success! Goodbye!!\n");
    break;
}
```
	
switch函数由**switch** 和 **case** **default** 组成；  
与if一致，switch函数也需要圆括号() ，它会检测圆括号里面的变量数值来执行case里面的内容；  
注：case里面的数必须是正整数，这是switch相对于if的**局限性**；

对于此代码，我们可以将100种hp换算为10种level，用hp/10就可以了！  
不然，要我写100个case，还不如用if函数！

case后面也要加大括号{}；  
想要表示一种情况，case和数之间要加空格，之后要有冒号:  
在冒号后面加上想要添加的代码，满足case后就可以执行以下的代码内容；

在每种case最后，要加上 **break;**  
否则就会**直接执行**下一个case里面的内容；  
不过，也可以利用这个特性，**合并多种case**，使它们执行相同的内容；
>如上面就将case01；case2345；case678合并了；

在switch函数的最后，还有一个东西，就是**default**；    
当条件**都不满足**case时，执行default里面的内容；  
如果你保证switch函数的所有条件都在你的case里面，**可以不写**default；  
**不然，忘记写了你就等着报错吧！**

小技巧：如果想要使用switch函数，但又**没有正整数**，可以尝试将其化为正整数；  
如利用**关系运算符**输出的结果**只有0和1**，把区间化为整数；