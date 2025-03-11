#include <stdio.h>
#include <conio.h>

struct MyData
{
	int i;
	float f;
	double d;
	char ch;
};

int main(void)
{
	// Variable Declarations
	struct MyData data_nkk; // Declaring a single struct variable 

	// Code
	// User Input For Values Of Data Members Of 'struct MyData'
	printf("\n\n");

	printf("Enter Integer Value For Data Member 'i' Of 'struct MyData' : \n");
	scanf("%d", &data_nkk.i);

	printf("Enter Floating-Point Value For Data Member 'f' Of 'struct MyData' : \n");
	scanf("%f", &data_nkk.f);

	printf("Enter 'Double' Value For Data Member 'd' Of 'struct MyData' : \n");
	scanf("%lf", &data_nkk.d);

	printf("Enter Character Value For Data Member 'c' Of 'struct MyData' : \n");
	data_nkk.ch = getch();

	// Display Value Of Data Members Of 'struct MyData'
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("i = %d\n", data_nkk.i);
	printf("f = %f\n", data_nkk.f);
	printf("d = %lf\n", data_nkk.d);
	printf("c = %c\n", data_nkk.ch);

	return(0);
	//
}