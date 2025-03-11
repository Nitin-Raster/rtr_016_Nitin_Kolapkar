#include<stdio.h>

int main(void)
{
	// Variable Declarations

	float f_nkk;
	float f_num = 1.7f; //Simply change this value ONLY to get different outputs...

	// code
	printf("\n\n");

	printf("Printing Numbers %f to %f : \n\n", f_num, (f_num * 10.0f));

	for (f_nkk = f_num; f_nkk <= (f_num * 10.0f); f_nkk = f_nkk + f_num)
	{
		printf("\t%f\n", f_nkk);
	}

	printf("\n\n");

	return(0);
}
