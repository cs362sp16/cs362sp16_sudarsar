#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void assertNewGame(struct gameState *game)
{
	if (!game)
	{
		printf("AssertNewGame: Test Fail!\n");
		fail = 1;
	}
}

void checkAssert()
{
	if (fail != 1)
		printf("AssertNewGame: Test Success!\n");
}

int main()
{
	struct gameState *game = newGame();

	assertNewGame(game);

	checkAssert();

	return 0;
}
