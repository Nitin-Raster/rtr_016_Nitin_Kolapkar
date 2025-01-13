#include <stdio.h>

// ****** GLOBAL SCOPE ******

int main(void)
{
	// Function Prototypes
	void change_count(void);

	// Variable Declarations
	extern int global_count_nkk;

	// Code
	printf("\n");
	printf("Value Of global_count_nkk before change_count() = %d\n", global_count_nkk);
	change_count();
	printf("Value Of global_count_nkk after change_count() = %d\n", global_count_nkk);
	printf("\n");
	return(0);
}

// ****** GLOBAL SCOPE ******
// global_count_nkk is a global variable.
// Since, it is declared before change_count(), it can be accessed and used as any ordinary global variable in change_count()
// Since, it is declared after main(), it must be first re-declared in main as external global variable by means of the 'extern' keyword and the type of the variable.
// Once this is done, it can be used as an ordinary global variable in main as well.

int global_count_nkk = 0;

void change_count(void) // Function Definition
{
	// Code
	global_count_nkk = 5;
	printf("Value Of global_count_nkk in change_count() = %d\n", global_count_nkk);
}
