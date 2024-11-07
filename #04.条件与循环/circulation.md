## while/do-while ：循环操作
无论是if还是switch函数，编译器都**只会读取1次**；  
当需要多次执行判断时，使用if或switch都会显得**非常麻烦**；  
特别是当**不知道判断的次数**时，if和switch都会**无能为力**；  
这时，就需要**while：循环函数**来帮忙；  
如下面的例子，当我们需要攻击多轮且记录solxr被战胜前攻击的回合数时，就需要用到while函数：(while.c)
```c
#include <stdio.h>
int main()
{
	int atk1 = 0;
	int atk2 = 0;
	const int ATK3 = 10;
	int originalhp = 0;
	int hp = 0;
	int n = 0;

	printf("There have 3 players that will attack me.\nWe have known player3's attack is 10.\n\ninput my hp:");
	scanf("%d", &originalhp);
	while (originalhp <= 10)
	{
		printf("You're kidding me absolutely! I can't live with the hp of %d!!\nPlease input it again:", originalhp);

		scanf("%d", &originalhp);
	}
	printf("OK;\n");

	hp = originalhp;
	do
	{
		printf("Round %d begin!\n", n + 1);
		printf("I have 100 hp now.\n",hp);

		printf("input player1's attack:");
		scanf("%d", &atk1 );
		while (atk1<0)
		{
			printf("I know you don't want to hurt me,but now the attack %d is too ABNORMAL!\n",atk1);
			printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
			scanf("%d", &atk1);
		}

		printf("input player2's attack:");
		scanf("%d", &atk2 );
		while (atk2<0)
		{
			printf("I know you don't want to hurt me,but now the attack %d is too ABNORMAL!\n",atk2);
			printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
			scanf("%d", &atk2);
		}

		hp = hp - atk1 - atk2 - ATK3;
		printf("OK;Now I only have");
		int level = hp * 10 / originalhp;

		if (hp >= originalhp - 10)
		printf(" %d hp;\nI guess you didn't want to hurt me.\nthank you very much!\n", hp);
		else if (level >= 6)
		printf(" %d hp;\nMy hp is still high now!\nThanks for your mercy!\n", hp);
		else if (level >= 1)
		printf(" %d hp.\nIt's really hurt... But I'm still alive!\n", hp);
		else if (hp > 0)
		printf(" %d hp;\nGood! I think I'm so lucky that I made it with such few hp!\n", hp);
		
		n++;

		if(hp > 0)
		printf("Although I don't want to die now,but I must help you succeed!\nKeep attacking!\n\n");
	
	}while (hp > 0);
			
	printf("...No!!My hp come to the bottom!\nOops!I DIED!\n");
	printf("You only take %d round(s) to defeat me!!\n", n);	
	printf("Congratulation to your success! Goodbye!!\n");
	return 0;
}	
```

while循环包含两个重要组成部分，一是**循环条件**，二是**循环内容**；  
循环条件指判断是否开始或继续循环的内容，需要在while后面用圆括号()括起来，与if类似；  
循环内容也与if类似，用大括号{}括起来；

循环成功搭建后，只要满足循环条件，就会**不断的执行**循环内容，直到条件不满足为止；
因此，一定要有条件让系统**有机会脱离循环**，否则就会陷入**死循环**！

while循环分为两种，一种循环条件写在前；另一种写在后面；  
第一种：

```c
while (...)  
{...}
```

第二种：
```c
do  
{...}  
while (...);
```

在**必须先判定**时，应该用第一种；在**必须要执行一次循环**时，应该用第二种；
需要注意的是，第二种最后**依然需要分号**，因为结尾不是大括号，**不能成为语句**；

先看第一个循环：
```c
while (originalhp <= 10)
{
    printf("You're kidding me absolutely! I can't live with the hp of %d!!\nPlease input it again:", originalhp);

    scanf("%d", &originalhp);
}
printf("OK;\n");
```

如果你没有输入正确的血量，程序就无法继续正常进行；  
因此设置了这个循环来提醒输错的玩家，并引导他们纠正；

