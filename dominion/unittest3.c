#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

void assertInitializeGame(int actualPlayers, int expectedPlayers)
{
	if (actualPlayers != expectedPlayers)
	{
		printf("AssertInitializeGame: Test Fail!\n");
		printf("Expected: %d\n", expectedPlayers);
		printf("Actual: %d\n", actualPlayers);

		exit(0);
	}
}

int main()
{
	struct gameState *game = newGame();
	int array[10] = {1,2,3,4,5,6,7,8,9,10};

	initializeGame(2, array, 0, game);

	assertInitializeGame(game->numPlayers, 2);

	printf("AssertInitializeGame: Test Success!\n");

	return 0;
}
