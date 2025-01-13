#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Function Prototype
	void MyStrcpy(char[], char[]);

	// Variable Declarations
	char chArray_Original_nkk[MAX_STRING_LENGTH], chArray_Copy_nkk[MAX_STRING_LENGTH]; // A Character Array Is A String

	// Code
	
	// ******* STRING INPUT ********
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_Original_nkk, MAX_STRING_LENGTH);

	// ******** STRING COPY ********
	MyStrcpy(chArray_Copy_nkk, chArray_Original_nkk);

	// ******** STRING OUTPUT ********
	printf("\n\n");
	printf("The Original String Entered By You (i.e. : 'chArray_Original_nkk') Is : \n\n");
	printf("%s\n", chArray_Original_nkk);

	printf("\n\n");
	printf("The Copied String (i.e. : 'chArray_Copy_nkk') Is : \n\n");
	printf("%s\n", chArray_Copy_nkk);

	return(0);
}

void MyStrcpy(char str_destination[], char str_source[])
{
	// Function Prototype
	int MyStrlen(char[]);

	// Variable Declarations
	int iStringLength_nkk = 0;
	int j_nkk;

	// Code
	iStringLength_nkk = MyStrlen(str_source);
	for (j_nkk = 0; j_nkk < iStringLength_nkk; j_nkk++)
		str_destination[j_nkk] = str_source[j_nkk];

	str_destination[j_nkk] = '\0';
}

int MyStrlen(char str[])
{
	// Variable Declarations
	int j;
	int string_length = 0;

	// Code
	// ******** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) ********
	for (j = 0; j < MAX_STRING_LENGTH; j++)
	{
		if (str[j] == '\0')
			break;
		else
			string_length++;
	}
	return(string_length);
}