#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void assertEmbargo(int b, char *msg)
{
	if (b == 0)
	{
		printf("Assert: Fail! (%s)\n", msg);
		fail = 1;
	}
}

void checkAsserts()
{
	if (!fail)
		printf("AssertEmbargo: Success!\n");
}

int main()
{
	struct gameState *game = newGame();
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};

	int result = initializeGame(3, k, 7, game);
	assertEmbargo(result == 0, "Initialize Game");

	/* int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus) */

	int coins = game->coins;
	int tokens = game->embargoTokens[1];

	int temp[10];
	cardEffect(22,1,2,3,game,3,temp);

	coins = game->coins;
	tokens = game->embargoTokens[1];

	assertEmbargo(coins == 6 && tokens == 1, "embargo added 2 coins to game state");
	checkAsserts();

	return 0;
}
