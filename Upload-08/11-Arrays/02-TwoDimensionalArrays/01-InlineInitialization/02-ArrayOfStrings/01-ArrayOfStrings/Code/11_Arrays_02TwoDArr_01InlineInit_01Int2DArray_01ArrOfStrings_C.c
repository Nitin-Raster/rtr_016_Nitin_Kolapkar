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
	char strArray_nkk[10][15] = { "Hello!", "Welcome", "To", "Real", "Time", "Rendering", "Batch", "(2024-25", "Of", "ASTROMEDICOMP." }; // IN-LINE INITIALIZATION
	int char_size_nkk;
	int strArray_size_nkk;
	int strArray_num_elements_nkk, strArray_num_rows_nkk, strArray_num_columns_nkk;
	int strActual_num_chars_nkk = 0;
	int i_nkk;

	// Code
	printf("\n\n");

	char_size_nkk = sizeof(char);

	strArray_size_nkk = sizeof(strArray_nkk);
	printf("Size Of Two Dimentional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_size_nkk);

	strArray_num_rows_nkk = strArray_size_nkk / sizeof(strArray_nkk[0]);
	printf("Number of Rows(Strings) In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_num_rows_nkk);

	strArray_num_columns_nkk = sizeof(strArray_nkk[0]) / char_size_nkk;
	printf("Number Of Columns In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_num_columns_nkk);

	strArray_num_elements_nkk = strArray_num_rows_nkk * strArray_num_columns_nkk;
	printf("Number Of Elements In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_num_elements_nkk);

	for (i_nkk = 0; i_nkk < strArray_num_rows_nkk; i_nkk++)
	{
		strActual_num_chars_nkk = strActual_num_chars_nkk + MyStrlen(strArray_nkk[i_nkk]);
	}
	printf("Actual Number of Elements (Characters) In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strActual_num_chars_nkk);

	printf("\n\n");
	printf("Strings In The 2D Array : \n\n");

	// Since, char[][] us an array of strings, referencing only by the row number (first []) will give the row or the strings
	// The Column Number (second []) is the particular character in that string / row
	printf("%s ", strArray_nkk[0]);
	printf("%s ", strArray_nkk[1]);
	printf("%s ", strArray_nkk[2]);
	printf("%s ", strArray_nkk[3]);
	printf("%s ", strArray_nkk[4]);
	printf("%s ", strArray_nkk[5]);
	printf("%s ", strArray_nkk[6]);
	printf("%s ", strArray_nkk[7]);
	printf("%s ", strArray_nkk[8]);
	printf("%s\n\n", strArray_nkk[9]);

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
