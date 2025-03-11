#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Variable Declarations
	char chArray_nkk[MAX_STRING_LENGTH]; // A Character Array Is A String
	int iStringLength = 0;

	// Code
	
	// ******* STRING INPUT ********
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_nkk, MAX_STRING_LENGTH);

	// ******** STRING OUTPUT ********
	printf("\n\n");
	printf("String Entered By You Is : \n\n");
	printf("%s\n", chArray_nkk);

	// ******** STRING LENGTH ********
	printf("\n\n");
	iStringLength = strlen(chArray_nkk);
	printf("Length Of Strng Is = %d Characters !!!\n\n", iStringLength);

	return(0);
}
