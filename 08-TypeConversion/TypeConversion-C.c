#include<stdio.h>

int main(void)
{
	// Variable Declarations 
	int iNumber1, iNumber2;
	char ch_01, ch_02;

	int a, result_int;
	float fNumber1, result_float;

	int i_explicit;
	float f_explicit;

	// Code
	printf("\n\n");

	// INTERCONVERSION AND IMPLICIT TYPE CASTING BETWEEN 'char' AND 'int' TYPES....
	iNumber1 = 92;
	ch_01 = iNumber1;
	printf("I = %d\n", iNumber1);
	printf("Character 1 (after ch_01 = iNumber1) = %c\n\n", ch_01);

	ch_02 = 'Q';
	iNumber2 = ch_02;
	printf("iNumber2 (after iNumber2 = ch_02) = %d\n\n", iNumber2);

	//IMPLICIT CONVERSION OF 'int' TO 'float'...

	iNumber1 = 5;
	fNumber1 = 7.8f;
	result_float = iNumber1 + fNumber1;
	printf("Integer iNumber1 = %d And Floating-Point Number %f Added Gives Floating-Point Sum = %f\n\n", iNumber1, fNumber1, result_float);

	result_int = iNumber1 + fNumber1;
	printf("Integer a = %d And Floating-Point Number %f Added Gives Integer Sum = %d\n\n", iNumber1, fNumber1, result_int);

	//EXPLICIT TYPE-CASTING USING CAST OPERATOR...
	f_explicit = 30.121995f;
	i_explicit = (int)f_explicit;
	printf("Floating Point Number Which Will Be Type Casted Explicitly = %f\n", f_explicit);
	printf("Resultant Integer After Explicit Type Casting Of %f = %d\n\n", f_explicit, i_explicit);

	return(0);
}
