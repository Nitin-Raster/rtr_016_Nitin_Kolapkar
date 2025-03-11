#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int i_nkk, j_nkk, k_nkk;

	// Code
	printf("\n\n");

	i_nkk = 1;
	do
	{
		printf("i_nkk = %d\n", i_nkk);
		printf("----------\n");

		j_nkk = 1;
		do
		{
			printf("j_nkk = %d\n", j_nkk);
			printf("----------\n");
			k_nkk = 1;
			do
			{
				printf("\t\tk_nkk = %d\n", k_nkk);
				k_nkk++;
			} while (k_nkk <= 3);
			printf("\n\n");
			j_nkk++;
		} while (j_nkk <= 5);
		printf("\n\n");
		i_nkk++;
	} while (i_nkk <= 10);
	return(0);
}
