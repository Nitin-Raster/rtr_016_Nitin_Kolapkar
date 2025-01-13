#include <stdio.h>

struct Employee
{
	char name[100];
	int age;
	float salary;
	char sex;
	char marital_status;
};

int main(void)
{
	// Code
	printf("\n\n");
	printf("SIZES OF DATA TYPES AND POINTERS TP THOSE RESPECTIVE DATA TYPES ARE : \n\n");
	printf("Size Of (int)		: %d \t \t \t Size Of pointer to int (int*)			: %d\t \t \t Size of pointer to pointer to int (int**)			: %d\n\n", sizeof(int), sizeof(int*), sizeof(int**));
	printf("Size Of (float)		: %d \t \t \t Size Of pointer to float (float*)			: %d\t \t \t Size of pointer to pointer to float (float**)			: %d\n\n", sizeof(float), sizeof(float*), sizeof(float**));
	printf("Size Of (double)		: %d \t \t \t Size Of pointer to double (double*)			: %d\t \t \t Size of pointer to pointer to double (double**)			: %d\n\n", sizeof(double), sizeof(double*), sizeof(double**));
	printf("Size Of (char)		: %d \t \t \t Size Of pointer to char (char*)			: %d\t \t \t Size of pointer to pointer to char (char**)			: %d\n\n", sizeof(char), sizeof(char*), sizeof(char**));
	printf("Size Of (struct Employee)		: %d \t \t \t Size Of pointer to struct Employee (struct Employee*)			: %d\t \t \t Size of pointer to pointer to struct Employee (struct Employee**)			: %d\n\n", sizeof(struct Employee), sizeof(struct Employee*), sizeof(struct Employee**));

	return(0);
}
