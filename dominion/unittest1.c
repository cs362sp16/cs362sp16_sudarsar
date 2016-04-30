#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

int fail = 0;

void assertCompare(int compareResult, int expectedResult)
{
	if (compareResult == expectedResult)
		fail = 0;
	else
	{
		printf("AssertCompare: Test Fail!\n");
		printf("\tExpected: %d\n", expectedResult);
		printf("\tActual: %d\n", compareResult);

		fail = 1;
	
		exit(0);
	}
}

int main()
{
	assertCompare(compare(5,10), -1);
	assertCompare(compare(15,10), 1);
	assertCompare(compare(12,12), 0);
	assertCompare(compare(), 0);

	printf("AssertCompare: Test Success!\n");

	return 0;
}
