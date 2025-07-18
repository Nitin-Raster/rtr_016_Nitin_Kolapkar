#include<stdio.h> //for printf()
#include<conio.h> // for getch()

// ASCII Values For 'A' to 'Z' => 65 to 90
#define CHAR_ALPHABET_UPPER_CASE_BEGINNING 65
#define CHAR_ALPHABET_UPPER_CASE_ENDING 90

// ASCII Values For 'a' to 'z' => 97 to 122
#define CHAR_ALPHABET_LOWER_CASE_BEGINNING 97
#define CHAR_ALPHABET_LOWER_CASE_ENDING 122

// ASCII Values For '0' to '9' => 48 to 57
#define CHAR_DIGIT_BEGINNING 48
#define CHAR_DIGIT_ENDING 57


int main(void)
{
	// Variable Declarations
	char ch_nkk;
	int ch_value_nkk;

	// Code
	printf("\n\n");

	printf("Enter Character : ");
	ch_nkk = getch();

	printf("\n\n");

	if ((ch_nkk == 'A' || ch_nkk == 'a') || (ch_nkk == 'E' || ch_nkk == 'e') || (ch_nkk == 'I' || ch_nkk == 'i') || (ch_nkk == 'O' || ch_nkk == 'o') || (ch_nkk == 'U' || ch_nkk == 'u'))
	{
		printf("Character \'%c\' Entered By You, Is A VOWEL CHARACTER From The English Alphabet !!!\n\n", ch_nkk);
	}
	
	else
	{
		ch_value_nkk = (int)ch_nkk;
		//If The Character Has ASCII VAlue Between 65 AND 90 OR Between 97 AND 122, It Is Still A Letter Of The Alphabet, But It Is A 'CONSONANT', and NOT a 'VOWEL'...
		if ((ch_value_nkk >= CHAR_ALPHABET_UPPER_CASE_BEGINNING && ch_value_nkk <= CHAR_ALPHABET_UPPER_CASE_ENDING) || (ch_value_nkk >= CHAR_ALPHABET_LOWER_CASE_BEGINNING && ch_value_nkk <= CHAR_ALPHABET_LOWER_CASE_ENDING))
		{
			printf("Character \'%c\' Entered By You, Is A CONSONANT CHARACTER From The English Alphabet !!!\n\n", ch_nkk);
		}

		else if (ch_value_nkk >= CHAR_DIGIT_BEGINNING && ch_value_nkk <= CHAR_DIGIT_ENDING)
		{
			printf("Character \'%c\' Entered By You, Is A DIGIT  CHARACTER !!!\n\n", ch_nkk);
		}

		else
		{
			printf("Character \'%c\' Entered By You, Is A SPECIAL CHARACTER !!!\n\n", ch_nkk);
		}
	}

	return(0);
}
