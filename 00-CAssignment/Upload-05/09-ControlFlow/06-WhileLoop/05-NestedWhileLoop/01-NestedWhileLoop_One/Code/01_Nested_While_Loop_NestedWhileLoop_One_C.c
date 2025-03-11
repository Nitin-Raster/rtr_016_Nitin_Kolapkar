#include<stdio.h>

int main(void)
{
	// Variable Declarations
	int i_nkk, j_nkk;

	// Code
	printf("\n\n");

	i_nkk = 1;
	while (i_nkk <= 10)
	{
		printf("i_nkk = %d", i_nkk);
		printf("--------------\n\n");

		j_nkk = 1;
		while (j_nkk <= 5)
		{
			printf("\tj_nkk = %d\n", j_nkk);
			j_nkk++;
		}
		i_nkk++;
		printf("\n\n");
	}

	return(0);
}