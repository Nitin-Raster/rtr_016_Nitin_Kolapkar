//
// RecursivrFunction.c
//
//
// Created by ASTROMEDICOMP
//

#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	// Variable Declarations
	unsigned int num_nkk;

	// Function prototype
	void recursive(unsigned int);

	// Code
	printf("\n\n");
	printf("Enter Any Number : \n\n");
	scanf("%u", &num_nkk);

	printf("\n\n");
	printf("Output Of Recursive Function : \n\n");

	recursive(num_nkk);

	printf("\n\n");
	return(0);
}

void recursive(unsigned int n)
{
	// Code
	printf("n = %d\n", n);

	if (n > 0)
	{
		recursive(n - 1);
	}
}
