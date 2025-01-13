#include <stdio.h>
int main(void)
{
	// Variable Declarations
	int iArray_nkk[5][3] = { {1,2,3}, {2,4,6}, {3,6,9}, {4,8,12}, {5,10,15} }; // IN-LINE INITIALIZATION
	int int_size_nkk;
	int iArray_size_nkk;
	int iArray_num_elements_nkk, iArray_num_rows_nkk, iArray_num_columns_nkk;
	int i_nkk, j_nkk;

	// Code
	printf("\n\n");

	int_size_nkk = sizeof(int);

	iArray_size_nkk = sizeof(iArray_nkk);
	printf("Size Of Two Dimentional ( 2D ) Integer Array Is = %d\n\n", iArray_size_nkk);

	iArray_num_rows_nkk = iArray_size_nkk / sizeof(iArray_nkk[0]);
	printf("Number of Rows In Two Dimensional ( 2D ) Integer Array Is = %d\n\n", iArray_num_rows_nkk);

	iArray_num_columns_nkk = sizeof(iArray_nkk[0]) / int_size_nkk;
	printf("Number Of Columns In Two Dimensional ( 2D ) Integer Array Is = %d\n\n", iArray_num_columns_nkk);

	iArray_num_elements_nkk = iArray_num_rows_nkk * iArray_num_columns_nkk;
	printf("Number Of Elements In Two Dimensional ( 2D ) Integer Array Is = %d\n\n", iArray_num_elements_nkk);

	printf("\n\n");
	printf("Elements In The 2D Array : \n\n");

	// ******** ARRAY INDICES BEGIN FROM 0, HENCE, 1ST ROW IS ACTUALLY 0TH ROW AND 1ST COLUMN IS ACTUALLY 0TH COLUMN ********
	for (i_nkk = 0; i_nkk < iArray_num_rows_nkk; i_nkk++)
	{
		printf("******** ROW %d ********", (i_nkk + 1));
		for (j_nkk = 0; j_nkk < iArray_num_columns_nkk; j_nkk++)
		{
			printf("iArray_nkk[%d][%d] = %d\n", i_nkk, j_nkk, iArray_nkk[i_nkk][j_nkk]);
		}
		printf("\n\n");
	}

	return(0);
}

