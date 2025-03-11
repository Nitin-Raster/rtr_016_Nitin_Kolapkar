#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int iArray_nkk[10];
	int i_nkk;

	// code
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		iArray_nkk[i_nkk] = (i_nkk + 1) * 3;

	printf("\n\n");
	printf("Elements Of The Integer Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("iArray[%d] = %d\n", i_nkk, iArray_nkk[i_nkk]);

	printf("\n\n");
	printf("Elements Of The Integer Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("iArray[%d] = %d \t \t Address = %p\n", i_nkk, iArray_nkk[i_nkk], &iArray_nkk[i_nkk]);

	printf("\n\n");

	return(0);
}
