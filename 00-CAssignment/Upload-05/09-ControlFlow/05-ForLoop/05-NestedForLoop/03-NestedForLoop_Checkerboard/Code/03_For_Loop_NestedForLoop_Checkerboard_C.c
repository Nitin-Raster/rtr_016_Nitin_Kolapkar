#include<stdio.h>

int main(void)
{
	// Variable Declarations
	int i_nkk, j_nkk, c_nkk;

	// Code
	printf("\n\n");

	for (i_nkk = 0; i_nkk < 64; i_nkk++)
	{
		for (j_nkk = 0; j_nkk < 64; j_nkk++)
		{
			c_nkk = ((i_nkk & 0x8) == 0) ^ ((j_nkk & 0x8) == 0);

			if (c_nkk == 0)
				printf("  ");
			if (c_nkk == 1)
				printf("* ");
		}
		printf("\n\n");
	}
	return(0);
}
