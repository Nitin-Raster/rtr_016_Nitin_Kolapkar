#include<stdio.h>

int main(void)
{
	// Variable Declarations
	int i_nkk, j_nkk, k_nkk;

	//Code
	printf("\n\n");
	for (i_nkk = 1; i_nkk <= 10; i_nkk++)
	{
		printf("i = %d\n", i_nkk);
		printf("-----------------------\n\n");
		for (j_nkk = 1; j_nkk <= 5; j_nkk++)
		{
			printf("\t j = %d\n", j_nkk);
			for (k_nkk = 1; k_nkk <= 3; k_nkk++)
			{
				printf("\t\t k = %d\n", k_nkk);
			}
			printf("\n\n");
		}
		printf("\n\n");
	}
	return(0);
}
