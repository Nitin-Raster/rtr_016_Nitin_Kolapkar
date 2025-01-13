#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// Entry-Point Function => main() => Valid Return Type (int) and 3 Parameters (int argc, char *argv[], char *envp[])
int main(int argc, char* argv[], char* envp[])
{
	// Function prototype / declaration / signature
	void MyAddition(int, int);

	// Variable Declarations :  local variables to main()
	int a_nkk, b_nkk = 0;

	// Code
	printf("\n\n");
	printf("Enter an Integer Value For 'A' : ");
	scanf("%d", &a_nkk);

	printf("\n\n");
	printf("Enter an Integer Value For 'B' : ");
	scanf("%d", &b_nkk);

	MyAddition(a_nkk, b_nkk); // Function Call

	return(0);
}

// ******* USER DEFINED FUNCTION : METHOD OF DEFINITION 3 ******
// ******* NO RETURN VALUE, VALID PARAMETER (int, int) ******

void MyAddition(int a, int b) //function definition
{
	// Variable Declarations :  local variables to MyAddition()
	int sum_nkk;


	sum_nkk = a + b;

	printf("\n\n");
	printf("Sum of %d And %d =  = %d\n\n", a, b, sum_nkk);

}
