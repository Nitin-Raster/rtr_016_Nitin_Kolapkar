#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int i_nkk;

	// Code
	printf("\n\n");

	printf("Printing Even Numbers From 0 to 100: \n\n");

	for (i_nkk = 0; i_nkk <= 100; i_nkk++)
	{
		// Condition for a number to be even number => division of number by 2 leaves no remainder (remainder = 0)
		// if remainder is not 0, the number is odd number...
		if (i_nkk % 2 != 0)
		{
			continue;
		}
		else
		{
			printf("\t%d\n", i_nkk);
		}
	}

	printf("\n\n");

	return(0);
}
