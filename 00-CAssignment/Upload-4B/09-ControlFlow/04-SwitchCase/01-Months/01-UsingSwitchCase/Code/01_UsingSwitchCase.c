#include<stdio.h>

int main(void)
{
	// Variable Declaration
	int num_month_nkk;

	// Code
	printf("\n\n");

	printf("Enter Number Of Month (1 to 12) :");
	scanf("%d", &num_month_nkk);

	printf("\n\n");

	switch (num_month_nkk)
	{
	case 1: //like 'if'
		printf("Month Number %d Is JANUARY !!!\n\n", num_month_nkk);
		break;

	case 2: //like 'else - if'
		printf("Month Number %d Is FEBRUARY !!!\n\n", num_month_nkk);
		break;

	case 3: //like 'else - if'
		printf("Month Number %d Is MARCH !!!\n\n", num_month_nkk);
		break;

	case 4: //like 'else - if'
		printf("Month Number %d Is APRIL !!!\n\n", num_month_nkk);
		break;

	case 5: //like 'else - if'
		printf("Month Number %d Is MAY !!!\n\n", num_month_nkk);
		break;

	case 6: //like 'else - if'
		printf("Month Number %d Is JUNE !!!\n\n", num_month_nkk);
		break;

	case 7: //like 'else - if'
		printf("Month Number %d Is JULY !!!\n\n", num_month_nkk);
		break;

	case 8: //like 'else - if'
		printf("Month Number %d Is AUGUST !!!\n\n", num_month_nkk);
		break;

	case 9: //like 'else - if'
		printf("Month Number %d Is SEPTEMBER !!!\n\n", num_month_nkk);
		break;

	case 10: //like 'else - if'
		printf("Month Number %d Is OCTOBER !!!\n\n", num_month_nkk);
		break;

	case 11: //like 'else - if'
		printf("Month Number %d Is NOVEMBER !!!\n\n", num_month_nkk);
		break;

	case 12: //like 'else - if'
		printf("Month Number %d Is DECEMBER !!!\n\n", num_month_nkk);
		break;

	default: //Like ending OPTIONAL 'else'... Just Like Terminating 'else' is Optional in If - Else If - ELSE Ladder, so is the 'default' case optional in switch - case
		printf("Invalid Month Number %d Entered !!! Please Try Again... \n\n", num_month_nkk);
		break;
	}

	printf("Switch Case Block Complete !!!\n");

	return(0);
}