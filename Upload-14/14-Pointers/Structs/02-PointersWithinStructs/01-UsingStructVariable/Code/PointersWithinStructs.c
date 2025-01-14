#include <stdio.h>

// DEFINING STRUCT
struct MyData
{
	int* ptr_i;
	int i;

	float* ptr_f;
	float f;

	double* ptr_d;
	double d;
};

int main(void)
{
	// Variable Declarations
	struct MyData data_nkk;

	// Code
	data_nkk.i = 8;
	data_nkk.ptr_i = &data_nkk.i;

	data_nkk.f = 8.222f;
	data_nkk.ptr_f = &data_nkk.f;

	data_nkk.d = 17.222;
	data_nkk.ptr_d = &data_nkk.d;

	printf("\n\n");
	printf("i = %d\n", *(data_nkk.ptr_i));
	printf("Address Of 'i' = %p\n", data_nkk.ptr_i);

	printf("\n\n");
	printf("f = %f\n", *(data_nkk.ptr_f));
	printf("Address Of 'f' = %p\n", data_nkk.ptr_f);

	printf("\n\n");
	printf("d = %lf\n", *(data_nkk.ptr_d));
	printf("Address Of 'd' = %p\n", data_nkk.ptr_d);

	return(0);
}
