#include <stdio.h>

int main(void)
{
	// Variable declarations
	double dArray_nkk[10];
	int i_nkk;

	// Code
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		dArray_nkk[i_nkk] = (double)(i_nkk + 1) * 1.3333f;

	printf("\n\n");
	printf("Elements Of the 'double ' Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("dArray_nkk[%d] = %lf \n", i_nkk, dArray_nkk[i_nkk]);

	printf("\n\n");
	printf("Addresses of the Elements Of The 'double' Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("dArray_nkk[%d] = %lf \t \t Address = %p\n", i_nkk, dArray_nkk[i_nkk], &dArray_nkk[i_nkk]);
	printf("dArray_nkk[%d] = %lf \t \t Address = %p\n", i_nkk, dArray_nkk[i_nkk], &dArray_nkk[i_nkk]);

	printf("\n\n");

	return(0);
}

