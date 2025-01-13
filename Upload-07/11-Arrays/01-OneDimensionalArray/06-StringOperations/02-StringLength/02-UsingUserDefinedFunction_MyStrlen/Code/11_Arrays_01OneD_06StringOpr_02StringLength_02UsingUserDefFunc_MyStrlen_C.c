#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Function Prototype
	int MyStrLen(char[]);

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
	iStringLength = MyStrlen(chArray_nkk);
	printf("Length Of Strng Is = %d Characters !!!\n\n", iStringLength);

	return(0);
}

int MyStrlen(char str[])
{
	// Variable Declarations
	int j_nkk;
	int string_length_nkk = 0;

	// Code
	// ******** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) ********
	for (j_nkk = 0; j_nkk < MAX_STRING_LENGTH; j_nkk++)
	{
		if (str[j_nkk] == '\0')
			break;
		else
			string_length_nkk++;
	}
	return(string_length_nkk);
}
