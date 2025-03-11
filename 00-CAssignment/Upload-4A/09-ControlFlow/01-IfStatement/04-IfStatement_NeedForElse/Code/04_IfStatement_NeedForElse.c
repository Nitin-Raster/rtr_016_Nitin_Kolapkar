#include<stdio.h>
int main(void)
{
	// Variable Declarations 
	int age_nkk;

	// Code
	printf("\n\n");
	printf("Enter Age : ");
	scanf("%d", &age_nkk);
	if (age_nkk >= 18)
	{
		printf("You are Eligible For Voting !!!\n\n");
	}
	printf("You Are NOT Eligible For Voting !!!\n\n");

	return(0);
}