#include <stdio.h>

int main(void)
{
	// Variable declarations
	char cArray_nkk[10];
	char *ptr_cArray = NULL;
	int i_nkk;

	// Code
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		cArray_nkk[i_nkk] = (char)(i_nkk + 65);

	// ******** NAME OF ANY ARRAY IS ITS BASE ADDRESS ********
	// ******** HENCE, 'cArray' IS THE BASE ADDRESS OF ARRAY cArray[] OR 'cArray' IS THE ADDRESS OF ELEMENT cArray[0] ********
	// ******** ASSIGNING BASE ADDRESS OF ARRAY 'cArray[]' TO FLOAT POINTER 'ptr_cArray'

	ptr_cArray = cArray_nkk; // ptr_cArray = & cArray[0];

	printf("\n\n");
	printf("Elements Of the 'character' Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("cArray_nkk[%d] = %c \n", i_nkk, *(ptr_cArray + i_nkk));

	printf("\n\n");
	printf("Addresses of the Elements Of The 'character' Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("cArray_nkk[%d] = %c \t \t Address = %p\n", i_nkk, *(ptr_cArray + i_nkk), (ptr_cArray + i_nkk));

	printf("\n\n");

	return(0);
}

