#include<stdio.h>
#include<conio.h>

int main(void)
{
	// Variable Declarations
	char option, ch_nkk = '\0';

	// Code 
	printf("\n\n");

	printf("Once The Infinite Loop Begins, Enter 'Q' or 'q' To Quit The Infinite While Loop : \n\n");
	printf("Enter 'Y' or 'y' To Initiate User Controlled Infinite Loop : \n\n");
	printf("\n\n");

	option = getch();
	if (option == 'Y' || option == 'y')
	{
		while (1)
		{
			printf("In Loop...\n");
			ch_nkk = getch();
			if (ch_nkk == 'Q' || ch_nkk == 'q')
				break; // User Controlled Exitting From Infinite Loop
		}

		printf("\n\n");
		printf("EXITTING USER CONTROLLED INFINITE LOOP...");
		printf("\n\n");
	}

	else
		printf("You Must Press 'Y' or 'y' To Initiate The User Controlled Infinite Loop.... Please Try Again...\n\n");

	return(0);
}
