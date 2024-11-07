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
		printf("I have %d hp now.\n",hp);

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