在这个循环中，先判断玩家有没有输对，如果不对，则报错提示玩家正确输入；  
如再次输错，则循环此命令，**直到玩家输对为止**，再执行下面的程序；
后面关于atk1和atk2的处理也是如此；

这里一定要先判断，所以使用第一种循环；

接下来是第二个循环：

```c
do
{
    printf("Round %d begin!\n", n + 1);
    printf("I have %d hp now.\n",hp);

    printf("input player1's attack:");
    scanf("%d", &atk1 );
    while (atk1<0)
    {
        printf("I know you don't want to hurt me,but now the attack is too ABNORMAL!\n",atk1);
        printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
        scanf("%d", &atk1);
    }

    printf("input player2's attack:");
    scanf("%d", &atk2 );
    while (atk2<0)
    {
        printf("I know you don't want to hurt me,but now the attack is too ABNORMAL!\n",atk2);
        printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
        scanf("%d", &atk2);
    }

    hp = hp - atk1 - atk2 - ATK3;
    printf("\nNow I only have");
    int level = hp * 10 / originalhp;

    if (hp >= originalhp - 10)
    printf(" %d hp;\nI guess you didn't want to hurt me.\nthank you very much!\n", hp);
    else if (level >= 6)
    printf("%d hp;\nMy hp is still high now!\nThanks for your mercy!\n", hp);
    else if (level >= 1)
    printf("%d hp.\nIt's really hurt... But I'm still alive!\n", hp);
    else if (hp > 0)
    printf("%d hp;\nGood! I think I'm so lucky that I made it with such few hp!\n", hp);
    
    n++;

    if(hp > 0)
    printf("Although I don't want to die now,but I must help you succeed!\nKeep attacking!\n\n");

}while (hp > 0);
```
1.先输入玩家1和2的攻击，必须为正，否则报错；  
2.根据玩家123的攻击计算玩家的剩余血量；  
3.输出“我”的剩余血量，并根据“我”的剩余血量来触发对话内容；  
>（这里没有用switch而选择if else级联的原因是switch函数不好对hp=0的情况进行判定）

4.回合数+1；  
5.若hp>0，提示玩家继续攻击，并**重复1-4步骤**；直到hp<=0为止；  
6.结束循环；

这里一定要进行第一回合，所以使用第二种循环；

```c
printf("...No!!My hp come to the bottom!\nOops!I DIED!\n");
printf("You only take %d round(s) to defeat me!!\n", n);	
printf("Congratulation to your success! Goodbye!!\n");
```

结算阶段，不完成上面的循环无法执行最后的结算代码；  
用printf输出回合数；

这里展示一种测试时终端输出的样例：

> There have 3 players that will attack me.  
> We have known player3's attack is 10.
>
> input my hp:*-1*   
> You're kidding me absolutely! I can't live with the hp of -1!!  
> Please input it again:*5*  
> You're kidding me absolutely! I can't live with the hp of 5!!  
> Please input it again:*100*  
> OK;  
> Round 1 begin!  
> I have 100 hp now.  
> input player1's attack:*-1*  
> I know you don't want to hurt me,but now the attack -1 is too ABNORMAL!  
> If you input this atk,it means you want to heal me!I refuse it!!  
> Please input it again:*0*  
> input player2's attack:*-1*  
> I know you don't want to hurt me,but now the attack -1 is too ABNORMAL!  
> If you input this atk,it means you want to heal me!I refuse it!!    
> Please input it again:*0*    
> OK;Now I only have 90 hp;  
> I guess you didn't want to hurt me.  
> thank you very much!  
> Although I don't want to die now,but I must help you succeed!  
> Keep attacking!  
>
> Round 2 begin!  
> I have 100 hp now.  
> input player1's attack:*5*  
> input player2's attack:*5*  
> OK;Now I only have 70 hp;  
> My hp is still high now!  
> Thanks for your mercy!  
> Although I don't want to die now,but I must help you succeed!  
> Keep attacking!  
>
> Round 3 begin!  
> I have 100 hp now.  
> input player1's attack:*10*  
> input player2's attack:*10*  
> OK;Now I only have 40 hp.  
> It's really hurt... But I'm still alive!  
> Although I don't want to die now,but I must help you succeed!  
> Keep attacking!  
>
> Round 4 begin!  
> I have 100 hp now.  
> input player1's attack:*10*  
> input player2's attack:*15*  
> OK;Now I only have 5 hp;  
> Good! I think I'm so lucky that I made it with such few hp!  
> Although I don't want to die now,but I must help you succeed!  
> Keep attacking!  
>
> Round 5 begin!  
> I have 100 hp now.  
> input player1's attack:*10*  
> input player2's attack:*10*  
> OK;Now I only have...No!!My hp come to the bottom!
> Oops!I DIED!  
> You only take 5 round(s) to defeat me!!  
> Congratulation to your success! Goodbye!!  

