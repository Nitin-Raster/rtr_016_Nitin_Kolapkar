#include <stdio.h>

int main(void)
{
	// Variable declarations
	int num_nkk;
	int* ptr = NULL; // Declaration Method 2 :- 'ptr' is a variable of type 'int*'

	// Code
	num_nkk = 10;

	printf("\n\n");

	printf("******* BEFORE ptr = &num *******\n\n");
	printf("Value of 'num'				= %d\n\n", num_nkk);
	printf("Address of 'num'			= %p\n\n", &num_nkk);
	printf("Value At Address of 'num'	= %d\n\n", *(&num_nkk));

	// Assigning address of variable 'num' to pointer variable 'ptr'
	// 'ptr' now contains address of 'num' ... hence, 'ptr' is SAME as '&num'
	ptr = &num_nkk;

	printf(" ******** AFTER ptr = &num *********\n\n");
	printf("Value of 'num'							=%d\n\n", num_nkk);
	printf("Address of 'num'						=%p\n\n", ptr);
	printf("Value At Address Of 'num'				=%d\n\n", *ptr);

	return(0);

}
