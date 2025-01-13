#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
	// Variable Declarations
	int iArray_nkk[NUM_ELEMENTS];
	int i_nkk, num_nkk, sum_nkk = 0;

	// Code
	printf("\n\n");
	printf("Enter Integer Elements For Array : \n\n");
	for (i_nkk = 0; i_nkk < NUM_ELEMENTS; i_nkk++)
	{
		scanf("%d", &num_nkk);
		iArray_nkk[i_nkk] = num_nkk;
	}

	for (i_nkk = 0; i_nkk < NUM_ELEMENTS; i_nkk++)
	{
		sum_nkk = sum_nkk + iArray_nkk[i_nkk];
	}

	printf("\n\n");
	printf("Sum Of All Elements Of Array = %d\n\n", sum_nkk);

	return(0);
}