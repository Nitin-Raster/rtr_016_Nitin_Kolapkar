#include <stdio.h>

// DEFINING STRUCT
struct MyData
{
	int i;
	float f;
	double d;
	char c;
};

struct MyData data_nkk = { 9, 8.6f, 63.4569, 'P' };

int main(void)
{
	// Code
	// Dispalying Values of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("i = %d\n", data_nkk.i);
	printf("f = %f\n", data_nkk.f);
	printf("d = %lf\n", data_nkk.d);
	printf("c = %c\n", data_nkk.c);

	return(0);
}
