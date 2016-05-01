#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void assertOutpostCard(int b, char *msg)
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
		printf("Assert: Success!\n");
}

int main()
{
	struct gameState *game = newGame();
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};

	int result = initializeGame(3, k, 7, game);
	assertOutpostCard(result == 0, "Initialize Game");

	int outpostPlayed = game->outpostPlayed;

	outpostCard(game, 0, 0);

	outpostPlayed = game->outpostPlayed;

	assertOutpostCard(outpostPlayed == 1, "outpost adds 1 to outpostPlayed");
	checkAsserts();

	return 0;
}
