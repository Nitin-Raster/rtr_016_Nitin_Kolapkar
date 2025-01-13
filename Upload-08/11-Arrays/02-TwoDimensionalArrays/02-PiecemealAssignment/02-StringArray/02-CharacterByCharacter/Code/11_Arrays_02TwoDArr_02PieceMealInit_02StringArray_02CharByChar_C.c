#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Variable Declarations

	// ******** A 'STRING' IS AN ARRAY OF CHARACTERS ... so char[] IS A char ARRAY AND HENCE, char[] IS A 'STRING' ********
	// ******** AN ARRAY OF char ARRAYS IS AN ARRAY OF STRINGS !!! ********
	// ******** HENCE, char[] IS ONE char ARRAY AND HENCE, IS ONE STRING ********
	// ******** HENCE, char[][] IS AN ARRAY OF char ARRAYS AND HENCE, IS AN ARRAY OF STRINGS ********

	// Here, the string array can allow a maximum number of 5 strings (5 rows) and each of these 5 strings can have only upto 10 characters (10 columns)
	char strArray_nkk[5][10]; // 5 ROWS (0, 1, 2, 3, 4) -> 5 STRINGS (EACH STRING CAN HAVE A MAXIMUM OF 10 CHARACTERS)
	int char_size_nkk;
	int strArray_size_nkk;
	int strArray_num_elements_nkk, strArray_num_rows_nkk, strArray_num_columns_nkk;
	int i_nkk;

	// Code
	printf("\n\n");

	char_size_nkk = sizeof(char);

	strArray_size_nkk = sizeof(strArray_nkk);
	printf("Size Of Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_size_nkk);

	strArray_num_rows_nkk = strArray_size_nkk / sizeof(strArray_nkk[0]);
	printf("Number of Rows (Strings) In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_num_rows_nkk);

	strArray_num_columns_nkk = sizeof(strArray_nkk[0]) / char_size_nkk;
	printf("Number Of Columns InTwo Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_num_columns_nkk);

	strArray_num_elements_nkk = strArray_num_rows_nkk * strArray_num_columns_nkk;
	printf("Maximum Number Of Elements (Character) In Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_num_elements_nkk);

	// ******** PIECE-MEAL ASSIGNMENT ********
	// ******** ROW 1 / STRING 1 ********
	strArray_nkk[0][0] = 'M';
	strArray_nkk[0][1] = 'y';
	strArray_nkk[0][2] = '\0'; // NULL-TERMINATING CHARACTER

	// ******** ROW 2 / STRING 2 ********
	strArray_nkk[1][0] = 'N';
	strArray_nkk[1][1] = 'a';
	strArray_nkk[1][2] = 'm';
	strArray_nkk[1][3] = 'e';
	strArray_nkk[1][4] = '\0'; // NULL-TERMINATING CHARACTER

	// ******** ROW 3 / STRING 3 ********
	strArray_nkk[2][0] = 'I';
	strArray_nkk[2][1] = 's';
	strArray_nkk[2][2] = '\0'; // NULL-TERMINATING CHARACTER

	// ******** ROW 4 / STRING 4 ********
	strArray_nkk[3][0] = 'A';
	strArray_nkk[3][1] = 'n';
	strArray_nkk[3][2] = 't';
	strArray_nkk[3][3] = 'h';
	strArray_nkk[3][4] = 'o';
	strArray_nkk[3][5] = 'n';
	strArray_nkk[3][6] = 'y';
	strArray_nkk[3][7] = '\0'; // NULL-TERMINATING CHARACTER

	// ******** ROW 5 / STRING 5 ********
	strArray_nkk[4][0] = 'G';
	strArray_nkk[4][1] = 'o';
	strArray_nkk[4][2] = 'n';
	strArray_nkk[4][3] = 's';
	strArray_nkk[4][4] = 'a';
	strArray_nkk[4][5] = 'l';
	strArray_nkk[4][6] = 'v';
	strArray_nkk[4][7] = 'e';
	strArray_nkk[4][8] = 's';
	strArray_nkk[4][9] = '\0'; // NULL-TERMINATING CHARACTER

	printf("\n\n");
	printf("The Strings In the 2D Character Array Are : \n\n");

	for (i_nkk = 0; i_nkk < strArray_num_rows_nkk; i_nkk++)
		printf("%s ", strArray_nkk[i_nkk]);

	printf("\n\n");

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
