#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int iArray_nkk[] = { 9, 30, 6, 12, 98, 95, 20, 23, 2, 45 };
	int int_size;
	int iArray_size;
	int iArray_num_elements;

	float fArray_nkk[] = {1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f };
	int float_size;
	int fArray_size;
	int fArray_num_elements;

	char cArray[] = { 'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P' };
	int char_size;
	int cArray_size;
	int cArray_num_elements;

	// Code

	// ****** iArray[] ******
	printf("\n\n");
	printf("In-Line Initilization And Piece-Meal Display Of Elements of Array 'iArray[]' : \n\n");
	printf("iArray_nkk[0] (1st Elements) = %d\n", iArray_nkk[0]);
	printf("iArray_nkk[1] (2nd Elements) = %d\n", iArray_nkk[1]);
	printf("iArray_nkk[2] (3rd Elements) = %d\n", iArray_nkk[2]);
	printf("iArray_nkk[3] (4th Elements) = %d\n", iArray_nkk[3]);
	printf("iArray_nkk[4] (5th Elements) = %d\n", iArray_nkk[4]);
	printf("iArray_nkk[5] (6th Elements) = %d\n", iArray_nkk[5]);
	printf("iArray_nkk[6] (7th Elements) = %d\n", iArray_nkk[6]);
	printf("iArray_nkk[7] (8th Elements) = %d\n", iArray_nkk[7]);
	printf("iArray_nkk[8] (9th Elements) = %d\n", iArray_nkk[8]);
	printf("iArray_nkk[9] (10th Elements) = %d\n", iArray_nkk[9]);

	int_size = sizeof(int);
	iArray_size = sizeof(iArray_nkk);
	iArray_num_elements = iArray_size / int_size;
	printf("Size Of Data type 'int'		= %d bytes\n", int_size);
	printf("Number Of Elements In 'int' Array 'iArray'		= %d Elements \n", iArray_num_elements);
	printf("Size Of Array 'iArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n", iArray_num_elements, int_size, iArray_size);

	// ****** fArray[] *******
	printf("\n\n");
	printf("In-Line Initialization And Piece-meal Display Of Elements of Array 'fArray[]' : \n\n");
	printf("fArray_nkk[0] (1st Elements) = %f\n", fArray_nkk[0]);
	printf("fArray_nkk[1] (2nd Elements) = %f\n", fArray_nkk[1]);
	printf("fArray_nkk[2] (3rd Elements) = %f\n", fArray_nkk[2]);
	printf("fArray_nkk[3] (4th Elements) = %f\n", fArray_nkk[3]);
	printf("fArray_nkk[4] (5th Elements) = %f\n", fArray_nkk[4]);
	printf("fArray_nkk[5] (6th Elements) = %f\n", fArray_nkk[5]);
	printf("fArray_nkk[6] (7th Elements) = %f\n", fArray_nkk[6]);
	printf("fArray_nkk[7] (8th Elements) = %f\n", fArray_nkk[7]);

	float_size = sizeof(float);
	fArray_size = sizeof(fArray_nkk);
	fArray_num_elements = fArray_size / float_size;
	printf("Size Of Data type 'float'			= %d bytes\n", float_size);
	printf("Number Of Elements In 'float' Array 'fArray[]'		= %d Elements\n", fArray_num_elements);
	printf("Size Of Array 'fArray[]' (%d Elements * %d Bytes)	= %d Bytes\n\n", fArray_num_elements, float_size, fArray_size);

	// ****** cArray[] ******
	printf("\n\n");
	printf("In-Line Initialization And Piece-meal Display Of Elements of Array 'cArray[]' : \n\n");
	printf("cArray[0] (1st Elements)	= %c\n", cArray[0]);
	printf("cArray[1] (2nd Elements)	= %c\n", cArray[1]);
	printf("cArray[2] (3rd Elements)	= %c\n", cArray[2]);
	printf("cArray[3] (4th Elements)	= %c\n", cArray[3]);
	printf("cArray[4] (5th Elements)	= %c\n", cArray[4]);
	printf("cArray[5] (6th Elements)	= %c\n", cArray[5]);
	printf("cArray[6] (7th Elements)	= %c\n", cArray[6]);
	printf("cArray[7] (8th Elements)	= %c\n", cArray[7]);
	printf("cArray[8] (9th Elements)	= %c\n", cArray[8]);
	printf("cArray[9] (10th Elements)	= %c\n", cArray[9]);
	printf("cArray[10] (11th Elements)	= %c\n", cArray[10]);
	printf("cArray[11] (12th Elements)	= %c\n", cArray[11]);
	printf("cArray[12] (13th Elements)	= %c\n", cArray[12]);

	char_size = sizeof(char);
	cArray_size = sizeof(cArray);
	cArray_num_elements = cArray_size / char_size;
	printf("Size Of Data type 'char'			= %d bytes\n", char_size);
	printf("Number Of Elements In 'char' Array 'cArray[]'			= %d Elements\n", cArray_num_elements);
	printf("Size Of Array 'cArray[]' (%d Elements * %d Bytes)	= %d Bytes \n\n", cArray_num_elements, char_size, cArray_size);

	return(0);

}

