#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

void assertKingdomCardsValues(int *expectedPtr, int *actualPtr)
{
	int i = 0;

	for(i=0;i<10;i++)
	{
		if (expectedPtr[i] != actualPtr[i])
		{
			printf("AssertKingdomCardsValues: Test Fail!\n");
			printf("\tExpected Value: %d\n", expectedPtr[i]);
			printf("\tActual Value: %d\n", actualPtr[i]);

			exit(0);
		}
	}
}

int main()
{
	int *kingdomArray = kingdomCards(12,2,14,15,18,22,92,62,82,11);
	
	int *array = malloc(10 * sizeof(int));

	array[0] = 12;
	array[1] = 2;
	array[2] = 14;
	array[3] = 15;
	array[4] = 18;
	array[5] = 22;
	array[6] = 92;
	array[7] = 62;
	array[8] = 82;
	array[9] = 11;

	assertKingdomCardsValues(array, kingdomArray);

	printf("AssertKingdomCardsValues: Test Success!\n");

	return 0;
}
