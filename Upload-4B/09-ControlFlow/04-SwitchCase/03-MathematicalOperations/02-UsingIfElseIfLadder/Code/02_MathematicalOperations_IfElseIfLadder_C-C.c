#include<stdio.h> //for printf()
#include<conio.h> // for getch()

int main(void)
{
	// Variable Declarations
	int a_nkk, b_nkk;
	int result_nkk;

	char option, option_division;

	// Code
	printf("\n\n");

	printf("Enter Value For 'A' : ");
	scanf("%d", &a_nkk);

	printf("Enter Value For 'B' : ");
	scanf("%d", &b_nkk);

	printf("Enter Option In Character : \n\n");
	printf("'A' or 'a' For Addition : \n");
	printf("'S' or 's' For Substraction : \n");
	printf("'M' or 'm' For Multiplication : \n");
	printf("'D' or 'd' For Division : \n\n");

	printf("Enter Option : ");
	option = getch();

	printf("\n\n");

	if (option == 'A' || option == 'a')
	{
		result_nkk = a_nkk + b_nkk;
		printf("Addition Of A = %d And B = %d Gives Result %d !!!\n\n", a_nkk, b_nkk, result_nkk);
	}

	else if (option == 'S' || option == 's')
	{
		if (a_nkk > b_nkk)
		{
			result_nkk = a_nkk - b_nkk;
			printf("Substraction Of B = %d And A = %d Gives Result %d !!!\n\n", b_nkk, a_nkk, result_nkk);
		}
		else
		{
			result_nkk = b_nkk - a_nkk;
			printf("Substraction Of A = %d And B = %d Gives Result %d !!!\n\n", a_nkk, b_nkk, result_nkk);
		}
	}

	else if (option == 'M' || option == 'm')
	{
		result_nkk = a_nkk * b_nkk;
		printf("Multiplication Of A = %d And B = %d Gives Result %d !!!\n\n", a_nkk, b_nkk, result_nkk);
	}

	else if (option == 'D' || option == 'd')
	{
		printf("Enter Option In Character : \n\n");
		printf("'Q' or 'q' or '/' For Quotient Upon Division : \n");
		printf("'R' or 'r' or '%%' For Remainder Upon Division : \n");

		printf("Enter Option : ");
		option_division = getch();

		printf("\n\n");

		if (option_division == 'Q' || option_division == 'q' || option_division == '/')
		{
			if (a_nkk > b_nkk)
			{
				result_nkk = a_nkk / b_nkk;
				printf("Division of A = %d By B = %d Gives Quotient = %d !!!\n\n", a_nkk, b_nkk, result_nkk);
			}
			else
			{
				result_nkk = b_nkk / a_nkk;
				printf("Division of B = %d By A = %d Gives Quotient = %d !!!\n\n", b_nkk, a_nkk, result_nkk);

			}
		}

		else if (option_division == 'R' || option_division == 'r' || option_division == '%')
		{
			if (a_nkk >= b_nkk)
			{
				result_nkk = a_nkk % b_nkk;
				printf("Division of A = %d by B = %d Gives Remainder = %d !!!\n\n", a_nkk, b_nkk, result_nkk);
			}
			else
			{
				result_nkk = b_nkk % a_nkk;
				printf("Division of B = %d by A = %d Gives Remainder = %d !!!\n\n", b_nkk, a_nkk, result_nkk);
			}
		}

		else
			printf("Invalid Character %c Entered For Division !!! Please Try Again... \n\n", option_division);
	}

	else
		printf("Invalid Character %c Entered !!! Please Try Again... \n\n", option);


	printf("If - Else If - Else Ladder Complete !!!\n");

	return(0);
}
