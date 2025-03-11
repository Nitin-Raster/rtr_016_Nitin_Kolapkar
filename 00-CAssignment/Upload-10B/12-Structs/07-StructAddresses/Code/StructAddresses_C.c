#include <stdio.h>

struct MyData
{
	int i;
	float f;
	double d;
	char c;
};

int main(void)
{
	// Variable Declarations
	struct MyData data_nkk;

	// Code
	// Assigning Data Values To The Data Members Of 'struct MyData'
	data_nkk.i = 34;
	data_nkk.f = 12.55f;
	data_nkk.d = 31.878989;
	data_nkk.c = 'A';

	// Displaying Values Of The Data Memebrs Of 'struct MyData'
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("i = %d\n", data_nkk.i);
	printf("f = %f\n", data_nkk.f);
	printf("d = %lf\n", data_nkk.d);
	printf("c = %c\n\n", data_nkk.c);

	printf("\n\n");
	printf("ADDRESSES OF DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("'i' Occupies Addresses From %p\n", &data_nkk.i);
	printf("'f' Occupies Addresses From %p\n", &data_nkk.f);
	printf("'d' Occupies Addresses From %p\n", &data_nkk.d);
	printf("'c' Occupies Addresses From %p\n\n", &data_nkk.c);

	printf("Starting Address Of 'struct MyData' variable 'data_nkk' = %p\n\n", &data_nkk);

	return(0);
}
