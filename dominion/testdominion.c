#include "dominion.h"
#include <stdio.h>
#include <time.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) 
{
	const char* cardNames[] = {
		"curse", "estate", "duchy", "province", "copper", "silver",
		"gold", "adventurer", "council_room", "feast", "gardens",
		"mine", "remodel", "smithy", "village", "baron", "great_hall",
		"minion", "steward", "tribute", "ambassador", "cutpurse", 
		"embargo", "outpost", "salvager", "sea_hag", "treasure_map"};

	struct gameState G;
	struct gameState *p = &G;

	int numPlayers = 0;
	int seed;
	int k[10];

	printf ("Starting game.\n");

	//
	// Random number of players between 2 and 4;
	//
	numPlayers = rand() % 3 + 2;

	//
	// Get the random seed from the user on command line, if it isn't there generate one.
	//
	if (argc == 2){
		seed = atoi(argv[1]);
		srand(atoi(argv[1]));
	}
	else {
		srand(time(NULL));
		printf("This game can take a random seed as its first parameter\n");
		printf("Using rand() to generate one instead\n");
		seed = rand();
		srand(seed);
	}

	printf("Game starts with %d players, using %d as random seed\n", numPlayers, seed); 

	int money = 0;
	int actionPos = -1;
	int i=0;
	int cards[treasure_map] = {0};
	int card;
	int turn = 0;
	int numActions = 0;

	printf("Kingdom cards:\n");

	//
	// Generate unique random kingdom cards to use foer this game.
	//
	for (i = 0; i < 10; i++){
		card = rand() % (treasure_map - adventurer + 1) + adventurer;
		if (cards[card]){
			i--;
			continue;
		}
		cards[card] = 1;
		k[i] = card;
		printf("%s,\n", cardNames[card]);
	}

	//
	// Initialize the game
	//
	initializeGame(numPlayers, k, seed, p);
	for (i = 0; i < numPlayers; i++){
		printf("Score for %d: %d\n", i, scoreFor(i, p));
	}

	//
	// Run until the game is over.
	//
	while (!isGameOver(p)) {
		printf("Turn#: %d\n", ++turn);
		money = 0;
		actionPos = -1;
		//
		// Count the amount of money in the player's hand and determine if they have an
		// action card that can be played.
		//
		for (i = 0; i < numHandCards(p); i++) {
			if (handCard(i, p) == copper)
				money++;
			else if (handCard(i, p) == silver)
				money += 2;
			else if (handCard(i, p) == gold)
				money += 3;
			else if (handCard(i,p) <= treasure_map && handCard(i,p) >= adventurer)
				actionPos = i;
		}

		//
		// Try to play an action card (dumb, with respect to user choices).
		//
		if (actionPos != -1) {
			printf("Player %d attempts to play %s from hand\n", 
					p->whoseTurn, cardNames[p->hand[whoseTurn(p)][actionPos]]);

			if(playCard(actionPos, -1, -1, -1, p) == -1){
				printf("Play failed\n");
			}
			else{
				printf("Play succeeded\n");
			}

			money = 0;
			i=0;
			//
			// Recalculate the amount of money that the user has.
			//
			while(i<numHandCards(p)){
				if (handCard(i, p) == copper){
					money++;
				}
				else if (handCard(i, p) == silver){
					money += 2;
				}
				else if (handCard(i, p) == gold){
					money += 3;
				}
				i++;
			}
		}

		//
		// Buy a province if the player has the money.
		//
		if (money >= 8) {
			printf("%d: bought province\n", p->whoseTurn); 
			buyCard(province, p);
		}
		//
		// Otherwise, a 50% chance that they'll buy a treasure or action card.
		//
		else if(rand() % 2){
			//
			// Buy the most expensive treasure card they can afford.
			//
			if (money >= 6){
				printf("%d: bought gold\n", p->whoseTurn); 
				buyCard(gold, p);
			}
			else if (money >= 3){
				printf("%d: bought silver\n", p->whoseTurn); 
				buyCard(silver, p);
			}
			else{
				printf("%d: bought copper\n", p->whoseTurn); 
				buyCard(copper, p);
			}
		}
		//
		// Otherwise buy an action card. Break after 1000 attempts to buy, as
		// this probably means they don't have enough money to buy a card.
		//
		else{
			for (i = 0; i < 1000; i++){
				card = k[rand() % 10];
				if (buyCard(card,p) != -1){
					i = -1;
					break;
				}
			}

			if (i == -1){
				printf("Player %d bought %s\n", p->whoseTurn, cardNames[card]);
			}
			else{
				printf("Player %d did not have enough money to buy a card...\n", p->whoseTurn);
			}
		}

		printf("%d: end turn\n", p->whoseTurn);
		endTurn(p);

		//
		// Print the scores for the players.
		//
		for (i = 0; i < numPlayers; i++){
			printf("Score for %d: %d\n", i, scoreFor(i, p));
		}
	} // end of While

	printf ("Finished game.\n");
	//
	// Print final scores for the players.
	//
	for (i = 0; i < numPlayers; i++){
		printf("Final Score for %d: %d\n", i, scoreFor(i, p));
	}

	printf("deck 1: %d\n",p->deckCount[0]);
	return 0;
}
