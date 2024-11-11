### 同类型变量容器：数组
有一个东西，它和变量非常相似，但相比于变量只能储存值，它却能储存多个变量，它就是**数组**；  
数组可以看成很多个变量；其中的变量必须具有**相同的类型**；

定义一个数组和定义一个变量类似，区别是数组需要加上方括号[]，里面写上数组的大小；
>如 int a[3]；

数组的大小代表了它能存放变量的个数；  
但要注意的是，数组的下标却是**从0开始**，因此数组a[3]实际上只有:
>a[0] a[1] a[2];  

这样是为了编译器的方便；

数组需要**初始化**；
可以通过赋值大括号里面的数的方式来初始化；
>如 int a[3] = {0,1,2}  
这样 a[0]=0 a[1]=1 a[2]=2；

需要注意的是，当输入的值不足的时候，剩下的值都将默认为0；  
但是必须要输入第一个值,否则所有的数都是乱码；

除此之外，在初始化的情况下，定义可以省略大小，此时的大小就是输入的数字个数；  
这种方法又叫做集成初始化；  
除此之外，还可以“精准”初始化，只需要用**[n]**在初始化数据中给出定位；

在初始化后，就可以往数组内部赋值以存储多个数据；

具体可以看下面的例子：(array.c)
```c
#include <stdio.h>
int main()
{
	int atk[9] = { 0 };
	int sumatk = 0, n = 0, originalhp, hp, player;
	const int ATK10 = 10;
	
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
		sumatk = 0;
		for (player = 0; player < 9; player++)
		{
			printf("input player%d's attack:", player+1);
			scanf("%d", &atk[player]);
			while (atk[player] < 0)
			{
				printf("I know you don't want to hurt me,but now player %d's attack %d is too ABNORMAL!\n",player+1 ,atk[player]);
				printf("If you input this atk,it means you want to heal me!I refuse it!!\nPlease input it again:");
				scanf("%d", &atk[player]);
			}
		}

		printf("The 9 attacks you input are:");
		for (player = 0; player < 9; player++)
		{
			printf("%d\t", atk[player]);
			sumatk += atk[player];
		}
		printf("Then adds player 10's attack;\n");
		sumatk += ATK10;
		hp -= sumatk;
		printf("OK;You hurt me with the sum of %d attack in this round;\nNow I only have", sumatk);

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

```c
for (player = 0; player < 9; player++)
{
    printf("请输入玩家%d的攻击:", player+1);
    scanf("%d", &atk[player]);
    while (atk[player] < 0)
    {
        printf("我知道你不想攻击我，但也别把玩家%d的攻击设置成“%d”啊！\n",player+1 ,atk[player]);
        printf("这可是个负数！我不接受治疗！请重新输入：");
        scanf("%d", &atk[player]);
    }
}
```
以上就是用for循环来给数组依次赋值的例子，需要注意player要**从0开始**；  
用for循环对数组处理又称为**遍历数组**；

### sizeof和数组
sizeof可以给出整个数组所占据的内容的大小，单位是字节；  
因此，用sizeof(a)/sizeof(a[0])就能得到数组的大小，不随数组数据的增减而变化；

## 高维数组
就像一维空间可以拓展到二维三维一样，数组也可以拓展维数；  
因此，就有了二维，三维乃至n维数组；  
以二维数组为例：  
二维数组定义需要加上两个方括号，分别代表行、列；  
若要集成初始化，只能省略第一个方括号里的内容；  
初始化时，除了一整个大括号，每一行要加上一层大括号；  
>如 int a[3][3]=  
{  
{1,1}  
{1}  
}  
初始化后，a[0][0]=1;a[1][0]=1;a[0][1]=1;其余6个数都是0； 
 
至于更高维度数组，以此类推就行了，只不过比较抽象；