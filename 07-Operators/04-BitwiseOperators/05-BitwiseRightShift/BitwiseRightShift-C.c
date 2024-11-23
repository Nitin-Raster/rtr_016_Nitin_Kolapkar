#include<stdio.h>

int main(void)
{
	// Function Prototypes
	void PrintBinaryFormOfNumber(unsigned int);

	// Variable Declarations 
	unsigned int a;
	unsigned int num_bits;
	unsigned int result;

	// Code
	printf("\n\n");
	printf("Enter An Integer = ");
	scanf("%u", &a);

	printf("\n\n");
	printf("By How Many Bits Do You Want To Shift A = %d To The Right?", a);
	scanf("%u", &num_bits);

	printf("\n\n\n\n");
	result = a >> num_bits;
	printf("Bitwise RIGHT-SHIFTing A = %d By %d Bits \nGives The Result = %d (Decimal). \n\n", a, num_bits, result);
	PrintBinaryFormOfNumber(result);

	return(0);
}

// ****** BEGINNERS TO C PROGRAMMING LANGUAGE : PLEASE IGNORE THE CODE OF THE FILLOWING FUNCTION SNIPPET 'PrintBinaryFormOfNumber()' ******
// ****** YOU MAY COMEBACK TO THIS CODE AND WILL UNDERSTAND IT MUCH BETTER AFTER YOU HAVE COVERED : AARAYS, LOOPS AND FUNCTIONS ******
// ****** THE ONLY OBJECTIVE OF TWRITING THIS FUNCTION WAS TO OBTAIN THE BINARY REPRESENTATION OF DECIMAL INTEGERS SO THAT BIT-WISE AND-ing, OR-ing, COMPLEMENT AND BIT-SHIFTING COULD BE UNDERSTOOD WITH GREAT EASE ******

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
	// Variable Declarations 
	unsigned int quotient, remainder;
	unsigned int number;
	unsigned int binary_array[8];
	int iCounter;

	// Code
	for (iCounter = 0; iCounter < 8; iCounter++)
		binary_array[iCounter] = 0;

	printf("The Binary Form Of The Decimal Integer %d Is \t=\t", decimal_number);
	number = decimal_number;
	iCounter = 7;
	while (number != 0)
	{
		quotient = number / 2;
		remainder = number % 2;
		binary_array[iCounter] = remainder;
		number = quotient;
		iCounter--;
	}

	for (iCounter = 0; iCounter < 8; iCounter++)
		printf("%u", binary_array[iCounter]);

	printf("\n\n");
}
