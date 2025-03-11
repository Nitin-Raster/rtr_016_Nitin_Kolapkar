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
	} data; // Declaring a Single struct variable of type 'struct MyData' locally ...

	// Variable Declarations
	int i_size_nkk;
	int f_size_nkk;
	int d_size_nkk;
	int struct_MyData_size_nkk;

	// Code
	// Assigning Data Values To The Data Members Of 'Struct MyData'
	data.i = 56;
	data.f = 6.456f;
	data.d = 8.654;

	// Displaying Values Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("DATA MEMBERS OF 'sruct MyData' ARE : \n\n");
	printf("i = %d\n", data.i);
	printf("f = %f\n", data.f);
	printf("d = %lf\n", data.d);

	// Calculating Sizes (In Bytes) Of The Data Members Of 'struct MyData'
	i_size_nkk = sizeof(data.i);
	f_size_nkk = sizeof(data.f);
	d_size_nkk = sizeof(data.d);

	// Displaying Sizes (In Bytes) Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("SIZES (in bytes) OF DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("Size Of 'i' = %d bytes\n", i_size_nkk);
	printf("Size Of 'f' = %d bytes\n", f_size_nkk);
	printf("Size Of 'd' = %d bytes\n", d_size_nkk);

	// Calculating Size (In Bytes) Of The Entire 'struct MyData'
	struct_MyData_size_nkk = sizeof(struct MyData); // can also give struct name -> sizeof(MyData)

	//Displaying Sizes (In Bytes) Of the entire 'struct MyData'
	printf("\n\n");
	printf("Size Of 'struct MyData' : %d bytes\n\n", struct_MyData_size_nkk);

	return(0);
}
