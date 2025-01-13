#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	// Variable Declarations
	int* iArray_nkk[NUM_ROWS]; // A 2D ARRAY which will have 5 rows and number of columns can be decided later on ....
	int i, j;

	// Code
	printf("\n\n");
	for (i = 0; i < NUM_ROWS; i++)
	{
		iArray_nkk[i] = (int*)malloc(NUM_COLUMNS * sizeof(int));
		if (iArray_nkk[i] == NULL)
		{
			printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXITTING NOW...\n\n", i);
			exit(0);
		}
		else
			printf("MEMORY ALLOCATION TO THE ROW %d OF 2D INTEGER ARRAY SUCCEDED !!!\n\n", i);
	}

	// ******** ASSIGNING VALUES TO 2D ********
	for (i = 0; i < NUM_ROWS; i++)
	{
		for (j = 0; j < NUM_COLUMNS; j++)
		{
			iArray_nkk[i][j] = (i + 1) * (j + 1);
		}
	}

	// ******** DISPLAYING VALUES ********
	printf("\n\n");
	printf("DISPLAYING 2D ARRAY : \n\n");
	for (i = 0; i < NUM_ROWS; i++)
	{
		for (j = 0; j < NUM_COLUMNS; j++)
		{
			printf("iArray[%d][%d] = %d \n", i, j, iArray_nkk[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\n");

	// ******** FREEING MEMORY ASSIGNED TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER) ********
	for (i = (NUM_ROWS - 1); i >= 0; i--)
	{
			free(iArray_nkk[i]);
			iArray_nkk[i] = NULL;
			printf("MEMORY ALLOCATED TO ROW %d of 2D INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!! \n\n", i);
	}

	return(0);
}
