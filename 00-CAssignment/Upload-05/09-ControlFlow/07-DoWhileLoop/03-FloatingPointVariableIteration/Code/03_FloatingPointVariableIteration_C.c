#include <stdio.h>

int main(void)
{
	// Variable Declarations
	float f_nkk;
	float f_num = 1.7f; //Simply Change This Value ONLY to get Different Outputs...

	// Code
	printf("\n\n");

	printf("Printing Numbers %f to %f : \n\n", f_num, (f_num * 10.0f));

	f_nkk = f_num;
	do
	{
		printf("\t%f\n", f_nkk);
		f_nkk = f_nkk + f_num;
	} while (f_nkk <= (f_num * 10.0f));

	printf("\n\n");

	return(0);
}

