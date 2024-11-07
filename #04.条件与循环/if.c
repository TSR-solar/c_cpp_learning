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
		printf("No!!My hp come to the bottom!\nOops!I DIED!\n");
	}

	if (hp <= 0)
	{
		printf("Congratulation to your success! Goodbye!!\n");
	}
	return 0;
}