## for : 循环计数器
在C语言中，除了while循环和do-while循环，还存在第三种循环，即for循环；  
作为最早的循环，for循环结构简单，也更难被理解；  
以下就是一个使用for循环的例子(for.c)：

```c
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

	printf("There have 10 players that will attack me.\nWe have known player3's attack is 10.\n\ninput my hp:");
	scanf("%d", &originalhp);
	while (originalhp <= 10)
	{
		printf("You're kidding me absolutely! I can't live with the hp of %d!!\nPlease input it again:", originalhp);

		scanf("%d", &originalhp);
	}
	printf("OK;\n");

	hp = originalhp;

	do
	{
		printf("Round %d begin!\n", n + 1);
		printf("I have %d hp now.\n",hp);
		sumatk = 0;
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
		sumatk += ATK10;
		hp -= sumatk;
		printf("OK;You hurt me with the sum of %d attack in this round;\nNow I only have",sumatk);
		int level = hp * 10 / originalhp;
		
		if (hp >= originalhp - 10)
		printf(" %d hp;\nI guess you didn't want to hurt me.\nthank you very much!\n", hp);
		else if (level >= 6)
		printf(" %d hp;\nMy hp is still high now!\nThanks for your mercy!\n", hp);
		else if (level >= 1)
		printf(" %d hp.\nIt's really hurt... But I'm still alive!\n", hp);
		else if (hp > 0)
		printf(" %d hp;\nGood! I think I'm so lucky that I made it with such few hp!\n", hp);
		n++;

		if(hp > 0)
		printf("Although I don't want to die now,but I must help you succeed!\nKeep attacking!\n\n");
	} while (hp > 0);

	printf("...No!!My hp come to the bottom!\nOops!I DIED!\n");
	printf("You only take %d round(s) to defeat me!!\n", n);	
	printf("Congratulation to your success! Goodbye!!\n");
	return 0;
}
```
如果把玩家人数提升到10位，使用for循环就会显得比while循环更加方便与简洁；

```c
for (player = 1; player <= 9; player++)
{
    printf("input player%d's attack:",player);
    scanf("%d", &atk );
    while (atk<0)
    {
        printf("I know you don't want to hurt me,but now the attack %d is too ABNORMAL!\n",atk);
        printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
        scanf("%d", &atk);
    }
    sumatk += atk;
}
```
for循环在形式上与其它判断语句类似，也是由小括号()和大括号{}组成；  
但不同的是，for循环的小括号里面有3条语句，中间用两个分号隔开；  
即:  
```c
for(a;b;c)
{d}
```
三条语句分别代表**初始动作**，**循环继续的条件**和**每次循环结束做的动作**；  
大括号里和其它循环相同，都用来做**每次循环中做的动作**；  
例如第一个for，它的流程如下：
1.初始化player的值为1；  
2.判定player的值是否大于10，若大于，则继续进行下面的步骤，反之直接结束循环；  
3.执行大括号内的代码；  
4.让player的值加1，以便输入下一名玩家的攻击；  
5.**重复2-4步骤**；

为了理解方便，可将for翻译为“对于”；
这样，for循环的流程可以理解为：
>对于 一开始的player=1，如果player<10，就重复执行大括号里的内容，并让player的值加1，直到player>=10为止；

（注意：循环结束时，**player==11**）  
用字母来表示就是：
>对于  
for(a;b;c)  
{d}  
执行顺序为a b d c b d c b d c...（**直到b不满足为止**）；

