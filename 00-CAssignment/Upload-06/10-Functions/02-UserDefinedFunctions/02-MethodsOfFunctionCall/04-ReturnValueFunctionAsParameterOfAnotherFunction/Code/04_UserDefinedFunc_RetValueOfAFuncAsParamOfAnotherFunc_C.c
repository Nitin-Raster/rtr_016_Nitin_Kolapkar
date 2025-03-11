#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	// Function prototypes OR declarations
	int MyAddition(int, int);

	// Variable Declarations
	int r_nkk;
	int num_01, num_02;
	int num_03, num_04;

	// Code
	num_01 = 10;
	num_02 = 20;
	num_03 = 30;
	num_04 = 40;

	r_nkk = MyAddition(MyAddition(num_01, num_02), MyAddition(num_03, num_04)); // Return Value Of MyAddition Is Sent As Parameter to Another Call To MyAddition()

	printf("\n\n");
	printf("%d + %d + %d + %d = %d\n", num_01, num_02, num_03, num_04, r_nkk);
	printf("\n\n");

	return(0);
}

// ****** Function Definition Of MyAddition() ******
int MyAddition(int a, int b) // Function Definition
{
	// Variable Declarations
	int sum_nkk;

	// Code
	sum_nkk = a + b;
	return(sum_nkk);
}
