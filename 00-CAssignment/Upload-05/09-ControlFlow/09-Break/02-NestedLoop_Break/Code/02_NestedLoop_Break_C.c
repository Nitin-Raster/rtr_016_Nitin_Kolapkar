#include <stdio.h>
#include <conio.h>

int main(void)
{
	// Variable Declarations
	int i_nkk, j_nkk;

	//Code
	printf("\n\n");

	for (i_nkk = 1; i_nkk <= 20; i_nkk++)
	{
		for (j_nkk = 1; j_nkk <= 20; j_nkk++)
		{
			if (j_nkk > i_nkk)
			{
				break;
			}
			else
			{
				printf("* ");
			}
		}
		printf("\n");
	}
	printf("\n\n");
	return(0);
}