#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void assertInitializeGame(int actualPlayers, int expectedPlayers)
{
	if (actualPlayers != expectedPlayers)
	{
		printf("AssertInitializeGame: Test Fail!\n");
		fail = 1;
	}
}

void checkAssert()
{
	if (fail != 1)
		printf("AssertInitializeGame: Test Success!\n");
}

int main()
{
	struct gameState *game = newGame();
	int array[10] = {1,2,3,4,5,6,7,8,9,10};

	initializeGame(2, array, 9, game);

	assertInitializeGame(game->numPlayers, 2);

	checkAssert();

	return 0;
}
