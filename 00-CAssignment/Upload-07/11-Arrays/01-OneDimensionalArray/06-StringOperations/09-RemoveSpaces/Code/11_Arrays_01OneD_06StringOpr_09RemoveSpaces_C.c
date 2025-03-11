#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Function Prototype
	int MyStrlen(char[]);
	void MyStrcpy(char[], char[]);

	// Variable Declarations
	char chArray_nkk[MAX_STRING_LENGTH], chArray_SpacesRemoved_nkk[MAX_STRING_LENGTH]; // A Character Array Is A String
	int iStringLength;
	int i, j;

	// Code
	
	// ******* STRING INPUT ********
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_nkk, MAX_STRING_LENGTH);

	iStringLength = MyStrlen(chArray_nkk);
	j = 0;
	for (i = 0; i < iStringLength; i++)
	{
		if (chArray_nkk[i] == ' ')
			continue;
		else
		{
			chArray_SpacesRemoved_nkk[j] = chArray_nkk[i];
			j++;
		}
	}

	chArray_SpacesRemoved_nkk[j++] = '\0';

	// ******** STRING OUTPUT ********
	printf("\n\n");
	printf("String Entered By You Is : \n\n");
	printf("%s\n", chArray_nkk);

	printf("\n\n");
	printf("String After Removal Of Spaces Is : \n\n");
	printf("%s\n", chArray_SpacesRemoved_nkk);

	return(0);
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
