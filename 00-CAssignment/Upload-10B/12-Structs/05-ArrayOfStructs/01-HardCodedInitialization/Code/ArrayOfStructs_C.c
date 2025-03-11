#include <stdio.h>

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

struct Employee
{
	char name[NAME_LENGTH];
	int age;
	float salary;
	char sex;
	char marital_status[MARITAL_STATUS];
};

int main(void)
{
	// Variable Declarations
	struct Employee EmployeeRecords[5]; // An Array of 5 structs - Each being type 'struct Employee'

	char employee_Advait[] = "Advait";
	char employee_Drishta[] = "Drishta";
	char employee_Gautam[] = "Gautam";
	char employee_Mahaveer[] = "Mahaveer";
	char Employee_Shunya[] = "Shunya";

	int i_nkk;

	// Code
	// ******** HARD-CODED INITIALIZATION OF ARRAY OF 'struct Employee' ********

	// ******** EMPLOYEE 1 ********
	strcpy(EmployeeRecords[0].name, employee_Advait);
	EmployeeRecords[0].age = 34;
	EmployeeRecords[0].sex = 'M';
	EmployeeRecords[0].salary = 464654564;
	strcpy(EmployeeRecords[0].marital_status, "Unmarried");

	// ******** EMPLOYEE 2 ********
	strcpy(EmployeeRecords[1].name, employee_Drishta);
	EmployeeRecords[1].age = 35;
	EmployeeRecords[1].sex = 'M';
	EmployeeRecords[1].salary = 565522;
	strcpy(EmployeeRecords[1].marital_status, "Unmarried");

	// ******** EMPLOYEE 3 ********
	strcpy(EmployeeRecords[2].name, employee_Gautam);
	EmployeeRecords[2].age = 36;
	EmployeeRecords[2].sex = 'M';
	EmployeeRecords[2].salary = 979874564;
	strcpy(EmployeeRecords[2].marital_status, "Unmarried");

	// ******** EMPLOYEE 4 ********
	strcpy(EmployeeRecords[3].name, employee_Mahaveer);
	EmployeeRecords[3].age = 36;
	EmployeeRecords[3].sex = 'M';
	EmployeeRecords[3].salary = 651231321213;
	strcpy(EmployeeRecords[3].marital_status, "Unmarried");

	// ******** EMPLOYEE 5 ********
	strcpy(EmployeeRecords[4].name, Employee_Shunya);
	EmployeeRecords[4].age = 36;
	EmployeeRecords[4].sex = 'M';
	EmployeeRecords[4].salary = 0;
	strcpy(EmployeeRecords[4].marital_status, "Unmarried");

	// ******** DISPLAY ********
	printf("\n\n");
	printf("******** DISPLAYING EMPLOYEE RECORDS ********\n\n");
	for (i_nkk = 0; i_nkk < 5; i_nkk++)
	{
		printf("******** EMPLOYEE NUMBER %d ********\n\n", (i_nkk + 1));
		printf("Name				: %s\n", EmployeeRecords[i_nkk].name);
		printf("Age				: %d\n", EmployeeRecords[i_nkk].age);
		
		if(EmployeeRecords[i_nkk].sex == 'M' || EmployeeRecords[i_nkk].sex == 'm')
			printf("Sex				: Male\n");
		else
			printf("Sex				: Female\n");

		printf("Salary				: Rs. %f\n", EmployeeRecords[i_nkk].salary);
		printf("Marital Status 			: %s\n", EmployeeRecords[i_nkk].marital_status);

		printf("\n\n");
	}

	return(0);
}
