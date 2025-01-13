#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int num_nkk;
	int* ptr_nkk = NULL;
	int ans_nkk;

	// Code
	num_nkk = 5;
	ptr_nkk = &num_nkk;

	printf("\n\n");
	printf(" num_nkk		= %d\n", num_nkk);
	printf(" &num_nkk		= %p\n", &num_nkk);
	printf(" *(&num_nkk)	= %d\n", *(&num_nkk));
	printf(" ptr_nkk		= %p\n", ptr_nkk);
	printf(" *ptr_nkk		= %d\n", *ptr_nkk);

	printf("\n\n");


	// Add 10 to 'ptr' which is the address of 'num' ...
	// Hence, 10 will be loaded to the address of 'num' and the resultant address will be displayed
	printf("Answer Of (ptr_nkk + 10)	= %p\n", (ptr_nkk + 10));
	

	// Add 10 to 'ptr' which is the address of 'num' and give value at the new address will be displayed
	// Hence, 10 will be added tp yhe address of 'num' and the value at resultant address will be displayed
	printf("Answer Of *(ptr_nkk + 10) = %p\n", *(ptr_nkk + 10));


	// Add 10 to '*ptr' which is the value at address of 'num' (i.e. : 'num' i.e. 5) and give new value. without any change in any address ...
	// Hence, 10 will be added to the '*ptr' (num = 5) and the resultant value will be given(*ptr + 10) = (num +10) = (5 + 10) = 15 ...
	printf("Answer Of (*ptr_nkk + 10) = %d\n\n", (*ptr_nkk + 10));


	// ******* ASSOCIATIVITY OF * (VALUE AT ADDRESS) AND ++ AND -- OPERATOR IS FROM RIGHT TO LEFT *******


	// (RIGHT TO LEFT) consider value *ptr ... Pre-increment *ptr ... That is, value at address 'ptr' i.e. *ptr is pre-incremented (++*ptr)
	++*ptr_nkk; // *ptr is pre-incremented ... *ptr is 5 ... after execution of this statement /// *ptr = 6
	printf("Answer Of ++*ptr_nkk : %d\n", *ptr_nkk); // Brackets not necessary for pre-increment / pre-decrement


	// ( RIGHT TO LEFT ) Post-Increment address ptr ... That is, address 'ptr' i.e.: ptr is post-incremented (ptr++) and then the value at the new address is displayed (*ptr++)...
	*ptr_nkk++; // Incorrect method of post-incrementing a value using pointer ...
	printf("Answer of *ptr++ : %d\n", *ptr_nkk); // Brackets are necessary for post-increment/ post-decrement


	// (RIGHT TO LEFT) Post-increment value *ptr ... That is, Value at address 'ptr' i.e.: *ptr is post-incremented (*ptr)++
	ptr_nkk = &num_nkk;
	(*ptr_nkk)++; // Correct method of post-incrementing a value using pointer ... *ptr is 6 ... at this statement *ptr remains 6 but at next statement *ptr = 7 (post-increment)
	printf("Answer Of (*ptr)++ : %d\n\n", *ptr_nkk); // Brackets are necessary for post=increment / post-decrement

	return(0);
}
