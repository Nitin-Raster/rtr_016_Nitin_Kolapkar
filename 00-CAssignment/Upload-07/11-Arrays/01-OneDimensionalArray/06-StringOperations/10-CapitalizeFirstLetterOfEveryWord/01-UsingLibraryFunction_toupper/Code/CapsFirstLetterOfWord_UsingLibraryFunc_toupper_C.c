#include <stdio.h>
#include <ctype.h> // for toupper()

#define MAX_STRING_LENGHT 512

int main(void)
{
	// function prototype
	int MyStrlen(char[]);

	// Variable Declarations
	char chArray_nkk[MAX_STRING_LENGHT], chArray_CapitalizedFirstLetterOfEveryWord_nkk[MAX_STRING_LENGHT]; // A Character Array Is A String
	int iStringLength_nkk;
	int i_nkk, j_nkk;

	// Code

	// ******* STRING INPUT *******
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_nkk, MAX_STRING_LENGHT);

	iStringLength_nkk = MyStrlen(chArray_nkk);
	j_nkk = 0;
	for (i_nkk = 0; i_nkk < iStringLength_nkk; i_nkk++)
	{
		if (i_nkk == 0) // First Letter Of Any Sentence Must Be A CAPITAL LETTER
			chArray_CapitalizedFirstLetterOfEveryWord_nkk[j_nkk] = toupper(chArray_nkk[i_nkk]);

		else if (chArray_nkk[i_nkk] == ' ')
		{
			chArray_CapitalizedFirstLetterOfEveryWord_nkk[j_nkk] = chArray_nkk[i_nkk];
			chArray_CapitalizedFirstLetterOfEveryWord_nkk[j_nkk + 1] = toupper(chArray_nkk[i_nkk + 1]);

			// SINCE, ALREADY TWO CHARACTERS (AT INDICES 'i' and i + 1 HAVE BEEN CONSIDERED IN THIS	else-if BLOCK ... WE ARE EXTRA-INCREMENTING 'i' AND 'j' BY 1
			j_nkk++;
			i_nkk++;
		}

		else
			chArray_CapitalizedFirstLetterOfEveryWord_nkk[j_nkk] = chArray_nkk[i_nkk];

		j_nkk++;
	}

	chArray_CapitalizedFirstLetterOfEveryWord_nkk[j_nkk] = '\0';

	// ******* STRING OUTPUT *******
	printf("\n\n");
	printf("String Entered By You Is :  \n\n");
	printf("%s\n", chArray_nkk);

	printf("\n\n");
	printf("String After Capitalizing First Letter Of Every Word : \n\n");
	printf("%s\n", chArray_CapitalizedFirstLetterOfEveryWord_nkk);

	return(0);
}

int MyStrlen(char str[])
{
	// Variable Declarations
	int j;
	int string_length = 0;

	// Code
	// ******* DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) *******
	for (j = 0; j < MAX_STRING_LENGHT; j++)
	{
		if (str[j] == '\0')
			break;
		else
			string_length++;
	}
	return(string_length);
}

char MyToUpper(char ch)
{
	// Variable Declarations
	int num;
	int c;

	// Code

	// ASCII VALUE OF 'a' = ASCII VALUE OF 'A' (65) = 32
	// THIS SUBTRACTION WILL GIVE THE EXACT DIFFERENCE BETWEEN THE UPPER AND LOWER CASE COUNTERPARTS OF EACH LETTER OF THE ALPHABET
	// IF THE DIFFERENCE IS SUBTRACTED FROM THE ASCII VALUE OF A LOWER CASE LETTER, THE RESULTANT ASCII VALUE WILL BE THAT OF ITS UPPER CASE LETTER !!!
	// ASCII VALUES OF 'a' to 'z' => 97 TO 122
	// ASCII VALUES OF 'A' TO 'Z' => 65 TO 90
	num = 'a' - 'A';

	if ((int)ch >= 97 && (int)ch <= 122)
	{
		c = (int)ch - num;
		return((char)c);
	}

	else
		return(ch);
}
