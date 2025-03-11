#include <stdio.h>

int main(void)
{
	// Variable Declarations
	char option_nkk, ch_nkk = '\0';

	// Code
	printf("\n\n");
	printf("Once The Infinite Loop Begins, Enter 'Q' or 'q' To Quit The Infinite For Loop : \n\n");
	printf("Enter 'Y' or 'y' To Initiate User Controlled Infinite Loop : ");
	printf("\n\n");
	option_nkk = getch();
	if (option_nkk == 'Y' || option_nkk == 'y')
	{
		do
		{
			printf("In Loop...\n");
			ch_nkk = getch(); // Control Flow Waits For Character Input...
			if (ch_nkk == 'Q' || ch_nkk == 'q')
				break; // User Controlled Exitting From Infinite Loop 
		} while (1); //Infinite Loop

		printf("\n\n");
		printf("EXITTING USER CONTROLLED INFINITE LOOP...");
		printf("\n\n");

	}

	else
		printf("You Must Press 'Y' or 'y' To Initiate The User Controlled Infinite Loop... Please Try Again...\n\n");
	
	return(0);
}
