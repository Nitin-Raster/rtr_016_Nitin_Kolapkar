#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// Entry-Point Function => main() => Valid Return Type (int) and 3 Parameters (int argc, char *argv[], char *envp[])
int main(int argc, char* argv[], char* envp[])
{
	// Function prototype / declaration / signature
	int MyAddition(void);

	// Variable Declarations :  local variables to main()
	int result_nkk = 0;

	// Code
	result_nkk =  MyAddition(); // Function Call

	printf("\n\n");
	printf("Sum_nkk = %d\n\n", result_nkk);
	return(0);
}

// ******* USER DEFINED FUNCTION : METHOD OF DEFINITION 2 ******
// ******* VALID (int) RETURN VALUE, NO PARAMETERS ******

int MyAddition(void) //function definition
{
	// Variable Declarations
	int a_nkk, b_nkk, sum_nkk;

	// Code
	printf("\n\n");
	printf("Enter an Integer Value For 'A' : ");
	scanf("%d", &a_nkk);

	printf("\n\n");
	printf("Enter an Integer Value For 'B' : ");
	scanf("%d", &b_nkk);

	sum_nkk = a_nkk + b_nkk;

	return(sum_nkk);
}
