#include <stdio.h>
int main(void)
{
	// Variable Declarations
	int iArray_nkk[3][5]; //3 ROWS (0, 1, 2) AND 5 COLUMNS (0, 1, 2, 3, 4);
	int int_size_nkk;
	int iArray_size_nkk;
	int iArray_num_elements_nkk, iArray_num_rows_nkk, iArray_num_columns_nkk;
	int i_nkk, j_nkk;

	// Code
	printf("\n\n");

	int_size_nkk = sizeof(int);

	iArray_size_nkk = sizeof(iArray_nkk);
	printf("Size Of Two Dimensional ( 2D ) Integer Array Is = %d\n\n", iArray_size_nkk);

	iArray_num_rows_nkk = iArray_size_nkk / sizeof(iArray_nkk[0]);
	printf("Number of Rows in Two Dimensional ( 2D ) Integer Array Is = %d\n\n", iArray_num_rows_nkk);

	iArray_num_columns_nkk = sizeof(iArray_nkk[0]) / int_size_nkk;
	printf("Number of Columns in Two Dimensional ( 2D ) Integer Array Is = %d\n\n", iArray_num_columns_nkk);

	iArray_num_elements_nkk = iArray_num_rows_nkk * iArray_num_columns_nkk;
	printf("Number of Elements in Two Dimensional ( 2D ) Integer Array Is = %d\n\n", iArray_num_elements_nkk);

	printf("\n\n");
	printf("Elements In The 2D Array : \n\n");

	// ******** PIECE-MEAL ASSIGNMENT ********
	// ******** ROW 1 ********
	iArray_nkk[0][0] = 21;
	iArray_nkk[0][1] = 42;
	iArray_nkk[0][2] = 63;
	iArray_nkk[0][3] = 84;
	iArray_nkk[0][4] = 105;

	// ******** ROW 2 ********
	iArray_nkk[1][0] = 22;
	iArray_nkk[1][1] = 44;
	iArray_nkk[1][2] = 66;
	iArray_nkk[1][3] = 88;
	iArray_nkk[1][4] = 110;

	// ******** ROW 3 ********
	iArray_nkk[2][0] = 23;
	iArray_nkk[2][1] = 46;
	iArray_nkk[2][2] = 69;
	iArray_nkk[2][3] = 92;
	iArray_nkk[2][4] = 115;

	// ******** DISPLAY ********
	for (i_nkk = 0; i_nkk < iArray_num_rows_nkk; i_nkk++)
	{
		printf("******** ROW %d ********\n", (i_nkk + 1));
		for (j_nkk = 0; j_nkk < iArray_num_columns_nkk; j_nkk++);
		{
			printf("iArray_nkk[%d][%d] = %d\n", i_nkk, j_nkk, iArray_nkk[i_nkk][j_nkk]);
		}
		printf("\n\n");
	}

	return(0);
}

