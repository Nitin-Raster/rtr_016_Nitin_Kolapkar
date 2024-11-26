#include<stdio.h>

int main(void)
{
	// Variable Declarations
	int i_nkk, j_nkk;

	// Code

	printf("\n\n");

	printf("Printing Digits 10 to 1 and 100 to 10 : \n\n");
	for (i_nkk = 10, j_nkk = 100; i_nkk >= 1, j_nkk >= 10; i_nkk--, j_nkk -= 10)
	{
		printf("\t %d \t %d\n", i_nkk, j_nkk);
	}

	printf("\n\n");
	return(0);
}