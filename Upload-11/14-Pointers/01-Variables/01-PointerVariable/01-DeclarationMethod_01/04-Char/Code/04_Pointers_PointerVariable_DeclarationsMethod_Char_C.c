#include <stdio.h>

int main(void)
{
	// Variable Declarations
	char ch_nkk;
	char *ptr_nkk = NULL; // Declaration Method 1 :- '*ptr' is a variable of type 'char'

	// Code
	ch_nkk = 'A';

	printf("\n\n");

	printf(" ******** BEFORE ptr = &ch_nkk ********\n\n");
	printf("Value Of 'ch_nkk'						=%c\n\n", ch_nkk);
	printf("Address Of 'ch_nkk'						=%p\n\n", &ch_nkk);
	printf("Value At Address Of 'ch_nkk'					=%c\n\n", *(&ch_nkk));

	// Assigning address of variable 'ch' to pointer variable 'ptr'
	// 'ptr' now contains address of 'ch' ...hence, 'ptr' is SAME as '&ch_nkk'
	ptr_nkk = &ch_nkk;

	printf("\n\n");

	printf(" ******** AFTER ptr = &ch_nkk ********\n\n");
	printf("Value Of 'ch'							= %c\n\n", ch_nkk);
	printf("Address Of 'ch'							= %p\n\n", ptr_nkk);
	printf("Value At Address Of 'num'					= %c\n\n", *ptr_nkk);

	return(0);
}