此外，for循环小括号里的**三条语句都可以省略**，但是**两个分号不可以省略**；
如第二个for：

```c
for(;atk<0;)
{
    printf("I know you don't want to hurt me,but now the attack %d is too ABNORMAL!\n",atk);
    printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
    scanf("%d", &atk);
}
```

就省略了第一条和第三条语句；

同为循环，for和while稍加改动就可以等价互换；  
如第二个for：
```c
for(;atk<0;)
{
    printf("I know you don't want to hurt me,but now the attack %d is too ABNORMAL!\n",atk);
    printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
    scanf("%d", &atk);
}
```
就和之前的
```c
while(;atk<0;)
{
    printf("I know you don't want to hurt me,but now the attack %d is too ABNORMAL!\n",atk);
    printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
    scanf("%d", &atk);
}
```
**完全等价**；

值得一提的是，for语句在省略第一条和第三条语句的情况下，单词“for”完全可以被平替为单词“while”；

在有三种循环时，用哪种循环最好呢？  
一般遵循以下原则：  
如果**有固定次数**，用for  
如果**必须执行一次**，用do_while  
如果**必须先进行判断**，用while  

这里展示一种测试时终端输出的样例：

> There have 10 players that will attack me.  
> We have known player3's attack is 10.  
>  
> input my hp:*-1*  
> You're kidding me absolutely! I can't live with the hp of -1!!  
> Please input it again:*5*  
> You're kidding me absolutely! I can't live with the hp of 5!!  
> Please input it again:*1000*  
> OK;  
> Round 1 begin!  
> I have 1000 hp now.  
> input player1's attack:*-1*  
> I know you don't want to hurt me,but now the attack -1 is too ABNORMAL!  
> If you input this atk,it means you want to heal me!I refuse it!!  
> Please input it again:*0*  
> input player2's attack:*-1*  
> I know you don't want to hurt me,but now the attack -1 is too ABNORMAL!  
> If you input this atk,it means you want to heal me!I refuse it!!  
> Please input it again:*0*  
> input player3's attack:*0*  
> input player4's attack:*0*  
> input player5's attack:*0*  
> input player6's attack:*0*   
> input player7's attack:*0*  
> input player8's attack:*0*  
> input player9's attack:*0*  
> OK;You hurt me with the sum of 10 attack in this round;  
> Now I only have 990 hp;  
> I guess you didn't want to hurt me.  
> thank you very much!  
> Although I don't want to die now,but I must help you succeed!  
> Keep attacking!  
>  
> Round 2 begin!  
> I have 990 hp now.  
> input player1's attack:*10*  
> input player2's attack:*10*  
> input player3's attack:*10*  
> input player4's attack:*10*  
> input player5's attack:*10*  
> input player6's attack:*10*  
> input player7's attack:*10*  
> input player8's attack:*10*  
> input player9's attack:*10*  
> OK;You hurt me with the sum of 100 attack in this round;  
> Now I only have 890 hp;  
> My hp is still high now!  
> Thanks for your mercy!  
> Although I don't want to die now,but I must help you succeed!  
> Keep attacking!  
>  
> Round 3 begin!  
> I have 890 hp now.  
> input player1's attack:*4*  
> input player2's attack:*40*  
> input player3's attack:*40*  
> input player4's attack:*50*  
> input player5's attack:*4*  
> input player6's attack:*40*  
> input player7's attack:*50*  
> input player8's attack:*50*  
> input player9's attack:*40*  
> OK;You hurt me with the sum of 328 attack in this round;  
> Now I only have 562 hp.  
> It's really hurt... But I'm still alive!   
> Although I don't want to die now,but I must help you succeed!  
> Keep attacking!  
>  
> Round 4 begin!  
> I have 562 hp now.  
> input player1's attack:*60*  
> input player2's attack:*60*  
> input player3's attack:*60*  
> input player4's attack:*60*  
> input player5's attack:*60*  
> input player6's attack:*60*  
> input player7's attack:*60*  
> input player8's attack:*60*  
> input player9's attack:*20*  
> OK;You hurt me with the sum of 510 attack in this round;  
> Now I only have 52 hp;  
> Good! I think I'm so lucky that I made it with such few hp!  
> Although I don't want to die now,but I must help you succeed!  
> Keep attacking!  
>  
> Round 5 begin!  
> I have 52 hp now.  
> input player1's attack:*52*  
> input player2's attack:*20*  
> input player3's attack:*20*  
> input player4's attack:*20*  
> input player5's attack:*20*  
> input player6's attack:*20*  
> input player7's attack:*20*  
> input player8's attack:*20*  
> input player9's attack:*20*  
> OK;You hurt me with the sum of 222 attack in this round;  
> Now I only have...No!!My hp come to the bottom!  
> Oops!I DIED!  
> You only take 5 round(s) to defeat me!!  
> Congratulation to your success! Goodbye!!  

