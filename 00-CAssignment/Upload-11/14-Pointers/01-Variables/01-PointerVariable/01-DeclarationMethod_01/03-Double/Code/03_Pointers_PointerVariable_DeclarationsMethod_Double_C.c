#include <stdio.h>

int main(void)
{
	// Variable Declarations
	double num_nkk;
	double *ptr_nkk = NULL; // Declaration Method 1 :- '*ptr' is a variable of type 'double'

	// Code
	num_nkk = 2.34343434f;

	printf("\n\n");

	printf(" ******** BEFORE ptr = &num ********\n\n");
	printf("Value Of 'num_nkk'						=%lf\n\n", num_nkk);
	printf("Address Of 'num_nkk'						=%p\n\n", &num_nkk);
	printf("Value At Address Of 'num'					=%lf\n\n", *(&num_nkk));

	// Assigning address of variable 'num' to pointer variable 'ptr'
	// 'ptr' now contains address of 'num' ...hence, 'ptr' is SAME as '&num_nkk'
	ptr_nkk = &num_nkk;

	printf("\n\n");

	printf(" ******** AFTER ptr = &num_nkk ********\n\n");
	printf("Value Of 'num'							= %lf\n\n", num_nkk);
	printf("Address Of 'num'						= %p\n\n", ptr_nkk);
	printf("Value At Address Of 'num'					= %lf\n\n", *ptr_nkk);

	return(0);
}