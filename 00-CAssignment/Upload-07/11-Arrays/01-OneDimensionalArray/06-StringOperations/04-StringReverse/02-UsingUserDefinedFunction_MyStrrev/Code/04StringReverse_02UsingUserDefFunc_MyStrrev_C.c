#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Function Prototype
	void MyStrrev(char[], char[]);

	// Variable Declarations
	char chArray_Original_nkk[MAX_STRING_LENGTH], chArray_Reversed_nkk[MAX_STRING_LENGTH]; // A Character Array Is A String

	// Code
	
	// ******* STRING INPUT ********
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_Original_nkk, MAX_STRING_LENGTH);

	// ******** STRING REVERSE ********
	MyStrrev(chArray_Reversed_nkk, chArray_Original_nkk);

	// ******** STRING OUTPUT ********
	printf("\n\n");
	printf("The Original String Entered By You (i.e. : 'chArray_Original_nkk[]') Is : \n\n");
	printf("%s\n", chArray_Original_nkk);

	printf("\n\n");
	printf("The Reversed String (i.e. : 'chArray_Reverse_nkk[]') Is : \n\n");
	printf("%s\n", chArray_Reversed_nkk);

	return(0);
}

void MyStrrev(char str_destination[], char str_source[])
{
	// Function Prototype
	int MyStrlen(char[]);

	// Variable Declarations
	int iStringLength_nkk = 0;
	int i_nkk, j_nkk, len_nkk;

	// Code
	iStringLength_nkk = MyStrlen(str_source);

	// ARRAY INDICES BEGIN FROM 0, HENCE, LAST INDEX WILL ALWAYS BE (LENGTH - 1)
	len_nkk = iStringLength_nkk - 1;

	// WE NEED TP PUT THE CHARACTER WHICH IS AT LAST INDEX OF 'str_source' TO THE FIRST INDEX OF 'str_destination'
	// AND SECOND-LAST CHARACTER OF 'str_source' TO THE SECOND CHARACTER OF 'str_destanation' and so on....
	for (i_nkk = 0, j_nkk = len_nkk; i_nkk < iStringLength_nkk, j_nkk >= 0; i_nkk++, j_nkk--)
	{
		str_destination[i_nkk] = str_source[j_nkk];
	}

	str_destination[i_nkk++] = '\0';
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