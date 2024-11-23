#include<stdio.h>

int main(void)
{
	// Function Prototypes
	void PrintBinaryFormOfNumber(unsigned int);

	//variable declarations
	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int result = 0;

	//code
	printf("\n\n");
	printf("Enter an Integer = ");
	scanf("%u", &a);

	printf("\n\n");
	printf("Enter Another Integer = ");
	scanf("%u", &b);

	printf("\n\n\n\n");
	result = a & b;
	printf("Bitwise AND-ing Of \nA = %d (Decimal) and B = %d (Decimal) gives results %d (Decimal). \n\n", a, b, result);

	PrintBinaryFormOfNumber(a);
	PrintBinaryFormOfNumber(b);
	PrintBinaryFormOfNumber(result);

	return(0);
}

// ****** BEGGINERS TO C PROGGRAMMING LANGUAGE : PLEASE IGNORE THE CODE OF THE FOLLOWING FUNCTION SNIPPET 'PrintBinaryFormOfNumber()' ******
// ****** YOU MAY COME BACK TO THIS CODE AND WILL UNDERSTAND IT MUCH BETTER AFTER YOU HAVE COVERED ARRAYS, LOOPS, AND FUNCTIONS ******
// ****** THE ONLY OBJECTIVE OF WRITING THIS FUNCTION WAS TO OBTAIN THE BINARY REPRESENTATION OF DECIMAL INTEGERS SO THAT BIT-WISE AND-ing, OR-ing, COMPLIMENT AND BIT-SHIFTING COULD BE UNDERSTOOD WITH GREAT ELSE ******

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
	// variable declarations 
	unsigned int quotient ,remainder = 0;
	unsigned int num = 0;
	unsigned int binary_array[8];
	int i = 0;

	// code 
	for (i = 0; i < 8; i++)
		binary_array[i] = 0;

	printf("The Binary Form of the Decimal Number %d Is \t=\t", decimal_number);
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
