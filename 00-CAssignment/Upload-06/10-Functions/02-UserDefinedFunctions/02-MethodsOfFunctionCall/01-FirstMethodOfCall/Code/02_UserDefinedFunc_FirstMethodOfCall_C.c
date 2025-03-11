#include <stdio.h>

// ****** USER DEFINED FUNCTIONS : METHOD OF CALLING FUNCTION 1 ******
// ****** CALLING ALL FUNCTIONS IN main() DIRECTLY ******

// Entry-Point Function => main() => Valid Return Type (int) and 3 Parameters (int argc, char *argv[], char *envp[])

int main(int argc, char* argv[], char* envp[])
{
	// Function Prototypes OR Declarations
	void MyAddition(void);
	int MySubtraction(void);
	void MyMultiplication(int, int);
	int MyDivision(int, int);

	// Variable Declarations
	int result_substraction_nkk;
	int a_multiplication_nkk, b_multiplication_nkk;
	int a_division_nkk, b_division_nkk, result_division_nkk;

	// Code

	// *** ADDITION ***
	MyAddition(); // Function Call

	// *** SUBSTRACTION ***
	result_substraction_nkk = MySubtraction(); // Function Call
	printf("\n\n");
	printf("Substraction Yields Result = %d\n", result_substraction_nkk);

	// *** MULTIPLICATION ***
	printf("\n\n");
	printf("Enter Integer Value For 'A' For Multiplication : ");
	scanf("%d", &a_multiplication_nkk);

	printf("\n\n");
	printf("Enter Integer Value For 'B' For Multiplication : ");
	scanf("%d", &b_multiplication_nkk);

	MyMultiplication(a_multiplication_nkk, b_multiplication_nkk); // Function Call

	// ***DIVISION ***
	printf("\n\n");
	printf("Enter Integer Value For 'A' For Division : ");
	scanf("%d", &a_division_nkk);

	printf("\n\n");
	printf("Enter Integer Value For 'B' For Division : ");
	scanf("%d", &b_division_nkk);

	result_division_nkk = MyDivision(a_division_nkk, b_division_nkk); // Function Call
	printf("\n\n");

	printf("Division Of %d and %d Gives = %d (Quotient)\n", a_division_nkk, b_division_nkk, result_division_nkk);

	printf("\n\n");
	
	return(0);
	
}

// *** Function Definition Of MyAddition() ***
void MyAddition(void) // Function Definition
{
	// Variable Declarations : Local Variables to MyAddition()
	int a, b, sum;

	// Code
	printf("\n\n");
	printf("Enter Integer Value For 'A' For Addition : ");
	scanf("%d", &a);

	printf("\n\n");
	printf("Enter Integer Value For 'B' For Addition : ");
	scanf("%d", &b);

	sum = a + b;

	printf("\n\n");
	printf("Sum Of %d And %d = %d\n\n", a, b, sum);

}

// *** Function Definition Of MySubtraction() *****
int MySubtraction(void) // Function Definition
{
	// Variable Declarations : local variables to MySubtraction()
	int a, b, subtraction;

	// Code
	printf("\n\n");
	printf("Enter Integer Value For 'A' For Substraction : ");
	scanf("%d", &a);

	printf("\n\n");
	printf("Enter Integer Value For 'B' For Substraction : ");
	scanf("%d", &b);

	subtraction = a - b;
	return (subtraction);

}

// ***** Function Definition Of MyMultiplication() *****
void MyMultiplication(int a, int b) // Function Definition
{
	// Variable Declarations : Local variables to MyMultiplication()
	int multiplication;
	
	// Code
	multiplication = a * b;

	printf("\n\n");
	printf("Multiplication Of %d And %d = %d\n\n", a, b, multiplication);

}

// ***** Function Definition of MyDivision() ******
int MyDivision(int a, int b) // Function Definition
{
	// Variable Declaration of MyDivision
	int division_quotient;

	// Code
	if (a > b)
		division_quotient = a / b;
	else
		division_quotient = b / a;

	return(division_quotient);
}
