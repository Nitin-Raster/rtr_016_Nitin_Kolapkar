#include <stdio.h>

int main(void)
{
	// Variable declarations
	char cArray_nkk[10];
	int i_nkk;

	// Code
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		cArray_nkk[i_nkk] = (char)(i_nkk + 65);

	printf("\n\n");
	printf("Elements Of the 'character' Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("cArray_nkk[%d] = %c \n", i_nkk, cArray_nkk[i_nkk]);

	printf("\n\n");
	printf("Addresses of the Elements Of The 'character' Array : \n\n");
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("cArray_nkk[%d] = %c \t \t Address = %p\n", i_nkk, cArray_nkk[i_nkk], &cArray_nkk[i_nkk]);

	printf("\n\n");

	return(0);
}