## break/continue : 循环控制
循环在解决实际问题方面有很广泛的应用；  
然而，要想发挥其最大作用，必须引入控制循环的元素，即**break和continue**；  
>此外，函数goto也可以控制循环，
但由于其权限太大，可以跳到代码任意位置，破坏了代码的逻辑，故在此不做介绍；

简单来说，函数break可以**跳出**其**所在循环**；  
而函数continue可以无视其所在循环体中接下来的所有内容，**直接进入下一轮循环**；  
（对于for循环，仍会执行圆括号中的**第三条语句**）  
具体可以看下面的例子:(break.c)
```c
#include <stdio.h>
int main()
{
	int atk1 = 0;
	int atk2 = 0;
	int atk3 = 0;
	int a, b, c;
	int solution = 0;
	const int hp = 100;

	printf("I have 100 hp now.\nThere have still 3 players that will attack me.\n");
	printf("What's different is everyone can attck for 1 ~ 10 times;\n");
	printf("But you can't succeed unless my hp come to exactly 0;\n");
	printf("Can you make it?\n");

	do
	{
		printf("input player1's attack:");
		scanf("%d", &atk1 );
		while (atk1<0)
		{
			printf("I know you don't want to hurt me,but now the attack %d is too ABNORMAL!\n",atk1);
			printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
			scanf("%d", &atk1);
		}

		printf("input player2's attack:");
		scanf("%d", &atk2 );
		while (atk2<0)
		{
			printf("I know you don't want to hurt me,but now the attack %d is too ABNORMAL!\n",atk2);
			printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
			scanf("%d", &atk2);
		}

		printf("input player3's attack:");
		scanf("%d", &atk3 );
		while (atk3<0)
		{
			printf("I know you don't want to hurt me,but now the attack %d is too ABNORMAL!\n",atk3);
			printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
			scanf("%d", &atk3);
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
		if(solution == 0)

		printf("Pity! The players tried for so long... But still can't succeed!\nTry it again!\n");
	} while (solution == 0);

	printf("Congratulations!\nPlayer1 attack for %d times, Player2 attack for %d times, Player3 attack for %d times can change my hp to exactly 0!\nYOU WIN!!!\n", a, b, c);
	return 0;
}
```
这里我们要根据三个玩家的攻击来判定是否能刚好战胜“我”；  
而每个人最多能攻击10次；  
因此我们采用穷举法，判定是否有解法符合条件；  

```c
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
```
以上便是具体操作；  
使用**嵌套for循环**，用**排列组合**的方式一个个判定结果是否符合；  
一旦遇到符合的情况，就让**solution=1**，说明可以过关；  
之后，便用break结束循环； 

但要注意的是，函数break只能跳出其**所在循环**，而上面共有3个循环；  
因此，在剩下两个循环下面设置了两个 `if (solution == 1)break` 语句；  
表明如果找到解法就一次性结束3个循环；  
这样，3个break**接力完成**了对循环的控制；  

附：输入样例和输出结果：  
输入样例1：
>3  
5  
7  

输出结果1：
>Congratulations!  
Player1 attack for 2 times, Player2 attack for 9 times, Player3 attack for 7 times can change my hp to exactly 0!  
YOU WIN!!!

输入样例2：
>3  
6  
9  

输出结果2：
>Pity! The players tried for so long... But still can't succeed!  
Try it again!  
