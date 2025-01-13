#include <stdio.h>

int main(void)
{
	// Variable Declarations
	float num_nkk;
	float *ptr_nkk = NULL; // Declaration Method 1 :- '*ptr' is a variable of type 'float'

	// Code
	num_nkk = 6.9f;

	printf("\n\n");

	printf(" ******** BEFORE ptr = &num ********\n\n");
	printf("Value Of 'num_nkk'						=%f\n\n", num_nkk);
	printf("Address Of 'num_nkk'						=%p\n\n", &num_nkk);
	printf("Value At Address Of 'num'					=%f\n\n", *(&num_nkk));

	// Assigning address of variable 'num' to pointer variable 'ptr'
	// 'ptr' now contains address of 'num' ...hence, 'ptr' is SAME as '&num_nkk'
	ptr_nkk = &num_nkk;

	printf("\n\n");

	printf(" ******** AFTER ptr = &num_nkk ********\n\n");
	printf("Value Of 'num'							= %f\n\n", num_nkk);
	printf("Address Of 'num'						= %p\n\n", ptr_nkk);
	printf("Value At Address Of 'num'					= %f\n\n", *ptr_nkk);

	return(0);
}