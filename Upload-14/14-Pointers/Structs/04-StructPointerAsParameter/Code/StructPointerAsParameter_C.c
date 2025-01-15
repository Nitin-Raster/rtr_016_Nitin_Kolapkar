#include <stdio.h>
#include <stdlib.h>

// DEFINIG STRUCT
struct MyData
{
	int i;
	float f;
	double d;
};

int main(void)
{
	// Function prototypes
	void ChangeValues(struct MyData*);

	// Variable Declarations
	struct MyData* pData_nkk = NULL;

	// Code
	printf("\n\n");

	pData_nkk = (struct MyData*)malloc(sizeof(struct MyData));
	if (pData_nkk == NULL)
	{
		printf("FAILED TO ALLOCATE MEMORY TO 'struct MyData' !!! EXITTING NOW ...\n\n");
		exit(0);
	}
	else
		printf("SUCCESSFULLY ALLOCATED MEMORY TO 'struct MyData' !!!");


	// Assigining Data Values To The Data Members Of 'struct MyData'
	pData_nkk->i = 34;
	pData_nkk->f = 123.123465f;
	pData_nkk->d = 321.321321;

	// Displaying Values Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("i = %d", pData_nkk->i);
	printf("i = %f", pData_nkk->f);
	printf("i = %lf", pData_nkk->d);

	ChangeValues(pData_nkk);

	// Displaying Values Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("DATA MEMEBRS OF 'struct MyData' ARE : \n\n");
	printf("i = %d", pData_nkk->i);
	printf("i = %f", pData_nkk->f);
	printf("i = %lf", pData_nkk->d);

	if (pData_nkk)
	{
		free(pData_nkk);
		pData_nkk = NULL;
		printf("MEMORY ALLOCATED TO 'struct MyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}

	return(0);
}

void ChangeValues(struct MyData* pParam_Data)
{
	// Code

	pParam_Data->i = 8;
	pParam_Data->f = 7.8f;
	pParam_Data->d = 2.456789;

	// CAN ALSO DO THIS AS ....
/*
	(*pParam_Data).i = 8;
	(*pParam.Data).f = 7.8f;
	(*pParam.Data).d = 2.456789
*/
}


