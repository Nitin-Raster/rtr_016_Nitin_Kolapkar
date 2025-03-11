#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int i_nkk, j_nkk;

	// Code
	printf("\n\n");

	i_nkk = 1;
	do
	{
		printf("i_nkk = %d\n", i_nkk);
		printf("----------\n\n");

		j_nkk = 1;
		do
		{
			printf("\tj_nkk = %d\n", j_nkk);
			j_nkk++;
		} while (j_nkk <= 5);
		i_nkk++;
		printf("\n\n");
	} while (i_nkk <= 10);
	return(0);
}
