#include <stdio.h>

#define MAX_NAME_LENGTH 100

struct Employee
{
	char name[MAX_NAME_LENGTH];
	unsigned int age;
	char gender;
	double salary;
};

struct MyData
{
	int i;
	float f;
	double d;
	char c;
};

int main(void)
{
	// Typedefs
	typedef struct Employee MY_EMPLOYEE_TYPE;
	typedef struct MyData MY_DATA_TYPE;

	// Variable Declarations
	struct Employee emp = {"Anthony", 34, 'M', 1000.00};
	MY_EMPLOYEE_TYPE emp_typedef = { "Gonsalves", 34, 'F', 1000.00 };

	struct MyData md = { 34, 34.34f, 34.343434, 'X' };
	MY_DATA_TYPE md_typedef;

	// Code
	md_typedef.i = 8;
	md_typedef.f = 8.8888f;
	md_typedef.d = 8.8888;
	md_typedef.c = 'A';

	printf("\n\n");
	printf("struct Employee : \n\n");
	printf("emp.name = %s\n", emp.name);
	printf("emp.age = %d\n", emp.age);
	printf("emp.gender = %c\n", emp.gender);
	printf("emp.salary = %lf\n", emp.salary);

	printf("\n\n");
	printf("MY_EMPLOYEE_TYPE : \n\n");
	printf("emp_typedef.name	= %s\n", emp_typedef.name);
	printf("emp_typedef.age		= %d\n", emp_typedef.age);
	printf("emp_typedef.gender	= %c\n", emp_typedef.gender);
	printf("emp_typedef.salary	= %lf\n", emp_typedef.salary);

	printf("\n\n");
	printf("struct MyData : \n\n");
	printf("md.i = %d\n", md.i);
	printf("md.f = %f\n", md.f);
	printf("md.d = %lf\n", md.d);
	printf("md.c = %c\n", md.c);

	printf("\n\n");
	printf("MY_DATA_TYPE : \n\n");
	printf("md_typedef.i = %d\n", md_typedef.i);
	printf("md_typedef.f = %f\n", md_typedef.f);
	printf("md_typedef.d = %lf\n", md_typedef.d);
	printf("md_typedef.c = %c\n", md_typedef.c);

	printf("\n\n");
	return(0);
}

