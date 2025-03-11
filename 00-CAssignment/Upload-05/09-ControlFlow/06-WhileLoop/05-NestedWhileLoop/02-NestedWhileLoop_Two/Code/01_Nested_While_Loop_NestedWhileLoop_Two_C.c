#include<stdio.h>

int main(void)
{
	// Variable Declarations
	int i_nkk, j_nkk, k_nkk;

	// Code
	printf("\n\n");

	i_nkk = 1;
	while (i_nkk <= 10)
	{
		printf("i_nkk = %d\n", i_nkk);
		printf("--------------\n\n");

		j_nkk = 1;
		while (j_nkk <= 5)
		{
			printf("\tj_nkk = %d\n", j_nkk);
			printf("\t--------------\n\n");

			k_nkk = 1;
			while (k_nkk <= 3)
			{
				printf("\tk_nkk = %d\n", k_nkk);
				k_nkk++;
			}
			printf("\n\n");
			j_nkk++;

		}
		printf("\n\n");
		i_nkk++;
	}

	return(0);
}