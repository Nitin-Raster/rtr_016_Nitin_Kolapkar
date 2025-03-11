#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int iArray_nkk[] = { 9, 30, 6, 12, 98, 95, 20, 23, 2, 45 };
	int int_size_nkk;
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

	int i_nkk = 0;
	// Code

	// ****** iArray[] ******
	printf("\n\n");
	printf("In-Line Initilization And Loop (for) Display Of Elements of Array 'iArray[]' : \n\n");

	int_size_nkk = sizeof(int);
	iArray_size = sizeof(iArray_nkk);
	iArray_num_elements = iArray_size / int_size_nkk;

	for (i_nkk = 0; i_nkk < iArray_num_elements; i_nkk++)
	{
		printf("iArray_nkk[%d] (Elements %d) = %d\n", i_nkk, (i_nkk + 1), iArray_nkk[i_nkk]);
	}
	printf("Size Of Data type 'int'		= %d bytes\n", int_size_nkk);
	printf("Number Of Elements In 'int' Array 'iArray'		= %d Elements \n", iArray_num_elements);
	printf("Size Of Array 'iArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n", iArray_num_elements, int_size_nkk, iArray_size);

	// ****** fArray[] *******
	printf("\n\n");
	printf("In-Line Initialization And Loop (while) Display Of Elements of Array 'fArray[]' : \n\n");
	
	float_size = sizeof(float);
	fArray_size = sizeof(fArray_nkk);
	fArray_num_elements = fArray_size / float_size;
	
	i_nkk = 0;
	while (i_nkk < fArray_num_elements)
	{
		printf("fArray_nkk[%d] (Elements %d) = %f\n", i_nkk, (i_nkk + 1), fArray_nkk[i_nkk]);
		i_nkk++;
	}

	printf("Size Of Data type 'float'			= %d bytes\n", float_size);
	printf("Number Of Elements In 'float' Array 'fArray[]'		= %d Elements\n", fArray_num_elements);
	printf("Size Of Array 'fArray[]' (%d Elements * %d Bytes)	= %d Bytes\n\n", fArray_num_elements, float_size, fArray_size);

	// ****** cArray[] ******
	printf("\n\n");
	printf("In-Line Initialization And Loop (for) Display Of Elements of Array 'cArray[]' : \n\n");
	
	char_size = sizeof(char);
	cArray_size = sizeof(cArray);
	cArray_num_elements = cArray_size / char_size;

	for (i_nkk = 0; i_nkk < iArray_num_elements; i_nkk++)
	{
		printf("cArray[%d] (Elements %d) = %d\n", i_nkk, (i_nkk + 1), cArray[i_nkk]);
	}
	printf("Size Of Data type 'char'			= %d bytes\n", char_size);
	printf("Number Of Elements In 'char' Array 'cArray[]'			= %d Elements\n", cArray_num_elements);
	printf("Size Of Array 'cArray[]' (%d Elements * %d Bytes)	= %d Bytes \n\n", cArray_num_elements, char_size, cArray_size);

	return(0);

}

