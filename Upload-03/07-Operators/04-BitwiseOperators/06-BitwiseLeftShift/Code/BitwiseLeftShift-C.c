#include<stdio.h>

int main(void)
{
	// Function Prototypes
	void PrintBinaryFormOfNumber(unsigned int);

	// Variable Declarations
	unsigned int number_1 = 0;
	unsigned int num_bits = 0;
	unsigned int result = 0;

	// Code
	printf("\n\n");
	printf("Enter An Integer = ");
	scanf("%u", &number_1);

	printf("By How Many Bits Do You Want To Shift A = %d To The Left ?", number_1);
	scanf("%u", &num_bits);

	printf("\n\n\n\n");
	result = number_1 << num_bits;
	printf("Bitwise LEFT-SHIFT By %d Bits Of A = %d \nGives The Result = %d (Decimal).\n\n", num_bits, number_1, result);
	PrintBinaryFormOfNumber(number_1);
	PrintBinaryFormOfNumber(result);

	return(0);
}

// ****** BEGINNERS TO C PROGRAMMING LANGUAGE : PLEASE IGNORE THE CODE OF THE FOLLOWING FUNCTION SNIPPET 'PrintBinaryFormOfNumber()' ******
// ****** YOU MAY COME BACK TO THIS CODE AND WILL UNDERSTAND IT MUCH BETTER AFTER YOU HAVE COVERED : ARRAYS, LOOPS AND FUNCTIONS ******
// ****** THE ONLY OBJECTIVE OF WRITING THIS FUNCTION WAS TO OBTAIN THE BINARY REPRESENTATION OF DECIMAL INTEGERS SO THAT BIT-WISE AND-ing, OR-ing, COMPLEMENT AND BIT-SHIFTING COULD BE UNDERSTOOD WITH GREAT EASE ******

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
	// Variable Declarations
	unsigned int quotient, remainder = 0;
	unsigned number = 0;
	unsigned int binary_array[8];
	int iCounter = 0;

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
