#include <stdio.h>
#include <ctype.h>

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

struct Employee
{
	char name[NAME_LENGTH];
	int age;
	char sex;
	float salary;
	char marital_status;
};

int main(void)
{
	// Function Prototype
	void MyGetString(char[], int);

	// Variable Declarations
	struct Employee* pEmployeerecord_nkk = NULL;
	int num_employee_nkk, i;

	// Code
	printf("\n\n");
	printf("Enter Number of Employees Whose Details You Want To Record : ");
	scanf("%d", &num_employee_nkk);

	printf("\n\n");
	pEmployeerecord_nkk = (struct Employee*)malloc(sizeof(struct Employee) * num_employee_nkk);
	if (pEmployeerecord_nkk == NULL)
	{
		printf("FAILED TO ALLOCATE MEMORY FOR %d EMPLOYEES !!! EXITTING NOW... \n\n", num_employee_nkk);
		exit(0);
	}
	else
		printf("SUCCESSFULLY ALLOCATED MEMORY FOR %d EMPLOYEES !!! ", num_employee_nkk);

	// ******** USER INPUT INITIALIZATION OF ARRAY OF 'struct Employee' ********
	for (i = 0; i < num_employee_nkk; i++)
	{
		printf("\n\n\n\n");
		printf("********** DATA ENTRY FOR EMPLOYEE NUMBER %d **********\n", (i + 1));

		printf("\n\n");
		printf("Enter Employee Name : ");
		MyGetString(pEmployeerecord_nkk[i].name, NAME_LENGTH);

		printf("\n\n\n");
		printf("Enter Employee's Age (in yeard) : ");
		scanf("%d", &pEmployeerecord_nkk[i].age);

		printf("\n\n");
		printf("Enter Employee's Sex (M/m For Male, F/f For Female) : ");
		pEmployeerecord_nkk[i].sex = getch();
		printf("%c", pEmployeerecord_nkk[i].sex);
		pEmployeerecord_nkk[i].sex = toupper(pEmployeerecord_nkk[i].sex);

		printf("\n\n\n");
		printf("Enter Employee's Salary (in Indian Rupees) : ");
		scanf("%f", &pEmployeerecord_nkk[i].salary);

		printf("\n\n");
		printf("Is The Employee Married? (Y/y For Yes, N/n For No) : ");
		pEmployeerecord_nkk[i].marital_status = getch();
		printf("%c", pEmployeerecord_nkk[i].marital_status);
		pEmployeerecord_nkk[i].marital_status = toupper(pEmployeerecord_nkk[i].marital_status);
	}


	// ******** DISPLAY ********
	printf("\n\n\n\n");
	printf("******** DISPLAYING EMPLOYEE RECORD ********\n\n");
	for (i = 0; i < num_employee_nkk; i++)
	{
		printf("******** EMPLOYEE NUMBER %d ********\n\n", (i + 1));
		printf("Name			: %s\n", pEmployeerecord_nkk[i].name);
		printf("Age				: %d years\n", pEmployeerecord_nkk[i].age);

		if (pEmployeerecord_nkk[i].sex == 'M')
			printf("Sex			: Male\n");
		else if (pEmployeerecord_nkk[i].sex == 'F')
			printf("Sex			: Female\n");
		else
			printf("Sex			: Invalid Data Entered\n");


		printf("Salary			: Rs. %f\n", pEmployeerecord_nkk[i].salary);

		if (pEmployeerecord_nkk[i].marital_status == 'Y')
			printf("Marital Status			: Married\n");
		else if (pEmployeerecord_nkk[i].marital_status == 'N')
			printf("Marital Status			: Unmarried\n");
		else
			printf("Marital Status			: Invalid Data Entered");


		printf("\n\n");
	}

	if (pEmployeerecord_nkk)
	{
		free(pEmployeerecord_nkk);
		pEmployeerecord_nkk = NULL;
		printf("MEMORY ALLOCATED TO %d EMPLOYEES HAS BEEN SUCCESSFULLY FREED !!! \n\n", num_employee_nkk);
	}

	return(0);
}

// ******** SIMPLE RUDIMENTARY IMPLICATION OF get_s() ********
// ******** IMPLEMENTED DUE TO DIFFERENT BEHAVIOUR OF gert_s() / fgets() / fscanf() ON DIFFERENT PLATFORMS ********
// ******** BACKSPACE / CHARACTER DELETION AND ARROW KEY CURSOR MOVEMENT NOT IMPLEMENTED ********

void MyGetString(char str[], int str_size)
{
	// variable declarations
	int i;
	char ch = '\0';

	//code
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

