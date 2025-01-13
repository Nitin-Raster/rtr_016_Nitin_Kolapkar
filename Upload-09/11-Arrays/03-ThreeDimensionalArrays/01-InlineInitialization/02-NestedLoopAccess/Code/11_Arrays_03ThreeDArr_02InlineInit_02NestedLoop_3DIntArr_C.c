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
	int i, j, k;

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

	for (i = 0; i < iArray_width_nkk; i++)
	{
		printf("******** ROW %d ********", (i + 1));
		for (j = 0; j < iArray_height_nkk; j++)
		{
			printf("******** COLUMN %d ********\n", (j + 1));
			for (k = 0; k < iArray_depth_nkk; k++)
			{
				printf("iArray_nkk[%d][%d][%d] = %d\n", i, j, k, iArray_nkk[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
	}

	return(0);
}

