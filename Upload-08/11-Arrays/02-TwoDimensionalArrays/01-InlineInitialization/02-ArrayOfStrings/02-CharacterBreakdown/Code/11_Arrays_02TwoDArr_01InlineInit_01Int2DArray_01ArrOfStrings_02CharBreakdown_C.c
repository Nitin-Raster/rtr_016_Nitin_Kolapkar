#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Function Prototype
	int MyStrlen(char[]);

	// Variable Declarations

	// ******** A 'STRING' IS AN ARARAY OF CHARACTERS ... so char[] ISA char ARRAY AND HENCE, char[] IS A 'STRING'...
	// ******** AN ARRAY OF char ARRAYS IS AN ARRAY OF STRINGS !!! ********
	// ******** HENCE, char[] IS ONE char ARRAY AND HENCE, IS ONE STRING ********
	// ******** HENCE, char[][] IS AN ARRAY OF char ARRAYS AND HENCE, IS AN ARRAY OF STRINGS ********

	//Here, the string array can allow a maximum number of 10 strings (10 rows) and each of these 10 strings can have only upto 15 characters maximum (15 columns)
	char strArray_nkk[10][15] = { "Hello!", "Welcome", "To", "Real", "Time", "Rendering", "Batch", "(2024-25)", "Of", "ASTROMEDICOMP." }; // IN-LINE INITIALIZATION
	int iStrLengths[10]; // 1D INTEGER Array - Stores lengths of those atrings at corresponding indices in 'strArray[]' e.g. iStrLengths[0] will be the length of string at strArray_nkk[0], iStrLengths[1] will be the lenth of string at strArray_nkk[1]... strings, 10 lengths...
	int strArray_size_nkk;
	int strArray_num_rows_nkk;
	int i_nkk, j_nkk;

	// Code
	strArray_size_nkk = sizeof(strArray_nkk);
	strArray_num_rows_nkk = strArray_size_nkk / sizeof(strArray_nkk[0]);

	// Storing in lengths of all the strings...
	for (i_nkk = 0; i_nkk < strArray_num_rows_nkk; i_nkk++)
		iStrLengths[i_nkk] = MyStrlen(strArray_nkk[i_nkk]);

	printf("\n\n");
	printf("The Entire String Array : \n\n");
	for (i_nkk = 0; i_nkk < strArray_num_rows_nkk; i_nkk++)
		printf("%s ", strArray_nkk[i_nkk]);

	printf("\n\n");
	printf("String In The 2D Array : \n\n");

	// Since, char[][] is an array of strings, referencing only by the row number (first []) will give the row or the string
	// The Volumn Number (second []) is the particular character in that string / row
	for (i_nkk = 0; i_nkk < strArray_num_rows_nkk; i_nkk++)
	{
		printf("String Number %d => %s\n\n", (i_nkk + 1), strArray_nkk[i_nkk]);
		for (j_nkk = 0; j_nkk < iStrLengths[i_nkk]; j_nkk++)
		{
			printf("Character %d = %c\n", (j_nkk + 1), strArray_nkk[i_nkk][j_nkk]);
		}
		printf("\n\n");
	}
	return(0);
}

int MyStrlen(char str[])
{
	// Variable Declarations
	int j_nkk;
	int string_length_nkk = 0;

	// code
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
