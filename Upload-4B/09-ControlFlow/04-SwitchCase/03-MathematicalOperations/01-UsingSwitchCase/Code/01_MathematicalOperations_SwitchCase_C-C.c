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

	switch (option)
	{
	// FALL THROUGH CONSITION FOR 'A' and 'a'
	case 'A':
	case 'a':
		result_nkk = a_nkk + b_nkk;
		printf("Addition Of A = %d And B = %d Gives Result %d !!!\n\n", a_nkk, b_nkk, result_nkk);
		break;

	//FALL THOUGH CONSITION FOR 'S' and 's'
	case 'S':
	case 's':
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
		break;

	// FALL THROUGH CONSITION FOR 'M' and 'm'
	case 'M':
	case 'm':
		result_nkk = a_nkk * b_nkk;
		printf("Multiplication Of A = %d And B = %d Gives Result %d !!!\n\n", a_nkk, b_nkk, result_nkk);
		break;

	// FALL THROUGH CONSITION FOR 'D' and 'd'
	case 'D':
	case 'd':
		printf("Enter Option In Character : \n\n");
		printf("'Q' or 'q' or '/' For Quotient Upon Division : \n");
		printf("'R' or 'r' or '%%' For Remainder Upon Division : \n");

		printf("Enter Option : ");
		option_division = getch();

		printf("\n\n");

		switch (option_division)
		{
			// FALL THROUGH CONSITION FOR 'Q' and 'q' and '/'
		case 'Q':
		case 'q':
		case '/':
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
			break; // 'break' of case 'Q' or case 'q' or case '/'

			// FALL THOUGH CONSITION FOR 'R' and 'r' and '%'
		case 'R':
		case 'r':
		case '%':
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
			break;

		default: //'default' case for switch(option_division)
			printf("Invalid Character %c Entered For Division !!! Please Try Again... \n\n", option_division);
			break; // 'break' of 'default' of switch(option_division)

		} // ending curly brace of switch(option_division)

		break; // 'break' of case 'D' or case 'd'

	default: // 'default' case for switch (option)
		printf("Invalid Character %c Entered !!! Please Try Again... \n\n", option);
		break;
	} // ending curly brace of switch(option)

	printf("Switch Case Block Complete !!!\n");

	return(0);
}
