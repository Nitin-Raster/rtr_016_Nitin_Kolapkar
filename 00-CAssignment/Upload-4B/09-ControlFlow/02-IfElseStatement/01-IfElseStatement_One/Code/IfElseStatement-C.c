#include<stdio.h>

int main(void)
{
	// Variable Declarations
	int a_nkk, b_nkk, p_nkk;

	//code
	a_nkk = 9;
	b_nkk = 30;
	p_nkk = 30;

	// *** FIRST if-else PAIR ***
	printf("\n\n");
	if (a_nkk < b_nkk)
	{
		printf("Entering First if-block...\n\n");
		printf("A Is Less Than B !!! \n\n");
	}
	else
	{
		printf("Entering First else-block... \n\n");
		printf("A Is NOT Less Than B!!!\n\n");
	}
	printf("First if-else PAir Done !!!\n\n");

	// *** SECOND if-else PAIR ***
	printf("\n\n");
	if (b_nkk != p_nkk)
	{
		printf("Entering Second if-block...\n\n");
		printf("B Is NOT Equal To P");
	}
	else
	{
		printf("Entering Second else-block\n\n");
		printf("B is Equal to P!!!\n\n");
	}
	printf("Second if-else Pair Done !!!\n\n");

	return(0);
}