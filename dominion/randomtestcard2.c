#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "dominion.h"
#include "rngs.h"

#define NUM_TESTS 100

int main()
{
	SelectStream(2);
	PutSeed(time(NULL));

	struct gameState game;

	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};

	int i, j, numPlayers, seed;

	for(i=0;i<NUM_TESTS;i++)
	{
		numPlayers = (rand() % MAX_PLAYERS) + 1;
		seed = rand();

		initializeGame(numPlayers, k, seed, &game);

		for(j=0;j<numPlayers;j++)
		{
			game.handCount[j] = rand() % MAX_HAND;
			game.deckCount[j] = rand() % (MAX_DECK - game.handCount[j]);
			game.discardCount[j] = rand() % (MAX_DECK - game.discardCount[j]);

			int n;
			int handPos = rand() % (game.handCount[j] + 1);

			for(n=0;n<game.handCount[j];n++)
			{
				game.hand[j][n] = rand() % (treasure_map + 1);
				game.handCount[j]++;
			}

			for(n=0;n<game.deckCount[j];n++)
			{
				game.deck[j][n] = rand() % (treasure_map + 1);
				game.deckCount[j]++;
			}

			for(n=0;n<game.discardCount[j];n++)
			{
				game.discard[j][n] = rand() % (treasure_map + 1);
				game.discardCount[j]++;
			}	

			game.hand[j][handPos] = village;
			int result = cardEffect(village, 0, 0, 0, &game, handPos, 0);

			if (result != 0)
			{
				printf("Test Fail\n");
				exit(0);
			}
		}
	}

	printf("Tests Successfully Completed!\n");
	return 0;
}
