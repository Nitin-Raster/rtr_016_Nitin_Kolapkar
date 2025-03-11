#include<stdio.h>

int main(void)
{
	// Function Prototypes
	void PrintBinaryFormOfNumber(unsigned int);

	// Variable Declarations
	unsigned int a;
	unsigned int result;

	// Code
	printf("\n\n");
	printf("Enter An Integer = ");
	scanf("%u", &a);

	printf("\n\n\n\n");
	result = ~a;
	printf("Bitwise COMPLEMENTING Of \n A = %d (Decimal) gives result %d (Decimal). \n\n", a, result);
	PrintBinaryFormOfNumber(a);
	PrintBinaryFormOfNumber(result);

	return(0);
}

// ****** BEGGINERS TO C PROGRAMMING LANGIAGE : PLEASE IGNORE THE CODE OF THE FOLLOWING FUNCTION SNIPPET 'PrintBinaryFormOfNumber()' ******
// ****** YOU MAY COME BACK TO THIS CODE AND WILL UNDERSTAND IT MUCH BETTER AFTER YOU HAVE COVERED : ARRAYS, LOOPS AND FUNCTIONS ******
// ****** THE ONLY OBJECTIVE OF WRITING THIS FUNCTION WAS TO OBTAIN THE BINARY REPRESENTATION OF DECIMAL INTEGERS SO THAT BIT-WISE AND-ing, OR-ing, COMPLEMENT and BIT-SHIFTING COULD BE UNDERSTOOD WITH EASE ******

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
	// variable declarations
	unsigned int quotient, remainder;
	unsigned int number;
	unsigned int binary_array[8];
	int i;

	// code
	for (i = 0; i < 8; i++)
		binary_array[i] = 0;

	printf("The Binary Form Of The Decimal Integer %d Is \t=\t", decimal_number);
	number = decimal_number;
	i = 7;
	while (number != 0)
	{
		quotient = number / 2;
		remainder = number % 2;
		binary_array[i] = remainder;
		number = quotient;
		i--;
	}

	for (i = 0; i < 8; i++)
		printf("%u", binary_array[i]);

	printf("\n\n");
}
