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

	// ******** SEPERATING OUT EVEN NUMBERS FROM ARRAY ELEMENTS ********
	printf("\n\n");
	printf("Even Numbers Amongst The Array Elements Are : \n\n");
	for (i_nkk = 0; i_nkk < NUM_ELEMENTS; i_nkk++)
	{
		if ((iArray_nkk[i_nkk] % 2) == 0)
			printf("%d\n", iArray_nkk[i_nkk]);
	}

	// ******** SEPERATING OUT ODD NUMBERS FROM ARRAY ELEMENTS ********
	printf("\n\n");
	printf("Odd Numbers Amongst The Array Elements Are : \n\n");
	for (i_nkk = 0; i_nkk < NUM_ELEMENTS; i_nkk++)
	{
		if ((iArray_nkk[i_nkk] % 2) != 0)
			printf("%d\n", iArray_nkk[i_nkk]);
	}

	return(0);
}