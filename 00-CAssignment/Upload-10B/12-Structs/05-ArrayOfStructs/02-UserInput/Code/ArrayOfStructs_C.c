#include <stdio.h>

#define NUM_EMPLOYEES 5 // Simply Change this constant value to have as many number of Employee Records as you please ....

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

struct Employee
{
	char name[NAME_LENGTH];
	int age;
	float salary;
	char sex;
	char marital_status;
};

int main(void)
{
	// Function Declarations
	void MyGetString(char[], int);

	// Variable Declarations
	struct Employee EmployeeRecords[NUM_EMPLOYEES]; // An Array <NUM_EMPLOYEES> 'struct Employee' - Each being type 'struct Employee'
	int i_nkk;

	// Code
	// ******** USER INPUT INITIALIZATION OF ARRAY OF 'struct Employee' ********
	for (i_nkk = 0; i_nkk < NUM_EMPLOYEES; i_nkk++)
	{
		printf("\n\n\n\n");
		printf("******** DATA ENTRY FOR EMPLOYEE NUMBER %d ********", (i_nkk + 1));

		printf("\n\n");
		printf("Enter Employee Name : ");
		MyGetString(EmployeeRecords[i_nkk].name, NAME_LENGTH);

		printf("\n\n\n");
		printf("Enter Employee's Age (in years) : ");
		scanf("%d", &EmployeeRecords[i_nkk].age);

		printf("\n\n");
		printf("Enter Employee's Sex (M/m For Male, F/f For Female) : ");
		EmployeeRecords[i_nkk].sex = getch();
		printf("%c", EmployeeRecords[i_nkk].sex);
		EmployeeRecords[i_nkk].sex = toupper(EmployeeRecords[i_nkk].sex);

		printf("\n\n\n");
		printf("Enter Employee's Salary (in Indian Rupees) : ");
		scanf("%f", &EmployeeRecords[i_nkk].salary);

		printf("\n\n");
		printf("Is The Employee Married? (Y/y For Yes, N/n For No) : ");
		EmployeeRecords[i_nkk].marital_status = getch();
		printf("%c", EmployeeRecords[i_nkk].marital_status);
		EmployeeRecords[i_nkk].marital_status = toupper(EmployeeRecords[i_nkk].marital_status);

	}


	// ******** DISPLAY ********
	printf("\n\n");
	printf("******** DISPLAYING EMPLOYEE RECORDS ********\n\n");
	for (i_nkk = 0; i_nkk < 5; i_nkk++)
	{
		printf("******** EMPLOYEE NUMBER %d ********\n\n", (i_nkk + 1));
		printf("Name				: %s\n", EmployeeRecords[i_nkk].name);
		printf("Age				: %d\n", EmployeeRecords[i_nkk].age);
		
		if (EmployeeRecords[i_nkk].sex == 'M')
			printf("Sex				: Male\n");
		else if (EmployeeRecords[i_nkk].sex == 'F')
			printf("Sex				: Female\n");
		else
			printf("Sex				: Invalid Data Entered\n");


		printf("Salary				: Rs. %f\n", EmployeeRecords[i_nkk].salary);
		
		if (EmployeeRecords[i_nkk].marital_status == 'Y')
			printf("Marital Status 			: Married\n");
		else if (EmployeeRecords[i_nkk].marital_status == 'N')
			printf("Marital Status 			: Unmarried\n");
		else
			printf("Marital Status : Invalid Data Entered\n");


		printf("\n\n");
	}

	return(0);
}

// ******** SIMPLE RUDIMENTARY IMPLEMENTATION OF gets_s() ********
// ******** IMPLEMENTED DUE TO DIFFERENT BEHAVIOUR OF gets_s() / fgets() / fscanf() ON DIFFERENT PLATFORMS ********
// ******** BACKSPACE / CHARACTER DELETION AND ARROW KEY CURSOR MOVEMENT NOT IMPLEMENTED ********

void MyGetString(char str[], int str_size)
{
	// Variable Declarations
	int i;
	char ch = '\0';

	// Code
	i = 0;
	do
	{
		ch = getch();
		str[i] = ch;
		printf("%c", str[i]);
		i++;
	} while ((ch != '\r') && (i < str_size));

	if (i == str_size)
		str[i - 1] = '\0';
	else
		str[i] = '\0';
}

