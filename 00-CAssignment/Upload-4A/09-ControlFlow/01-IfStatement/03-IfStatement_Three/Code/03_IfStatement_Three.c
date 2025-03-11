#include<stdio.h>

int main(void)
{
	// Variable Declarations
	int num_nkk;

	// Code

	printf("\n\n");
	printf("Enter Value For 'num_nkk' : ");
	scanf("%d", &num_nkk);

	if (num_nkk < 0)
	{
		printf("Num_nkk = %d Is Less Than 0 (NEGATIVE).\n\n", num_nkk);
	}

	if ((num_nkk > 0) && (num_nkk <= 100))
	{
		printf("Num_nkk = %d Is Between 0 and 100.\n\n", num_nkk);
	}

	if ((num_nkk > 100) && (num_nkk <= 200))
	{
		printf("Num_nkk = %d Is Between 100 and 200.\n\n", num_nkk);
	}

	if ((num_nkk > 200) && (num_nkk <= 300))
	{
		printf("Num_nkk = %d Is Between 200 and 300.\n\n", num_nkk);
	}

	if ((num_nkk > 300) && (num_nkk <= 400))
	{
		printf("Num_nkk = %d Is Between 300 and 400.\n\n", num_nkk);
	}

	if ((num_nkk > 400) && (num_nkk <= 500))
	{
		printf("Num_nkk = %d Is Between 400 and 500.\n\n", num_nkk);
	}

	if (num_nkk > 500)
	{
		printf("Num_nkk = %d Is Greater Than 500.\n\n", num_nkk);
	}

	return(0);
}