#include <stdio.h>

int main(void)
{
	// Variable Declarations
	char option_nkk, ch_nkk = '\0';

	// Code
	printf("\n\n");
	printf("Once The Infinite Loop Begins, Enter 'Q' or 'q' To Quit The Infinite For Loop : \n\n");

	do
	{
		do
		{
			printf("\n");
			printf("In Loop...\n");
			ch_nkk = getch(); // Control Flow Waits For Character Input...
		} while (ch_nkk != 'Q' && ch_nkk != 'q');

		printf("\n\n");
		printf("EXITTING USER CONTROLLED INFINITE LOOP...");

		printf("\n\n");
		printf("DO YOU WANT TO BEGIN USER CONTROLLED INFINITE LOOP AGAIN?... (Y/y - Yes, Any Other Key - No : )");

		option_nkk = getch();
	} while (option_nkk == 'Y' || option_nkk == 'y');

	return(0);
}

