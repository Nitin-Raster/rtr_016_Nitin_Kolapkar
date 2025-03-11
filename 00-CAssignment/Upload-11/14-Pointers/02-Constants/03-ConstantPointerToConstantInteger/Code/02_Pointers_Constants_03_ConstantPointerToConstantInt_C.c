#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int num_nkk = 5;
	const int* const ptr_nkk = &num_nkk; // Read this line from right to left => "ptr is a constant (const) pointer (*) to integer (int) constant (const)."

	// Code
	printf("\n");
	printf("Current Value Of 'num' = %d\n", num_nkk);
	printf("Current 'ptr' (Address Of 'num') = %p\n", ptr_nkk);

	// The following line does NOT give error ... as we are modifying the value of the variable individually 
	num_nkk++;
	printf("\n\n");
	printf("After num++, value of 'num' = %d\n", num_nkk);


	// The following line gives error and is hence commented out.
	// We cannot alter the 'ptr' value as 'ptr' "is a constant pointer to constant integer"
	// With respect to the pointer, the value it points to is constant and the pointer itself is also constant.
	// Uncomment it and see the error.

	// ptr_nkk++;

	// The following line also give error and is hence commented out.
	// We cannot alter the value stored in 'ptr' as 'ptr' is a "A constant pointer to constant integer"
	// With respect to the pointer, the value it points to is constant and the pointer itself is also constant.
	// Uncoment it and see the error.

	// (*ptr_nkk)++;

	return(0);
}

//Conclusion :
// As "ptr" is a "constant pointer to a constant integer" - we cannot change the value stored at address "ptr" AND we cannot change the 'ptr' (Address) itself.
// We can change the value of the variable (num) individually - whose address is contained in "ptr".
// We cannot change the "the value at address of ptr" - we cannot change the value of "num" with respect to "ptr" => (*ptr)++ is NOT allowed
// We cannot change the value of 'ptr' => That is we cannot store a new address inside 'ptr' => So, ptr++ is NOT allowed


