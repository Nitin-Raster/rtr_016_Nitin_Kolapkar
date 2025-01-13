#include <stdio.h>

int main(void)
{
	// Variable Declarations
	float fArray_nkk[10];
	int i_nkk;

	// Code
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		fArray_nkk[i_nkk] = (float)(i_nkk + 1) * 1.5f;

	printf("\n\n");
	printf("Elements Of The 'float' Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("fArray_nkk[%d] = %f\n", i_nkk, fArray_nkk[i_nkk]);

	printf("\n\n");
	printf("Elements Of The  'float' Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("fArray[%d] = %f \t \t Address = %p \n", i_nkk, fArray_nkk[i_nkk], &fArray_nkk[i_nkk]);

	printf("\n\n");

	return(0);
}
