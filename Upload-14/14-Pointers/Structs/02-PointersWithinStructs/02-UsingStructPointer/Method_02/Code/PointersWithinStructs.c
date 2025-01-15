#include <stdio.h>
#include <stdlib.h>

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
	struct MyData *pData_nkk;

	// Code
	printf("\n\n");
	pData_nkk = (struct MyData*)malloc(sizeof(struct MyData));
	if (pData_nkk == NULL)
	{
		printf("FAILED TO ALLOCATE MEMORY 'TO struct MyData' !!! EXITTING NOW...\n\n");
		exit(0);
	}
	else
		printf("SUCCESSFULLY ALLOCATED MEMORY TO 'struct MyData' !!!\n\n");
	
	pData_nkk->i = 7;
	pData_nkk->ptr_i = &(pData_nkk->i);

	pData_nkk->f = 8.222f;
	pData_nkk->ptr_f = &(pData_nkk->f);

	pData_nkk->d = 17.222;
	pData_nkk->ptr_d = &(pData_nkk->d);

	printf("\n\n");
	printf("i = %d\n", *(pData_nkk->ptr_i));
	printf("Address Of 'i' = %p\n", pData_nkk->ptr_i);

	printf("\n\n");
	printf("f = %f\n", *(pData_nkk->ptr_f));
	printf("Address Of 'f' = %p\n", pData_nkk->ptr_f);

	printf("\n\n");
	printf("d = %lf\n", *(pData_nkk->ptr_d));
	printf("Address Of 'd' = %p\n", pData_nkk->ptr_d);

	if (pData_nkk)
	{
		free(pData_nkk);
		pData_nkk = NULL;
		printf("MEMORY ALLOCATED TO 'struct MyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}

	return(0);
}
