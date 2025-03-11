#include<stdio.h>

int main(void)
{
	// Variable Declarations
	int i_nkk, j_nkk, c_nkk;

	// Code
	printf("\n\n");

	i_nkk = 0;
	while (i_nkk < 64)
	{
		j_nkk = 0;
		while (j_nkk < 64)
		{
			c_nkk = ((i_nkk & 0x8) == 0) ^ ((j_nkk & 0x8) == 0);

			if (c_nkk == 0)
				printf("  ");
			
			if (c_nkk == 1)
				printf("* ");

			j_nkk++;
		}
		printf("\n\n");
		i_nkk++;
	}

	return(0);
}