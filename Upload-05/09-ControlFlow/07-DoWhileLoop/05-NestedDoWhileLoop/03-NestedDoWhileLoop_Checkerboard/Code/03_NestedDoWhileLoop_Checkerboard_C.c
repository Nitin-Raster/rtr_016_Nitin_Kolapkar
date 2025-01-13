#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int i_nkk, j_nkk, c_nkk;

	//Code
	printf("\n\n");

	i_nkk = 0;
	do
	{
		j_nkk = 0;
		do
		{
			c_nkk = ((i_nkk & 0x8) == 0) ^ ((j_nkk & 0x8) == 0);

			if (c_nkk == 0)
				printf("  ");

			if (c_nkk == 1)
				printf("* ");

			j_nkk++;
		} while (j_nkk < 64);
		printf("\n\n");
		i_nkk++;
	} while (i_nkk < 64);

	return(0);
}

