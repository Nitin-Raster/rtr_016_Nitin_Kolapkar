#include <stdio.h>
#include <conio.h>

int main(void)
{
	// Variable Declarations
	int i_nkk;
	char ch_nkk;

	//Code
	printf("\n\n");

	printf("Printing Even Numbers From 1 to 100 For Every User Input. Exitting the Loop When User Enters Characters 'Q' or 'q' To Exit Loop: \n\n");
	printf("Enter Character 'Q' or 'q' To Exit Loop: \n\n");

	for (i_nkk = 1; i_nkk <= 100; i_nkk++)
	{
		printf("\t%d\n", i_nkk);
		ch_nkk = getch();
		if (ch_nkk == 'Q' || ch_nkk == 'q')
		{
			break;
		}
	}

	printf("\n\n");
	printf("EXITTING LOOP...");
	printf("\n\n");

	return(0);
}