#include <stdio.h>

int main(void)
{
	// Function Declarations
	void MathematicalOperations(int, int, int*, int*, int*, int*, int*);

	// Variable Declarations
	int a_nkk;
	int b_nkk;
	int answer_sum_nkk;
	int answer_difference_nkk;
	int answer_product_nkk;
	int answer_quotient_nkk;
	int answer_remainder_nkk;

	//code
	printf("\n\n");
	printf("Enter Value Of 'A' : ");
	scanf("%d", &a_nkk);

	printf("\n\n");
	printf("Enter Value Of 'B' : ");
	scanf("%d", &b_nkk);

	// PASSING ADDRESSES TO FUNCTION ... FUNCTION WILL FILL THEM UP WITH VALUES ... HENCE, THEY GO INTO THE FUNCTION AS ADDRESS PARAMETERS AND COME OUT OF THE FUNCTION FILLED WITH VALID VALUES
	// THUS, (&answer_sum_nkk, &answer_difference_nkk, &answer_product_nkk, &answer_quotient_nkk, &answer_remainder_nkk) ARE CALLED "OUT PARAMETERS" OR "PARAMETERIZED RETURN VALUES" ... RETURN VALUES OF FUNCTIONS COMING VIA PARAMETERS
	// HENCE, ALTHOUGH EACH FUNCTION HAS ONLY ONE RETURN VALUE, USING THE CONCEPT OF "PARAMETERIZED RETURN VALUES", OUR FUNCTION "MathematicalOperations()" HAS GIVEN US 5 RETURN VALUES !!!

	MathematicalOperations(a_nkk, b_nkk, &answer_sum_nkk, &answer_difference_nkk, &answer_product_nkk, &answer_quotient_nkk, &answer_remainder_nkk);
	
	printf("\n\n");
	printf("******** RESULTS ******** : \n\n");
	printf("Sum = %d\n\n", answer_sum_nkk);
	printf("Difference = %d\n\n", answer_difference_nkk);
	printf("Product = %d\n\n", answer_product_nkk);
	printf("Quotient = %d\n\n", answer_quotient_nkk);
	printf("Remainder = %d\n\n", answer_remainder_nkk);
	return(0);
}

void MathematicalOperations(int x, int y, int* sum, int* difference, int* product, int* quotient, int* remainder)
{
	// Code
	*sum = x + y;	// Value at Address 'sum' = (x + y)
	*difference = x - y;	// Value at Address 'difference' = (x - y)
	*product = x * y;	// Value at Address 'product' = (x * y)
	*quotient = x / y;	// Value at Address 'quotient' = (x / y)
	*remainder = x % y;	// Value at Address 'remainder' = (x % y)
}
