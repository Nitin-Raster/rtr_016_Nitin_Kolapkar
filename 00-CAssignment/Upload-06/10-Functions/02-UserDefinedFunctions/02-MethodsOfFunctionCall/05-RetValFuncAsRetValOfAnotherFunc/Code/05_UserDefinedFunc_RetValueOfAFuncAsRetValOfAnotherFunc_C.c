#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	// Function prototypes OR declarations
	int MyAddition(int, int);

	// Variable Declarations
	int r_nkk;
	int num_01, num_02;

	// Code
	num_01 = 10;
	num_02 = 20;

	printf("\n\n");
	printf("%d + %d = %d\n", num_01, num_02, MyAddition(num_01, num_02));
	printf("\n\n");

	return(0);
}

// ****** Function Definition Of MyAddition() ******
int MyAddition(int a, int b) // Function Definition
{
	// Function prototype
	int Add();

	// Code

	return(add(a, b)); //Return Value Of Function Add() as return value of function MyAddition()
}

int add(int x, int y)
{
	// Code
	return(x + y);
}