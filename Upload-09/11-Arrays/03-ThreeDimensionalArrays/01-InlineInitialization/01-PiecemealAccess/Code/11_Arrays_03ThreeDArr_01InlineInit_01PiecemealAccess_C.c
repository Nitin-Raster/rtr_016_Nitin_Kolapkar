#include <stdio.h>
int main(void)
{
	// Variable Declarations

	// IN-LINE INITIALIZATION
	int iArray_nkk[5][3][2] = { { {9, 18}, {27, 36}, {45,54} },
								{ {8, 16}, {24, 32}, {40,48} },
								{ {7, 14}, {21, 28}, {35,42} },
								{ {6, 12}, {18, 24}, {30,36} },
								{ {5, 10}, {15, 20}, {25,30} } };
	int int_size_nkk;
	int iArray_size_nkk;
	int iArray_num_elements_nkk, iArray_width_nkk, iArray_height_nkk, iArray_depth_nkk;

	// Code
	printf("\n\n");

	int_size_nkk = sizeof(int);

	iArray_size_nkk = sizeof(iArray_nkk);
	printf("Size Of Three Dimensional ( 3D ) Integer Array Is = %d\n\n", iArray_size_nkk);

	iArray_width_nkk = iArray_size_nkk / sizeof(iArray_nkk[0]);
	printf("Number Of Rows (Width) In Three Dimensional ( 3D ) Integer Array Is = %d\n\n", iArray_width_nkk);

	iArray_height_nkk = sizeof(iArray_nkk[0]) / sizeof(iArray_nkk[0][0]);
	printf("Number of Columns (Height) In Three Dimensional ( 3D ) Integer Array Is = %d\n\n", iArray_height_nkk);

	iArray_depth_nkk = sizeof(iArray_nkk[0][0]) / int_size_nkk;
	printf("Depth In Three Dimensional ( 3D ) Integer Array Is = %d\n\n", iArray_depth_nkk);

	iArray_num_elements_nkk = iArray_width_nkk * iArray_height_nkk * iArray_depth_nkk;
	printf("Number of Elements In Three Dimensional ( 3D ) Integer Array Is = %d\n\n", iArray_num_elements_nkk);

	printf("\n\n");
	printf("Elements In Integer 3D Array : \n\n");

	// ******** PIECE-MEAL DISPLAY ********
	// ******** ROW 1 ********
	printf("******** ROW 1 ********\n");
	printf("******** COLUMN 1 ********\n");
	printf("iArray_nkk[0][0][0] = %d\n", iArray_nkk[0][0][0]);
	printf("iArray_nkk[0][0][1] = %d\n", iArray_nkk[0][0][1]);
	printf("\n");

	printf("******** COLUMN 2 ********\n");
	printf("iArray_nkk[0][1][0] = %d\n", iArray_nkk[0][1][0]);
	printf("iArray_nkk[0][1][1] = %d\n", iArray_nkk[0][1][1]);
	printf("\n");

	printf("******** COLUMN 3 ********\n");
	printf("iArray_nkk[0][2][0] = %d\n", iArray_nkk[0][2][0]);
	printf("iArray_nkk[0][2][1] = %d\n", iArray_nkk[0][2][1]);
	printf("\n");

	// ******** ROW 2 ********
	printf("******** ROW 2 ********\n");
	printf("******** COLUMN 1 ********\n");
	printf("iArray_nkk[1][0][0] = %d\n", iArray_nkk[1][0][0]);
	printf("iArray_nkk[1][0][1] = %d\n", iArray_nkk[1][0][1]);
	printf("\n");

	printf("******** COLUMN 2 ********\n");
	printf("iArray_nkk[1][1][0] = %d\n", iArray_nkk[1][1][0]);
	printf("iArray_nkk[1][1][1] = %d\n", iArray_nkk[1][1][1]);
	printf("\n");

	printf("******** COLUMN 3 ********\n");
	printf("iArray_nkk[1][2][0] = %d\n", iArray_nkk[1][2][0]);
	printf("iArray_nkk[1][2][1] = %d\n", iArray_nkk[1][2][1]);
	printf("\n");

	// ******** ROW 3 ********
	printf("******** ROW 3 ********\n");
	printf("******** COLUMN 1 ********\n");
	printf("iArray_nkk[2][0][0] = %d\n", iArray_nkk[2][0][0]);
	printf("iArray_nkk[2][0][1] = %d\n", iArray_nkk[2][0][1]);
	printf("\n");

	printf("******** COLUMN 2 ********\n");
	printf("iArray_nkk[2][1][0] = %d\n", iArray_nkk[2][1][0]);
	printf("iArray_nkk[2][1][1] = %d\n", iArray_nkk[2][1][1]);
	printf("\n");

	printf("******** COLUMN 3 ********\n");
	printf("iArray_nkk[2][2][0] = %d\n", iArray_nkk[2][2][0]);
	printf("iArray_nkk[2][2][1] = %d\n", iArray_nkk[2][2][1]);
	printf("\n");

	// ******** ROW 4 ********
	printf("******** ROW 4 ********\n");
	printf("******** COLUMN 1 ********\n");
	printf("iArray_nkk[3][0][0] = %d\n", iArray_nkk[3][0][0]);
	printf("iArray_nkk[3][0][1] = %d\n", iArray_nkk[3][0][1]);
	printf("\n");

	printf("******** COLUMN 2 ********\n");
	printf("iArray_nkk[3][1][0] = %d\n", iArray_nkk[3][1][0]);
	printf("iArray_nkk[3][1][1] = %d\n", iArray_nkk[3][1][1]);
	printf("\n");

	printf("******** COLUMN 3 ********\n");
	printf("iArray_nkk[3][2][0] = %d\n", iArray_nkk[3][2][0]);
	printf("iArray_nkk[3][2][1] = %d\n", iArray_nkk[3][2][1]);
	printf("\n");

	// ******** ROW 5 ********
	printf("******** ROW 5 ********\n");
	printf("******** COLUMN 1 ********\n");
	printf("iArray_nkk[4][0][0] = %d\n", iArray_nkk[4][0][0]);
	printf("iArray_nkk[4][0][1] = %d\n", iArray_nkk[4][0][1]);
	printf("\n");

	printf("******** COLUMN 2 ********\n");
	printf("iArray_nkk[4][1][0] = %d\n", iArray_nkk[4][1][0]);
	printf("iArray_nkk[4][1][1] = %d\n", iArray_nkk[4][1][1]);
	printf("\n");

	printf("******** COLUMN 3 ********\n");
	printf("iArray_nkk[4][2][0] = %d\n", iArray_nkk[4][2][0]);
	printf("iArray_nkk[4][2][1] = %d\n", iArray_nkk[4][2][1]);
	printf("\n");

	return(0);
}

