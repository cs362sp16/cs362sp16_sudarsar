#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

void assertKingdomCards(int *a)
{
	for (int i=0;i<10;i++)
	{
		if (!a[i])
			printf("AssertKingdomCards: Test Fail!\n");
	}	
}

int main()
{
	int *k = kingdomCards(2,3,4,5,6,7,8,9,10,11);
	assertKingdomCards(k);

	printf("AssertKingdomCards: Test Success!\n");

	return 0;
}
