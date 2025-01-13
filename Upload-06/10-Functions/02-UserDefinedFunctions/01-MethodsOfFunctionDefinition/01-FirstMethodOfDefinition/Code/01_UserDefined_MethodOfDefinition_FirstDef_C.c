#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// Entry-Point Function => main() => Valid Return Type (int) and 3 Parameters (int argc, char *argv[], char *envp[])
int main(int argc, char* argv[], char* envp[])
{
	// Function prototype / declaration / signature
	void MyAddition(void);

	// Code
	MyAddition(); // Function Call
	return(0);
}

// ******* USER DEFINED FUNCTION : METHOD OF DEFINITION 1 ******
// ******* NO RETURN VALUE, NO PARAMETERS ******

void MyAddition(void) //function definition
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

	printf("\n\n");
	printf("Sum Of %d And %d = %d\n\n", a_nkk, b_nkk, sum_nkk);
}
