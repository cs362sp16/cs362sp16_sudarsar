#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void assertSmithy(int b, char *msg)
{
	if (b == 0)
	{
		printf("AssertSmithy: Fail! (%s)\n", msg);
		fail = 1;
	}
}

void checkAsserts()
{
	if (!fail)
		printf("AssertSmithy: Success!\n");
}

int main()
{
	struct gameState *game = newGame();
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};

	int result = initializeGame(3, k, 7, game);
	assertSmithy(result == 0, "Initialize Game");

	int cardsInHand = numHandCards(game);

	smithyCard(0, 0, game, 5);
	
	cardsInHand = numHandCards(game);
	assertSmithy(cardsInHand == 8, "smithy adds 3 cards, should have 8 cards");

	checkAsserts();

	return 0;
}
