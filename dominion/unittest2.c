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

		exit(0);
	}
}

int main()
{
	struct gameState *game = newGame();

	assertNewGame(game);

	printf("AssertNewGame: Test Success!\n");
	return 0;
}
