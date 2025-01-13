#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int num_nkk = 5;
	const int* ptr_nkk = NULL; // Read this line from right to left => "ptr is a pointer (*) to integer (int) constant (const)."

	// Code
	ptr_nkk = &num_nkk;
	printf("\n");
	printf("Current Value Of 'num' = %d\n", num_nkk);
	printf("Current 'ptr' (Address Of 'num') = %p\n", ptr_nkk);

	// The following line does NOT give error ... as we are modifying the value of the variable individually 
	num_nkk++;
	printf("\n\n");
	printf("After num++, value of 'num' = %d\n", num_nkk);


	// The following line gives error and is hence commented out.
	// We cannot alter the value stored in "A pointer to constant integer"
	// With respect to the pointer, the value it points to should be constant.
	// Uncomment it and see the error.

	// (*ptr_nkk)++;

	// The following line does NOT give error
	// We do not get error because we are chatting the pointer (address).
	// The pointer is not constant. The value to which the [poiinter pointer points is constant.
	ptr_nkk++;

	printf("\n\n");
	printf("After ptr++, value of 'ptr' = %p\n", ptr_nkk);
	printf("Value at this new 'ptr' = %d\n", *ptr_nkk);
	printf("\n");
	return(0);
}

//Conclusion :
// As "ptr" is a "variable pointer to constant integer" - we can change the value of pointer "ptr".
// We can change the value of the variable (num) individually - whose address is contained in "ptr".
// So in short, we cannot change "the value at address of ptr" - we cannot change the value of "num" with respect to "ptr" - we cannot change the value of "num" with respect to "ptr" => (*ptr)++ is NOT allowed.
// But, we can change the address 'ptr' itself => so ptr++ is allowed.

