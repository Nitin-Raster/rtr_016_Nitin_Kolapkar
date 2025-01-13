#include <stdio.h>

int main(void)
{
	// DEFINING STRUCT
	struct MyData
	{
		int i;
		float f;
		double d;
		char c;
	} data_nkk = { 8, 45.3f, 51.3256, 'N' };

	// Code
	// Dispalying Values of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("i = %d\n", data_nkk.i);
	printf("f = %f\n", data_nkk.f);
	printf("d = %lf\n", data_nkk.d);
	printf("c = %c\n\n", data_nkk.c);

	return(0);
}
