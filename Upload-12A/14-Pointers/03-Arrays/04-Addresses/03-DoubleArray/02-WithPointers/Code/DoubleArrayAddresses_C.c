#include <stdio.h>

int main(void)
{
	// Variable declarations
	double dArray_nkk[10];
	double *ptr_dArray = NULL;
	int i_nkk;

	// Code
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		dArray_nkk[i_nkk] = (double)(i_nkk + 1) * 1.3333f;

	// ******** NAME OF ANY ARRAY IS ITS BASE ADDRESS ********
	// ******** HENCE, 'dArray' IS THE BASE ADDRESS OF ARRAY dArray[] OR 'dArray' IS THE ADDRESS OF ELEMENT dArray[0] ********
	// ******** ASSIGNING BASE ADDRESS OF ARRAY 'dArray[]' TO FLOAT POINTER 'ptr_dArray'

	ptr_dArray = dArray_nkk; // ptr_dArray = & dArray[0];

	printf("\n\n");
	printf("Elements Of the 'double ' Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("dArray_nkk[%d] = %lf \n", i_nkk, *(ptr_dArray + i_nkk));

	printf("\n\n");
	printf("Addresses of the Elements Of The 'double' Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("dArray_nkk[%d] = %lf \t \t Address = %p\n", i_nkk, *(ptr_dArray + i_nkk), (ptr_dArray + i_nkk));

	printf("\n\n");

	return(0);
}

