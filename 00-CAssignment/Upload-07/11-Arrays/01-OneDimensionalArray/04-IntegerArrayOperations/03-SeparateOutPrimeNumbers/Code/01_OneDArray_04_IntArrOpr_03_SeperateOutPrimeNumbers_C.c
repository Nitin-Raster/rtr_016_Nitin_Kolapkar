#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
	// Variable Declarations
	int iArray_nkk[NUM_ELEMENTS];
	int i_nkk, num_nkk, j_nkk, count_nkk = 0;

	// Code
	printf("\n\n");

	// ******* ARRAY ELEMENTS INPUT ******
	printf("Enter Integer Elements For Array : \n\n");
	for (i_nkk = 0; i_nkk < NUM_ELEMENTS; i_nkk++)
	{
		scanf("%d", &num_nkk);

		// If 'num' is negative ( < 0 ), then convert it to positive (multiply by -1)
		if (num_nkk < 0)
			num_nkk = -1 * num_nkk;
			
		iArray_nkk[i_nkk] = num_nkk;
	}

	printf("\n\n");
	printf("Prime Numbers Amongst The Array Elements Are : \n\n");
	for (i_nkk = 0; i_nkk < NUM_ELEMENTS; i_nkk++)
	{
		for (j_nkk = 1; j_nkk <= iArray_nkk[i_nkk]; j_nkk++)
		{
			if ((iArray_nkk[i_nkk] % j_nkk) == 0)
				count_nkk++;
		}

		// NUMBER 1 IS NEITHER A PRIME NUMBER NOR A CONSONANT
		// IF A NUMBER IS PRIME, IT IS ONLY DIVISIBLE BY 1 AND ITSELF.
		// HENCE, IF A NUMBER IS PRIME, THE VALUE OF 'count' WILL BE EXACTLY 2.
		// IF THE VALUE OF 'count' IS GREATER THAN 2, THE NUMBER IS DIVISIBLE BY NUMBERS OTHER THAN 1 AND ITSELF AND HENCE, IT IS NOT PRIME
		// THE VALUE OF 'count' will be 1 only if iArray_nkk[i_nkk] is 1
		if (count_nkk == 2)
			printf("%d\n", iArray_nkk[i_nkk]);

		count_nkk = 0; // RESET 'count' TO 0 FOR CHECKING THE NEXT NUMBER...
	}

	return(0);
}