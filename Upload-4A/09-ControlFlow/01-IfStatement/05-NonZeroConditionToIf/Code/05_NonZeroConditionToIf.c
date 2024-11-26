#include<stdio.h>

int main(void)
{
	// Variable Declarations
	int a_nkk;

	printf("\n\n");

	a_nkk = 5;
	if (a_nkk) // Non-Zero Positive Value
	{
		printf("If-Block 1 : 'A' Exists And Has VAlue = %d !!!\n\n", a_nkk);
	}

	a_nkk = -5;
	if (a_nkk) //Non-Zero Negative Value
	{
		printf("If-Block 2 : 'A' Exists And Has Value = %d !!!\n\n", a_nkk);
	}

	a_nkk = 0;
	if (a_nkk) //Zero Value
	{
		printf("If-Block 3 : 'A' Exists And Has Value = %d !!!\n\n", a_nkk);
	}

	printf("All Three If-Statements Are Done !!!\n\n");

	return(0);
}