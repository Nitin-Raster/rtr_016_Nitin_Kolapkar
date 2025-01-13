#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// Variable Declarations
	int** ptr_iArray_nkk = NULL; // A pointer-to-pointer to integer ... but can also hold base address of a 2D Array which will have any number of rows and any numner of columns ... 
	int i, j;
	int num_rows_nkk, num_columns_nkk;

	// code
	
	// ******** ACCEPT NUMBER OF ROWS 'num_rows' FROM USER ********
	printf("\n\n");
	printf("Enter Number of Rows: ");
	scanf("%d", &num_rows_nkk);

	// ******** ACCEPT NUMBER OF ROWS 'num_columns' FROM USER ********
	printf("\n\n");
	printf("Enter Number of Columns: ");
	scanf("%d", &num_columns_nkk);

	// ******** ALLOCATING MEMORY TO 1D ARRAY CONSISTING OF BASE ADDRESS OF ROWS ********
	printf("\n\n");
	printf("********* MEMORY ALLOCATION TO 2D INTEGER ARRAY ********\n\n");
	ptr_iArray_nkk = (int**)malloc(num_rows_nkk * sizeof(int*));
	if (ptr_iArray_nkk == NULL)
	{
		printf("FAILED TO ALLOCATE MEMORY TO %d ROWS OF 2D INTEGER ARRAY !!! EXITTING NOW... \n\n", num_rows_nkk);
		exit(0);
	}
	else
		printf("MEMORY ALLOCATION TO %d ROWS OF 2D INTEGER ARAY SUCCEDED !!!\n\n", num_rows_nkk);

	// ******** ALLOCATING MEMORY TO EACH ROW WHICH IS A 1D ARRAY CONTAINING CONSISTING OF COLUMNS WHICH CONTAIN THE ACTUAL INTEGERS ********
	for (i = 0; i < num_rows_nkk; i++)
	{
		ptr_iArray_nkk[i] = (int*)malloc(num_columns_nkk * sizeof(int)); // ALLOCATING MEMORY (Number Of Columns * size of 'int' ) TO ROW 'i' 
		if (ptr_iArray_nkk[i] == NULL) // ROW 'i' MEMORY ALLOCATED ?
		{
			printf("FAILED TO ALLOCATE MEMORY TO COLUMNS OF ROW %d OF 2D INTEGER ARRAY !!! EXITTING NOW... \n\n", i);
			exit(0);
		}
		else
			printf("MEMORY ALLOCATION TO COLUMNS OF ROW %d OF 2D INTEGER ARRAY SUCCEDED !!!\n\n", i);
	}

	// ******** FILLING UP VALUUES  ********
	for (i = 0; i < num_rows_nkk; i++)
	{
		for (j = 0; j < num_columns_nkk; j++)
		{
			ptr_iArray_nkk[i][j] = (i * 1) + (j + 1); // can also use : *(*ptr_iArray_nkk + i) + j) = (i * 1) + (j * 1)
		}
	}

	// ******** DISPLAYING VALUES ********
	for (i = 0; i < num_rows_nkk; i++)
	{
		printf("ase Address Of Row %d : ptr_iArray[%d] = %p \t At Address : %p \n", i, i, ptr_iArray_nkk[i], &ptr_iArray_nkk[i]);
	}

	printf("\n\n");

	for (i = 0; i < num_rows_nkk; i++)
	{
		for (j = 0; j < num_columns_nkk; j++)
		{
			printf("ptr_iArray_nkk[%d][%d] = %d \t At Address : %p\n", i, j, ptr_iArray_nkk[i][j], &ptr_iArray_nkk[i][j]); // can also use *(*(ptr_iArray_nkk + i) + j) for value and *(ptr_iArray_nkk + i) + j for address ...
		}
		printf("\n");
	}

	// ******** FREEING MEMORY ALLOCATED TO EACH ROW ********
	for (i = (num_rows_nkk - 1); i >= 0; i--)
	{
		if (ptr_iArray_nkk[i])
		{
			free(ptr_iArray_nkk[i]);
			ptr_iArray_nkk[i] = NULL;
			printf("MEMORY ALLOCATED TO ROW %d HAS BEEN SUCCESSFULLY FREED !!!\n\n", i);
		}
	}

	// ******** FREEING MEMORY ALLOCATED TO 1D ARRAY CONSISTING OF BASE ADDRESSES OF ROWS ********
	if (ptr_iArray_nkk)
	{
		free(ptr_iArray_nkk);
		ptr_iArray_nkk = NULL;
		printf("MEMORY ALLOCATED TO ptr_iArray_nkk HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}

	return(0);
}




