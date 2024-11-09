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