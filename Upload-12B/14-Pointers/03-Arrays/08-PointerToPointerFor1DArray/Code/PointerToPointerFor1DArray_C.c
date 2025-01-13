#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	void MyAlloc(int** ptr, unsigned int numberOfElements);

	// Variable Declarations
	int* piArray_nkk = NULL; 
	unsigned int num_elements_nkk;
	int i;

	// code
	printf("\n\n");
	printf("Enter Number of Rows: ");
	scanf("%d", &num_elements_nkk);

	printf("\n\n");
	MyAlloc(&piArray_nkk, num_elements_nkk);

	printf("Enter %u Elements To Fill Up Your Integer Array : \n\n", num_elements_nkk);
	for (i = 0; i < num_elements_nkk; i++)
		scanf("%d", &piArray_nkk[i]);

	printf("\n\n");
	printf("The %u Elements Entered By You In The Integer Array : \n\n", num_elements_nkk);
	for (i = 0; i < num_elements_nkk; i++)
		printf("%u\n", piArray_nkk[i]);

	printf("\n\n");
	if (piArray_nkk)
	{
		free(piArray_nkk);
		piArray_nkk = NULL;
		printf("Memory Allocated Has Now Been Successfully Freed !!!\n\n");
	}

	return(0);
}

void MyAlloc(int** ptr, unsigned int numberOfElements)
{
	// code
	*ptr = (int*)malloc(numberOfElements * sizeof(int));
	if (*ptr == NULL)
	{
		printf("Could Not Allocate Memory !!! Exitting Now ... \n\n");
		exit(0);
	}

	printf("MyAlloc() Has Successfully Allocated %lu Bytes For Integer Array !!!\n\n", (numberOfElements * sizeof(int)));
}

