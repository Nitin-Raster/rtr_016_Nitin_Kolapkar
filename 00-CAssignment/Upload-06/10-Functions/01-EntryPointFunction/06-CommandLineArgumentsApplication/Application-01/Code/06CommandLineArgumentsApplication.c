#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'
#include <ctype.h> // 'ctype.h' contains declarations of 'atoi()'
#include <stdlib.h> // 'stdlib.h' contains declarations of 'exit()'

int main(int argc, char *argv[], char *envp[])
{
	// Variable Declarations
	int i_nkk;
	int num_nkk;
	int sum_nkk = 0;

	// Code
	if (argc == 1)
	{
		printf("\n\n");
		printf("No Numbers Given For Addition !!! Exitting Now ...\n\n");
		printf("Usage : CommandLineArgumentsApplication <First Number> <Second Number> ...\n\n");
		exit(0);
	}

	// *** THIS PROGRAMS ADDS ALL COMMAND LINE ARGUMENTS GIVEN IN INTEGER FORM ONLY AND OUTPUTS THE SUM ***
	// *** DUE TO USE OF atoi(), ALL COMMAND LINE ARGUMENTS OF TYPES OTHER THAN 'int' ARE IGNORED ***

	printf("\n\n");
	printf("Eum Of All Integer Command Line Arguments Is : \n\n");
	for (i_nkk = 1; i_nkk < argc; i_nkk++) // Loo[ starts from i = 0 will result in 'argv[i]' = 'argv[0]' which is the name of the program itself i.e. '06CommandLineArgumentsApplication.exe'
	{
		num_nkk = atoi(argv[i_nkk]);
		sum_nkk = sum_nkk + num_nkk;
	}

	printf("Sum = %d\n\n", sum_nkk);

	return(0);
}
