#include <stdio.h>


int main(void)
{
	// Variable Declarations
	char chArray_01_nkk[] = { 'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0'}; // Must give \0 Explicitly For Proper Initialization
	char chArray_02_nkk[9] = { 'W', 'E', 'L', 'C', 'O', 'M', 'E', 'S', '\0' }; // Must give \0 Explicitly For Proper Initialization
	char chArray_03_nkk[9] = { 'Y', 'O', 'U', '\0' }; // Must give \0 Explicitly For Proper Initialization
	char chArray_04_nkk[] = "To"; // \0 is assumed, Size is given as 3, although string has only 2 characters
	char chArray_05_nkk[] = "REAL TIME RENDERING BATCH OF 2024-25"; // \0 is assumed, Size is given as 37, although string has only 36 characters

	char chArray_WithoutNullTerminator[] = { 'H', 'e', 'l', 'l', 'o' };

	// Code
	printf("\n\n");

	printf("Size Of chArray_01_nkk : %lu\n\n", sizeof(chArray_01_nkk));
	printf("Size Of chArray_02_nkk : %lu\n\n", sizeof(chArray_02_nkk));
	printf("Size Of chArray_03_nkk : %lu\n\n", sizeof(chArray_03_nkk));
	printf("Size Of chArray_04_nkk : %lu\n\n", sizeof(chArray_04_nkk));
	printf("Size Of chArray_05_nkk : %lu\n\n", sizeof(chArray_05_nkk));

	printf("\n\n");

	printf("The Strings are : \n\n");
	printf("chArray_01_nkk : %s\n\n", chArray_01_nkk);
	printf("chArray_02_nkk : %s\n\n", chArray_02_nkk);
	printf("chArray_03_nkk : %s\n\n", chArray_03_nkk);
	printf("chArray_04_nkk : %s\n\n", chArray_04_nkk);
	printf("chArray_05_nkk : %s\n\n", chArray_05_nkk);

	printf("\n\n");

	printf("Size of chArray_WithoutNullTerminator : %lu\n\n", sizeof(chArray_WithoutNullTerminator));
	printf("chArray_WithoutNullTerminator : %s\n\n", chArray_WithoutNullTerminator); // Will Display garbage value at the end of string due to absence of \0

	return(0);
}