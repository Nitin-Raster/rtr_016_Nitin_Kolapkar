#include <stdio.h>

int main(void)
{
	// Variable Declaration
	int num_nkk;
	int* ptr_nkk = NULL;
	int** pptr_nkk = NULL; // Declaration Method 1 :- **pptr_nkk Is a Variable Of Type 'int' pointer to ponter

	// Code
	num_nkk = 10;

	printf("\n\n");

	printf("******** BEFORE ptr_nkk = &num_num");
	printf("Values of 'num_nkk'			= %d\n\n", num_nkk);
	printf("Address of 'num_nkk'			= %p\n\n", &num_nkk);
	printf("Value at Address of 'num_nkk'			= %d\n\n", *(&num_nkk));

	// Assigning address of variable 'num_nkk' to pointer variable 'ptr_nkk'
	// 'ptr_nkk' now contains address of 'num_nkk' ... hence, 'ptr_nkk' is SAME as '&num_nkk' 
	ptr_nkk = &num_nkk;

	printf("\n\n");

	printf("******** AFTER ptr_nkk = &num_num");
	printf("Values of 'num_nkk'			= %d\n\n", num_nkk);
	printf("Address of 'num_nkk'			= %p\n\n", ptr_nkk);
	printf("Value at Address of 'num_nkk'			= %d\n\n", *ptr_nkk);

	// Assigning address of variable of 'ptr_nkk' to pointer-to-pointer variable 'pptr_nkk'
	// 'pptr_nkk' now contains the address of 'ptr_nkk' which in turn contains the address of 'num_nkk'
	// Hence, 'pptr_nkk' is SAME as '&ptr'
	// 'ptr_nkk' is same as '&num_nkk'
	// Hence, pptr_nkk = &ptr_nkk = &(&num_ptr)
	// If ptr = &num & *ptr = *(&num) = value at address of 'num'
	// Then, pptr = &ptr and *pptr = *(&ptr) = ptr = value at address of 'ptr' i.e. 'ptr' i.e. address of 'num'
	// Then, **pptr = **(&ptr) = *(*(&ptr)) = *ptr = *(&ptr) = num = 10
	// Hence num = *(&num) = *ptr = *(*pptr) = **ptr

	pptr_nkk = &ptr_nkk;

	printf("\n\n");

	printf("******** AFTER pptr = &ptr ********\n\n");
	printf("Values of 'num_nkk'							= %d\n\n", num_nkk);
	printf("Address of 'num_nkk' (ptr)					= %p\n\n", ptr_nkk);
	printf("Address of 'ptr' (pptr)						= %p\n\n", pptr_nkk);
	printf("Value at Address of 'ptr' (*pptr) 			= %p\n\n", *pptr_nkk);
	printf("Value at Address of 'num_nkk' (*ptr) (*pptr) 				= %d\n\n", **pptr_nkk);

	return(0);
}