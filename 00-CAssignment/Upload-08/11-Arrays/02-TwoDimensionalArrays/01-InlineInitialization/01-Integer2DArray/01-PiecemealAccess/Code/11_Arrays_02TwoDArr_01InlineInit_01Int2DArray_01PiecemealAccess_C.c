#include <stdio.h>
int main(void)
{
	// Variable Declarations
	int iArray_nkk[5][3] = { {1,2,3}, {2,4,6}, {3,6,9}, {4,8,12}, {5,10,15} }; // IN-LINE INITIALIZATION
	int int_size_nkk;
	int iArray_size_nkk;
	int iArray_num_elements_nkk, iArray_num_rows_nkk, iArray_num_columns_nkk;

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

	// ******** ROW 1 ********
	printf("******** ROW 1 ********\n");
	printf("iArray[0][0] = %d\n", iArray_nkk[0][0]); // *** COLUMN 1 *** (0th Element) => 1
	printf("iArray[0][1] = %d\n", iArray_nkk[0][1]); // *** COLUMN 2 *** (1st Element) => 2
	printf("iArray[0][2] = %d\n", iArray_nkk[0][2]); // *** COLUMN 3 *** (2nd Element) => 3

	printf("\n\n");

	// ******** ROW 2 ********
	printf("******** ROW 2 ********\n");
	printf("iArray[1][0] = %d\n", iArray_nkk[1][0]); // *** COLUMN 1 *** (0th Element) => 2
	printf("iArray[1][1] = %d\n", iArray_nkk[1][1]); // *** COLUMN 2 *** (1st Element) => 4
	printf("iArray[1][2] = %d\n", iArray_nkk[1][2]); // *** COLUMN 3 *** (2nd Element) => 6

	printf("\n\n");

	// ******** ROW 3 ********
	printf("******** ROW 3 ********\n");
	printf("iArray[2][0] = %d\n", iArray_nkk[2][0]); // *** COLUMN 1 *** (0th Element) => 3
	printf("iArray[2][1] = %d\n", iArray_nkk[2][1]); // *** COLUMN 2 *** (1st Element) => 6
	printf("iArray[2][2] = %d\n", iArray_nkk[2][2]); // *** COLUMN 3 *** (2nd Element) => 9

	printf("\n\n");

	// ******** ROW 4 ********
	printf("******** ROW 4 ********\n");
	printf("iArray[3][0] = %d\n", iArray_nkk[3][0]); // *** COLUMN 1 *** (0th Element) => 4
	printf("iArray[3][1] = %d\n", iArray_nkk[3][1]); // *** COLUMN 2 *** (1st Element) => 8
	printf("iArray[3][2] = %d\n", iArray_nkk[3][2]); // *** COLUMN 3 *** (2nd Element) => 12

	printf("\n\n");

	// ******** ROW 5 ********
	printf("******** ROW 5 ********\n");
	printf("iArray[4][0] = %d\n", iArray_nkk[4][0]); // *** COLUMN 1 *** (0th Element) => 5
	printf("iArray[4][1] = %d\n", iArray_nkk[4][1]); // *** COLUMN 2 *** (1st Element) => 10
	printf("iArray[4][2] = %d\n", iArray_nkk[4][2]); // *** COLUMN 3 *** (2nd Element) => 15

	printf("\n\n");

	return(0);
}

