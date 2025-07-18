#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// Entry-Point Function => main() => Valid Return Type (int) and 2 Parameters (int argc, char *argv[])
int main(int argc, char *argv[])
{
	// Variable Declarations
	int i_nkk;

	// Code
	printf("\n\n");
	printf("Hello World !!!\n\n"); // Library Function
	printf("Number Of Command Line Arguments = %d\n\n", argc);

	printf("Command Line Arguments Passed To This Program Are: \n\n");
	for (i_nkk = 0; i_nkk < argc; i_nkk++)
	{
		printf("Command Line Argument Number %d = %s\n", (i_nkk + 1), argv[i_nkk]);
	}

	printf("\n\n");
	return(0);
}
