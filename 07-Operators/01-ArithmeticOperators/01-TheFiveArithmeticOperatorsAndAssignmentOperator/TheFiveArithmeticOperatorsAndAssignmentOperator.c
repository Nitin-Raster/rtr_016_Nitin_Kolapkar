#include<stdio.h>

int main(void)
{
	//variable declarations
	int a;
	int b;
	int result;
	
	//code
	printf("\n\n");
	printf("Enter a Number: ");
	scanf("%d", &a);
	
	printf("\n\n");
	printf("Enter another number: ");
	scanf("%d", &b);
	
	printf("\n\n");
	printf("\n\n");
	
	// *** The Following Are the 5 Arithmatic Operators +,-,*,/ and % ***
	// *** Also, The Resultants Of the Arithmatic Operations In All The Below Five Cases Have Been Assigned To The Variable 'result' Using The Assignment Operator (=) ***
	
	result = a + b;
	printf("Addition of A = %d And B = %d Gives %d. \n", a, b, result);
	
	result = a - b;
	printf("Substraction of A = %d And B = %d Gives %d. \n", a, b, result);
	
	result = a * b;
	printf("Multiplication of A = %d And B = %d Gives %d. \n", a, b, result);
	
	result = a / b;
	printf("Division of A = %d And B = %d Gives Quotient %d. \n", a, b, result);
	
	result = a % b;
	printf("Division of A = %d And B = %d Gives Remainder %d. \n", a, b, result);
	
	printf("\n\n");
	
	return(0);
	
}