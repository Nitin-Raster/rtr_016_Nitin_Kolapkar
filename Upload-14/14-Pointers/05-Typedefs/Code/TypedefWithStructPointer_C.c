#include <stdio.h>
#include <stdlib.h>

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
	int i_size_nkk;
	int f_size_nkk;
	int d_size_nkk;
	int struct_MyData_size_nkk;
	int pointer_to_struct_MyData_size_nkk;

	typedef struct MyData* MyDataptr_nkk;
	
	MyDataptr_nkk pData_nkk;

	// Code
	printf("\n\n");

	pData_nkk = (MyDataptr_nkk)malloc(sizeof(struct MyData));
	// pData_nkk = (MyDataptr_nkk)malloc(sizeof(struct MyData));
	if (pData_nkk == NULL)
	{
		printf("FAILED TO ALLOCATE MEMORY TO 'struct MyData' !!! EXITTING NOW ...\n\n");
		exit(0);
	}
	else
		printf("SUCCESSFULLY ALLOCATED MEMORY TO 'struct MyData' !!! \n\n");


	printf("\n\n");

	// Assigning Data Values To The Data Members Of 'struct MyData'
	pData_nkk->i = 30;
	pData_nkk->d = 11.45f;
	pData_nkk->d = 1.2995;

	//Displaying Values Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("i = %d\n", pData_nkk->i);
	printf("f = %f\n", pData_nkk->f);
	printf("d = %lf\n", pData_nkk->d);

	// Calculating Sizes (In Bytes) Of The Data Members Of 'struct MyData'
	i_size_nkk = sizeof(pData_nkk->i);
	f_size_nkk = sizeof(pData_nkk->f);
	d_size_nkk = sizeof(pData_nkk->d);

	// Displaying Sizes (In Bytes) Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("SIZES (in bytes) OF DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("Size of 'i' = %d bytes\n", i_size_nkk);
	printf("Size of 'f' = %d bytes\n", f_size_nkk);
	printf("Size of 'd' = %d bytes\n", d_size_nkk);

	// Calculating Size (In Bytes) Of The Entire 'struct MyData'
	struct_MyData_size_nkk = sizeof(struct MyData);
	pointer_to_struct_MyData_size_nkk = sizeof(MyDataptr_nkk);

	// Displaying Sizes (In Bytes) Of the entire 'struct MyData'
	printf("\n\n");
	printf("Size of 'struct MyData' : %d bytes\n\n", struct_MyData_size_nkk);
	printf("Size of pointer to 'struct MyData' : %d bytes\n\n", pointer_to_struct_MyData_size_nkk);

	if (pData_nkk)
	{
		free(pData_nkk);
		pData_nkk = NULL;
		printf("MEMORY ALLOCATED TO 'struct MyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}

	return(0);
}

