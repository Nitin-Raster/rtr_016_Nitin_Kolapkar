#include<stdio.h>

int main(void)
{
	//Variable Declarations
	int i_nkk, j_nkk;

	//Code
	printf("\n\n");

	for (i_nkk = 1; i_nkk <= 10; i_nkk++)
	{
		printf("i_nkk = %d\n", i_nkk);
		printf("------------------\n\n");
		for (j_nkk = 1; j_nkk <= 5; j_nkk++)
		{
			printf("\tj_nkk = %d\n", j_nkk);
		}
		printf("\n\n");
	}

	return(0);
}
