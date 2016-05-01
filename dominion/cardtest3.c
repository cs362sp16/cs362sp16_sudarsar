#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void assertGreatHall(int b, char *msg)
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

	/* int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus) */

	int result = initializeGame(3, k, 7, game);
	assertGreatHall(result == 0, "Initialize Game");

	int numActions = game->numActions;

	int temp[10];
	cardEffect(16,1,2,3,game,3,temp);

	numActions = game->numActions;

	assertGreatHall(numActions == 2, "great_hall adds 1 to cardsInHand and adds 1 to numActions");
	checkAsserts();
	
	return 0;
}
