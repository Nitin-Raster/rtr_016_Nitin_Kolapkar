#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	// Variable Declarations
	int iArray_2D_nkk[NUM_ROWS][NUM_COLUMNS]; // TOTAL NUMBER OF ELEMENTS = NUM_ROWS * NUM_COLUMNS
	int iArray_1D_nkk[NUM_ROWS * NUM_COLUMNS];

	int i, j;
	int num;

	// Code
	printf("Enter Elements Of Your Choice To Fill Up The Integer 2D Array : \n\n");
	for (i = 0; i < NUM_ROWS; i++)
	{
		printf("For ROW NUMBER %d : \n", (i + 1));
		for (j = 0; j < NUM_COLUMNS; j++)
		{
			printf("Enter Element Number %d : \n", (j + 1));
			scanf("%d", &num);
			iArray_2D_nkk[i][j] = num;
		}
		printf("\n\n");
	}

	// ******** DISPLAY OF 2D  ARRAY ********
	printf("\n\n");
	printf("Two-Dimensional ( 2D ) Array Of Integers : \n\n");
	for (i = 0; i < NUM_ROWS; i++)
	{
		printf("******** ROW %d ********", (i + 1));
		for (j = 0; j < NUM_COLUMNS; j++)
		{
			printf("iArray_2D[%d][%d] = %d\n", i, j, iArray_2D_nkk[i][j]);
		}
		printf("\n\n");
	}

	// ******** CONVERTING 2D INTEGER ARRAY TO 1D INTEGER ARRAY ********
	for (i = 0; i < NUM_ROWS; i++)
	{
		for (j = 0; j < NUM_COLUMNS; j++)
		{
			iArray_1D_nkk[(i * NUM_COLUMNS) + j] = iArray_2D_nkk[i][j];
		}
	}

	// ******** Printing 1D Array ********
	printf("\n\n");
	printf("One-Dimensional ( 1D ) Array Of Integers : \n\n");
	for (i = 0; i < (NUM_ROWS * NUM_COLUMNS); i++)
	{
		printf("iArray_1D_nkk[%d] = %d\n", i, iArray_1D_nkk[i]);
	}

	printf("\n\n");

	return(0);
}

