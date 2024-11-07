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