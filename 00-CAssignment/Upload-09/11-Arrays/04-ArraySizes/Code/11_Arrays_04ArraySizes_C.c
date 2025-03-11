#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int iArray_One_nkk[5];
	int iArray_Two_nkk[5][3];
	int iArray_Three_nkk[100][100][5];

	int num_rows_2D;
	int num_columns_2D;

	int num_rows_3D;
	int num_columns_3D;
	int depth_3D;

	// Code
	printf("\n\n");
	printf("Size Of 1-D integer array iArray_One_nkk = %lu\n", sizeof(iArray_One_nkk));
	printf("Number of elements in 1-D integer array iArray_One = %lu\n", (sizeof(iArray_One_nkk) / sizeof(int)));

	printf("\n\n");
	printf("Size of 2-D integer array iArray_Two = %lu\n", sizeof(iArray_Two_nkk));

	printf("Number rows in 2-D Integer Array iArray_Two_nkk = %lu\n", (sizeof(iArray_Two_nkk) / sizeof(iArray_Two_nkk[0])));
	num_rows_2D = (sizeof(iArray_Two_nkk) / sizeof(iArray_Two_nkk[0]));

	printf("Number of elements (columns) in each row in 2-D integer array iArray_Two_nkk = %lu\n", (sizeof(iArray_Two_nkk[0]) / sizeof(iArray_Two_nkk[0][0])));
	num_columns_2D = (sizeof(iArray_Two_nkk[0]) / sizeof(iArray_Two_nkk[0][0]));

	printf("Number of elements in total in 2-D Array iArray_Two = %d\n", (num_rows_2D * num_columns_2D));

	printf("\n\n");

	printf("\n\n");
	printf("Size of 3-D integer array iArray_Three = %lu\n", sizeof(iArray_Three_nkk));

	printf("Number rows in 3-D integer array iArray_Three_nkk = %lu\n", (sizeof(iArray_Three_nkk) / sizeof(iArray_Three_nkk[0])));
	num_rows_3D = (sizeof(iArray_Three_nkk) / sizeof(iArray_Three_nkk[0]));

	printf("Number of elements (columns) in one row in 3-D integer array iArray_Three_nkk = %lu\n", (sizeof(iArray_Three_nkk[0]) / sizeof(iArray_Three_nkk[0][0])));
	num_columns_3D = (sizeof(iArray_Three_nkk[0]) / sizeof(iArray_Three_nkk[0][0]));

	printf("Number of elements (depth) in one column in one row in 3-D integer array iArray_Three_nkk = %lu\n", (sizeof(iArray_Three_nkk[0][0]) / sizeof(iArray_Three_nkk[0][0][0])));
	depth_3D = (sizeof(iArray_Three_nkk[0][0]) / sizeof(iArray_Three_nkk[0][0][0]));

	printf("Number Of elements in total in 3-D Array iArray_Three = %d\n", (num_rows_3D * num_columns_3D * depth_3D));

	printf("\n\n");

	return(0);
}


