// ******** THIS PROGRAM REPLACES ALL VOWELS IN THE INPUT STRING WITH * (asterisk) SYMBOL ********
// ******** FOR EXAMPLE, ORIGINAL STRING 'Dr. Vijay Dattatray Gokhale ASTROMEDICOMP' WILL BECOME 'Dr. V*j*y D*ttr*y G*kh*l* *STR*M*D*C*MP'

#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Function Prototype
	int MyStrlen(char[]);
	void MyStrcpy(char[], char[]);

	// Variable Declarations
	char chArray_Original_nkk[MAX_STRING_LENGTH], chArray_VowelReplaced_nkk[MAX_STRING_LENGTH]; // A Character Array Is A String
	int iStringLength;
	int i;

	// Code
	
	// ******* STRING INPUT ********
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_Original_nkk, MAX_STRING_LENGTH);

	MyStrcpy(chArray_VowelReplaced_nkk, chArray_Original_nkk);

	iStringLength = MyStrlen(chArray_VowelReplaced_nkk);

	for (i = 0; i < iStringLength; i++)
	{
		switch (chArray_VowelReplaced_nkk[i])
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			chArray_VowelReplaced_nkk[i] = '*';
			break;
		default:
			break;
		}
	}

	// ******** STRING OUTPUT ********
	printf("\n\n");
	printf("String Entered By You Is : \n\n");
	printf("%s\n", chArray_Original_nkk);

	printf("\n\n");
	printf("String After Replacement Of Vowels By * Is : \n\n");
	printf("%s\n", chArray_VowelReplaced_nkk);

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

void MyStrcpy(char str_destination[], char str_source[])
{
	// Function Prototype
	int MyStrlen(char[]);

	// Variable Declarations
	int iStringLength = 0;
	int j;

	// Code
	iStringLength = MyStrlen(str_source);
	for (j = 0; j < iStringLength; j++)
		str_destination[j] = str_source[j];

	str_destination[j] = '\0';
}

