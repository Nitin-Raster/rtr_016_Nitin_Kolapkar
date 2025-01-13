#include <stdio.h>

enum
{
	NEGATIVE = -1,
	ZERO,
	POSITIVE
};

int main(void)
{
	// Function Declarations
	int Difference(int, int, int*);

	// Variable Declarations
	int a_nkk;
	int b_nkk;
	int answer_nkk, ret_nkk;

	//code
	printf("\n\n");
	printf("Enter Value Of 'A' : ");
	scanf("%d", &a_nkk);

	printf("\n\n");
	printf("Enter Value Of 'B' : ");
	scanf("%d", &b_nkk);

	ret_nkk = Difference(a_nkk, b_nkk, &answer_nkk);
	
	printf("\n\n");
	printf("Difference Of %d And %d = %d\n\n", a_nkk, b_nkk, answer_nkk);

	if (ret_nkk == POSITIVE)
		printf("The Difference Of %d And %d Is Positive !!!\n\n", a_nkk, b_nkk);

	else if (ret_nkk == NEGATIVE)
		printf("The Difference Of %d And %d Is Negative !!!\n\n", a_nkk, b_nkk);

	else
		printf("The Difference Of %d And %d Is Zero !!!\n\n", a_nkk, b_nkk);

	return(0);
}

// WE WANT OUR FUNCTION Difference() TO PERFORM 2 JOBS ...
// ONE, IS TO SUBTRACT THE INPUT NUMBERS ('y' FROM 'x') AND THE SECOND. IS TO TELL WHETHER THE DIFFERENCE OF 'x' AND 'y' IS POSITIVE OR NEGATIVE OR ZERO ...
// BUT ANY FUNCTION HAS ONLY ONE VALID RETURN VALUE, THEN HOW CAN WE MANAGE TO RETURN TWO VALUES TO THE CALLING FUNCTION?
// THIS IS WHERE PARAMETERIZED RETURN VALUES COMES INTO THE PICTURE ...
// WE CAN RETURN THE ACTUAL DIFFERENCE OF 'x' AND 'y', THAT IS, THE ACTUAL ANSWER VALUE. VIA OUT-PARAMETER / PARAMETERIZED RETURN VALUE 
// AND WE CAN RETURN THE STATUS OF THE ANSWER (POSITIVE / NEGATIVE / ZERO) VIA THE ACTUAL RETURN VALUE OF THE FUNCTION ...

int Difference(int x, int y, int* diff)
{
	// Code
	*diff = x - y;

	if (*diff > 0)
		return(POSITIVE);

	else if (*diff < 0)
		return(NEGATIVE);

	else
		return(ZERO);
}

