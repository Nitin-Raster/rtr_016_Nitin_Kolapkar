#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// Entry-Point Function => main() => Valid Return Type (int) and 3 Parameters (int argc, char *argv[], char *envp[])
int main(int argc, char* argv[], char* envp[])
{
	// Function prototype / declaration / signature
	int MyAddition(int, int);

	// Variable Declarations :  local variables to main()
	int a_nkk, b_nkk, result_nkk = 0;

	// Code
	printf("\n\n");
	printf("Enter an Integer Value For 'A' : ");
	scanf("%d", &a_nkk);

	printf("\n\n");
	printf("Enter an Integer Value For 'B' : ");
	scanf("%d", &b_nkk);

	result_nkk = MyAddition(a_nkk, b_nkk); // Function Call

	printf("\n\n");
	printf("Sum of %d And %d =  = %d\n\n", a_nkk, b_nkk, result_nkk);

	return(0);
}

// ******* USER DEFINED FUNCTION : METHOD OF DEFINITION 4 ******
// ******* VALID (int) RETURN VALUE, VALID PARAMETER (int, int) ******

int MyAddition(int a, int b) //function definition
{
	// Variable Declarations :  local variables to MyAddition()
	int sum_nkk;

	// Code
	sum_nkk = a + b;
	return(sum_nkk);

}
