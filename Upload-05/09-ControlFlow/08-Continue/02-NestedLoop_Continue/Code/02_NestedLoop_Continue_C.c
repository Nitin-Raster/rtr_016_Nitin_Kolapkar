#include<stdio.h>

int main(void)
{
	// Variable Declaration
	int i_nkk, j_nkk;

	// Code
	printf("\n\n");

	printf("Outer Loop Prints Odd Numbers Between 1 and 10. \n\n");
	printf("Ineer Loop Prints Even Numbers Between 1 and 10 For Every Odd Number Printed By Outer Loop. \n\n");

	// Condition for a Number to be even Number => division of Number by 2 Leaves no Remainder (Remainder = 0)
	// Condition for a Number to be Odd Number => Division Of Number by 2 Leaves Remainder (Remainder = 1 (Usually))

	for (i_nkk = 1; i_nkk <= 10; i_nkk++)
	{
		if (i_nkk % 2 != 0) // If Number (i_nkk) Is Odd..
		{
			printf("i = %d\n", i_nkk);
			printf("----------\n");
			for (j_nkk = 1; j_nkk <= 10; j_nkk++)
			{
				if (j_nkk % 2 == 0) //If Number (j) Is Even...
				{
					printf("\t j_nkk = %d\n", j_nkk );
				}
				else // If Number (j_nkk) is Odd
				{
					continue;
				}
			}
			printf("\n\n");
		}
		else // If Number (i) Is Even...
		{
			continue;
		}
	}

	printf("\n\n");

	return(0);
}
