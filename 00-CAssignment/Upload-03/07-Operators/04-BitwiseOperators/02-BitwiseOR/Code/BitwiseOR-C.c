#include<stdio.h>

int main(void)
{
	// Function Prototypes
	void PrintBinaryFormOfNumber(unsigned int);

	// Variable declarations
	unsigned int a;
	unsigned int b;
	unsigned int result;

	// Code
	printf("\n\n");
	printf("Enter An Integer = ");
	scanf("%u", &a);

	printf("\n\n");
	printf("Enter Another Integer =");
	scanf("%u", &b);

	printf("\n\n\n\n");
	result = a | b;
	printf("Bitwise OR-ing Of \nA = %d (Decimal) and B = %d (Decimal) gives result %d (Decimal). \n\n", a, b, result);

	PrintBinaryFormOfNumber(a);
	PrintBinaryFormOfNumber(b);
	PrintBinaryFormOfNumber(result);

	return(0);
}


// ****** BEGGINNERS TO C PROGRAMMING LANGUAGE : PLEASE IGNORE THE CODE OF THE FILLOWING FUNCTION SNIPPET 'PrintBinaryFormOfNumber()' ******
// ****** THE ONLY OBJECTIVE OF WRITING THIS FUNCTION WAS TO OBTAIN THE BINARY REPRESENTATION OF DECIMAL INTEGERS SO THAT BIT-WISE AND-ing, OR-ing, COMPLEMENT AND BIT-SHIFTING COULD BE UNDERSTOOD WITH GREAT EASE ******

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
	// variable declarations
	unsigned int quotient, remainder;
	unsigned int num;
	unsigned int binary_array[8];
	int i;

	// code
	for (i = 0; i < 8; i++)
		binary_array[i] = 0;

	printf("The Binary Form Of The Decimal Integer %d Is\t=\t", decimal_number);
	num = decimal_number;
	i = 7;
	while (num != 0)
	{
		quotient = num / 2;
		remainder = num % 2;
		binary_array[i] = remainder;
		num = quotient;
		i--;
	}

	for (i = 0; i < 8; i++)
		printf("%u", binary_array[i]);

	printf("\n\n");
}
