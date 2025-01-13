#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Variable Declarations
	char chArray_Original_nkk[MAX_STRING_LENGTH], chArray_Copy_nkk[MAX_STRING_LENGTH]; // A Character Array Is A String

	// Code
	
	// ******* STRING INPUT ********
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_Original_nkk, MAX_STRING_LENGTH);

	// ******** STRING COPY ********
	strcpy(chArray_Copy_nkk, chArray_Original_nkk);

	// ******** STRING OUTPUT ********
	printf("\n\n");
	printf("The Original String Entered By You (i.e. : 'chArray_Original_nkk') Is : \n\n");
	printf("%s\n", chArray_Original_nkk);

	printf("\n\n");
	printf("The Copied String (i.e. : 'chArray_Copy_nkk') Is : \n\n");
	printf("%s\n", chArray_Copy_nkk);

	return(0);
}
