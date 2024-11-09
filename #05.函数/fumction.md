在此之前，我们已经知道了printf、scanf、if、while、for等函数；  
然而，这些函数的定义是库函数里面本来就有的；  
如果要创造一个自己定义的函数，该怎么做呢？  
具体看下面的例子：(function.c)  
```c
#include <stdio.h>
int sumatk(int hp);//函数声明

void judge(int hp, int originalhp);
//函数声明，void表示无返回值

int main()
{
	int originalhp,hp,n=0;
	const int ATK10 = 10;

	printf("There have 10 players that will attack me.\nWe have known player3's attack is 10.\n\ninput my hp:");
	scanf("%d", &originalhp);
	while (originalhp <= 10)
	{
		printf("You're kidding me absolutely! I can't live with the hp of %d!!\nPlease input it again:", originalhp);

		scanf("%d", &originalhp);
	}
	printf("OK;I have %d hp now.\n",originalhp);
	hp = originalhp;
	do
	{
		printf("Round %d begin!\n", n + 1);
		int sum = sumatk(hp)+ATK10;
        //调用sumatk函数，返回的值再参与到sum的计算中；
		hp -= sum;
		printf("OK;You hurt me with the sum of %d attack in this round;\nNow I only have",sumatk);
		judge(hp, originalhp);
        //调用judge函数，根据两个变量打印结果，不返回值；
		n++;
		if (hp > 0)
		printf("Although I don't want to die now,but I must help you succeed!\nKeep attacking!\n\n");
	} while (hp > 0);
	printf("...No!!My hp come to the bottom!\nOops!I DIED!\n");
	printf("You only take %d round(s) to defeat me!!\n", n);	
	printf("Congratulation to your success! Goodbye!!\n");
	return 0;
}
//sumatk函数的定义，其中sunatk里面的hp、player等变量一旦离开作用域，内存即被释放，变量不复存在；
int sumatk(int hp)
{
	int sumatk=0, player, atk;
	for (player = 1; player <= 9; player++)
	{
		printf("input player%d's attack:",player);
		scanf("%d", &atk );
		for(;atk<0;)
		{
			printf("I know you don't want to hurt me,but now the attack %d is too ABNORMAL!\n",atk);
			printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
			scanf("%d", &atk);
		}
		sumatk += atk;
	}
	return sumatk;
}

//judge函数的定义
void judge(int hp, int originalhp)
{
	int level = hp * 10 / originalhp;
	if (hp >= originalhp - 10)
		printf(" %d hp;\nI guess you didn't want to hurt me.\nthank you very much!\n", hp);
		else if (level >= 6)
		printf(" %d hp;\nMy hp is still high now!\nThanks for your mercy!\n", hp);
		else if (level >= 1)
		printf(" %d hp.\nIt's really hurt... But I'm still alive!\n", hp);
		else if (hp > 0)
		printf(" %d hp;\nGood! I think I'm so lucky that I made it with such few hp!\n", hp);
}
//可以无return语句或加上无返回值的 (return;) 语句
```
函数一般由**声明**，**定义**组成；  

**声明**要讲出函数的返回类型和输入类型，必须写在主程序前，格式如下：  
>返回类型 函数名(输入类型若干)

其中返回类型与变量类型相似，可以填int、double等；  
那么在函数的最后，就要使用**return语句**返回一个值给主程序，它的类型就是返回类型；  
但有一种返回类型例外，它就是**void**，它代表“没有”，用void做返回类型不需要return语句返回值；  
但是也可以使用不加返回值的`return;`来结束函数运行；  

>注意：任何函数**最多只能返回1个值**，因为函数的自变量只能有唯一的因变量对应；  

输入类型指主程序向函数传递的若干值，与定义变量类似；
输入类型仍然可以是void，这时主程序无需向函数输入任何值；

>如   `void judge(int hp, int originalhp)`  
就是声明一个函数名为judge的函数，主程序将向其传递2个值，它们将会依次定义给变量hp和originalhp，最终不返回任何值；

声明最后要**加上分号**；

函数的**定义**则是指在函数内部利用输入的变量进行的一系列代码；  
其第一行必须是函数的声明，因此可以将函数的定义和声明写在一起；  
但一般不这么做，因为把定义放在后面显得代码更加**模块化**；  
之后用大括号括起要执行的代码，构成定义；
>注意：函数禁止嵌套定义，会出现非常严重的错误；  
但允许嵌套调用，甚至自己调用自己，我们称之为**递归**；

函数与main函数以及函数与函数之间是完全**不相干**的，它们只以互相输入的值来联系 *(指值传递的函数，**地址传递不算**)* ；  
这就是说，你可以在主程序和函数中定义两个**完全相同**的变量，但它们是互不影响的；  
函数中的变量有自己的起作用范围，就是在大括号里面，我们管它叫**作用域**；  
一旦离开了作用域，变量就会**不复存在**，直到下一次调用该函数时才会出现；

在**调用**函数时，无需输入函数类型，只要输入函数名，后面跟小括号输入要传递的若干个值即可；

>值得注意的是，main也是函数；  
因为计算机内部的一些计算，main函数也要返回值，所以int main返回0；  
如果函数发生了非零返回，很可能是出现了错误，故 `return 0;` 是代码正常运行的重要标志；   
在小括号里面，本可以放进去void，然而由于种种原因，还是不加为好；  