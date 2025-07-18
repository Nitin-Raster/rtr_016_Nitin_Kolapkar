#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3
#define DEPTH 2

int main(void)
{
	// Variable Declarations

	// IN-LINE INITIALIZATION
	int iArray_nkk[5][3][2] = { { {9, 18}, {27, 36}, {45,54} },
								{ {8, 16}, {24, 32}, {40,48} },
								{ {7, 14}, {21, 28}, {35,42} },
								{ {6, 12}, {18, 24}, {30,36} },
								{ {5, 10}, {15, 20}, {25,30} } };
	int i, j, k;

	int iArray_1D_nkk[NUM_ROWS * NUM_COLUMNS * DEPTH]; // 5 * 3 * 2 ELEMENTS => 30 ELEMENTS IN 1D ARRAY

	// Code

	// ******** DISPLAY 3D ARRAY ********
	printf("\n\n");
	printf("Elements In The 3D Array : \n\n");
	for (i = 0; i < NUM_ROWS; i++)
	{
		printf("******** ROW %d ********\n", (i + 1));
		for (j = 0; j < NUM_COLUMNS; j++)
		{
			printf("******** COLUMN %d ********\n", (j + 1));
			for (k = 0; k < DEPTH; k++)
			{
				printf("iArray_nkk[%d][%d][%d] = %d\n", i, j, k, iArray_nkk[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	// ******** CONVERTING 3D TO 1D ********
	for (i = 0; i < NUM_ROWS; i++)
	{
		for (j = 0; j < NUM_COLUMNS; j++)
		{
			for (k = 0; k < DEPTH; k++)
			{
				iArray_1D_nkk[(i * NUM_COLUMNS * DEPTH) + (j * DEPTH) + k] = iArray_nkk[i][j][k];
			}
		}
	}

	// ******** DISPLAY 1D ARRAY ********
	printf("\n\n\n\n");
	printf("Elements In The 1D Array : \n\n");
	for (i = 0; i < (NUM_ROWS * NUM_COLUMNS * DEPTH); i++)
	{
		printf("iArray_1D_nkk[%d] = %d\n", i, iArray_1D_nkk[i]);
	}

	return(0);
}

