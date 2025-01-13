#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Variable Declarations
	char chArray_One_nkk[MAX_STRING_LENGTH], chArray_Two_nkk[MAX_STRING_LENGTH]; // A Character Array Is A String

	// Code
	
	// ******* STRING INPUT ********
	printf("\n\n");
	printf("Enter First String : \n\n");
	gets_s(chArray_One_nkk, MAX_STRING_LENGTH);

	printf("\n\n");
	printf("Enter Second String : \n\n");
	gets_s(chArray_Two_nkk, MAX_STRING_LENGTH);

	// ******** STRING CONCAT ********
	printf("\n\n");
	printf("******** BEFORE CONCATENATION ********");
	printf("\n\n");
	printf("The Original First String Entered By You (i.e. 'chArray_One_nkk[]') Is: \n\n");
	printf("%s\n", chArray_One_nkk);

	printf("\n\n");
	printf("The Original Second String Entered By You (i.e. 'chArray_Two_nkk[]') Is: \n\n");
	printf("%s\n", chArray_Two_nkk);

	strcat(chArray_One_nkk, chArray_Two_nkk);

	printf("\n\n");
	printf("******** AFTER CONCATENATION ********");
	printf("\n\n");
	printf("'chArray_One_nkk[]' Is: \n\n");
	printf("%s\n", chArray_One_nkk);

	printf("\n\n");
	printf("'chArray_Two_nkk[]' Is: \n\n");
	printf("%s\n", chArray_Two_nkk);

	return(0);
}

