#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

void assertNewGame(struct gameState *game)
{
	if (!game)
	{
		printf("AssertNewGame: Test Fail!\n");

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
