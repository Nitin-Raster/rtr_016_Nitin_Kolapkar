#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'
#include <stdlib.h> // 'stdlib.h' contains declarations of 'exit()'

int main(int argc, char *argv[], char *envp[])
{
	// Variable Declarations
	int i_nkk;

	// Code
	if (argc != 4) // Program name + first name + middle name + surname = 4 command line arguments are required
	{
		printf("\n\n");
		printf("Invalid Usage !!! Exitting Now ... \n\n");
		printf("Usage :  CommandLineArgumentsApplication <first name> <middle name> <surname> \n\n");
		exit(0);
	}

	// *** THIS PROGRAM PRINTS YOUR FULL NAME AS ENTERED IN THE COMMAND LINE ARGUMENTS ***
	printf("\n\n");
	printf("Your Full Name Is: ");
	for (i_nkk = 1; i_nkk < argc; i_nkk++) // Loop starts from i_nkk = 1 because, i_nkk = 0 will result in 'argv[i_nkk]' = 'argv[0]' which is the name of program itself i.e. '06_02_CommandLineArgumentsApplication.exe'
	{
		printf("%s ", argv[i_nkk]);
	}

	printf("\n\n");

	return(0);
}
