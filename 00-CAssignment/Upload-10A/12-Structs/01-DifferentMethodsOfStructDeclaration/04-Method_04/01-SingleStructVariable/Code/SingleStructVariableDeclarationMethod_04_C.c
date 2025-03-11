#include <stdio.h>

// DEFINING STRUCT
struct MyData
{
	int i;
	float f;
	double d;
};

int main(void)
{
	// Variable Declarations
	struct MyData data_nkk; // Declaring a single struct variable of type 'struct Mydata' locally ...
	int i_size;
	int f_size;
	int d_size;
	int struct_MyData_size;

	// Code
	// Assigning Data Values To The Data Members Of 'struct MyData'
	data_nkk.i = 77;
	data_nkk.f = 66.77f;
	data_nkk.d = 8.12364;

	// Dispalying Values Of The Data Memebrs Of 'struct Mydata'
	printf("\n\n");
	printf("DATA MEMEBERS Of 'struct MyData' ARE: \n\n");
	printf("i = %d\n", data_nkk.i);
	printf("f = %f\n", data_nkk.f);
	printf("d = %lf\n", data_nkk.d);

	//Calculating Sizes (In Bytes) Of The Data Members Of 'struct MyData'
	i_size = sizeof(data_nkk.i);
	f_size = sizeof(data_nkk.f);
	d_size = sizeof(data_nkk.d);

	//Displaying Sizes (In Bytes) Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("SIZES (in bytes) OF DATA MEMENRS OF 'struct MyData' ARE : \n\n");
	printf("Size of 'i' = %d bytes\n", i_size);
	printf("Size of 'f' = %d bytes\n", f_size);
	printf("Size of 'd' = %d bytes\n", d_size);

	// Calculating Size (In Bytes) Of The entire 'struct MyData'
	struct_MyData_size = sizeof(struct MyData); // can also give struct name -> sizeof(MyData)

	// Displaying Sizes (In Bytes) Of the entire 'struct MyData'
	printf("\n\n");
	printf("Size Of 'struct MyData' :%d bytes\n\n", struct_MyData_size);

	return(0);
}

