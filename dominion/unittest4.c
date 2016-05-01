#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void assertKingdomCards(int *a)
{
	for (int i=0;i<10;i++)
	{
		if (!a[i])
		{
			printf("AssertKingdomCards: Test Fail!\n");
			fail = 1;
		}
	}	
}

void checkAssert()
{
	if (fail != 1)
		printf("AssertKingdomCards: Test Success!\n");
}

int main()
{
	int *k = kingdomCards(2,3,4,5,6,7,8,9,10,11);
	assertKingdomCards(k);

	checkAssert();

	return 0;
}
