#include <stdio.h>

// MACRO CONSTANT USED AS ARRAY SIZE IN SUBSCRIPT AND AS LENGTH.
// HENCE, THIS PROGRAM's ARRAYS' SIZES CAN BE SIMPLY CHANGED BY CHANGING THESE FOLLOWING 3 GLOBAL MACRO CONSTANT VALUES, BEFORE COMPILING, LINKING AND EXECUTING THE PROGRAM !!!

#define INT_ARRAY_NUM_ELEMENTS 5
#define FLOAT_ARRAY_NUM_ELEMENTS 3
#define CHAR_ARRAY_NUM_ELEMENTS 15

int main(void)
{
	// Variable Declarations
	int iArray_nkk[INT_ARRAY_NUM_ELEMENTS];
	float fArray_nkk[FLOAT_ARRAY_NUM_ELEMENTS];
	char cArray_nkk[CHAR_ARRAY_NUM_ELEMENTS];
	int i_nkk, num_nkk;

	// Code

	// ************* ARRAY ELEMENTS INPUT *****************
	printf("\n\n");
	printf("Enter Elements For 'Integer' Array : \n");
	for (i_nkk = 0; i_nkk < INT_ARRAY_NUM_ELEMENTS; i_nkk++)
		scanf("%d", &iArray_nkk[i_nkk]);

	printf("\n\n");
	printf("Enter Elements For 'Floating-Point' Array : \n");
	for (i_nkk = 0; i_nkk < FLOAT_ARRAY_NUM_ELEMENTS; i_nkk++)
		scanf("%f", &fArray_nkk[i_nkk]);
	
	printf("\n\n");
	printf("Enter Elements For 'Character' Array : \n");
	for (i_nkk = 0; i_nkk < CHAR_ARRAY_NUM_ELEMENTS; i_nkk++)
	{
		cArray_nkk[i_nkk] = getch();
		printf("%c\n", cArray_nkk[i_nkk]);
	}

	// ********** ARRAY ELEMENTS OUTPUT **********
	printf("\n\n");
	printf("Integer Array Entered By you : \n\n");
	for (i_nkk = 0; i_nkk < INT_ARRAY_NUM_ELEMENTS; i_nkk++)
		printf("%d\n", iArray_nkk[i_nkk]);

	printf("\n\n");
	printf("Floating-Point Array Entered By you : \n\n");
	for (i_nkk = 0; i_nkk < FLOAT_ARRAY_NUM_ELEMENTS; i_nkk++)
		printf("%f\n", fArray_nkk[i_nkk]);

	printf("\n\n");
	printf("Character Array Entered By you : \n\n");
	for (i_nkk = 0; i_nkk < CHAR_ARRAY_NUM_ELEMENTS; i_nkk++)
		printf("%c\n", cArray_nkk[i_nkk]);

	return(0);
}
