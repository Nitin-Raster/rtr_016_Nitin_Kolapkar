#include <stdio.h>

int main(void)
{
	// Variable declarations
	float fArray_nkk[10];
	float* ptr_fArray = NULL;
	int i_nkk;

	// Code
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		fArray_nkk[i_nkk] = (float)(i_nkk + 1) * 1.5f;

	// ******** NAME OF ANY ARRAY IS ITS BASE ADDRESS ********
	// ******** HENCE, 'fArray' IS THE BASE ADDRESS OF ARRAY fArray[] OR 'fArray' IS THE ADDRESS OF ELEMENT fArray[0] ********
	// ******** ASSIGNING BASE ADDRESS OF ARRAY 'fArray[]' TO FLOAT POINTER 'ptr_fArray'

	ptr_fArray = fArray_nkk; // ptr_fArray = & fArray[0];

	printf("\n\n");
	printf("Elements Of the 'float ' Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("fArray_nkk[%d] = %f \n", i_nkk, *(ptr_fArray + i_nkk));

	printf("\n\n");
	printf("Addresses of the Elements Of The 'float' Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("fArray_nkk[%d] = %f \t \t Address = %p\n", i_nkk, *(ptr_fArray + i_nkk), (ptr_fArray + i_nkk));

	printf("\n\n");

	return(0);
}

