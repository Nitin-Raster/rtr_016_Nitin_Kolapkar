#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE sizeof(int)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#define CHAR_SIZE sizeof(char)

int main(void)
{
	// Variable Declarations
	int* ptr_iArray = NULL;
	unsigned int intArrayLength_nkk = 0;

	float* ptr_fArray = NULL;
	unsigned int floatArrayLength_nkk = 0;

	double* ptr_dArray = NULL;
	unsigned int doubleArrayLength_nkk = 0;

	char *ptr_cArray = NULL;
	unsigned int charArrayLength_nkk = 0;

	int i;

	// code

	// ******** INTEGER ARRAY ********
	printf("\n\n");
	printf("Enter The Number Of Elements You Want In Your Integer Array : ");
	scanf("%u", &intArrayLength_nkk);

	ptr_iArray = (int*)malloc(INT_SIZE * intArrayLength_nkk);
	if (ptr_iArray == NULL)
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR INTEGER ARRAY HAS FAILED !!! EXITTING NOW...\n\n");
		exit(0);
	}	
	else
	{
			printf("\n\n");
			printf("MEMORY ALLOCATION FOR INTEGER ARRAY HAS SUCCEDED !!!\n\n");
	}

	printf("\n\n");
	printf("Enter The %d Elements For The Integer Elements To Fill Up The Integer Array : \n\n", intArrayLength_nkk);
	for (i = 0; i < intArrayLength_nkk; i++)
		scanf("%d", (ptr_iArray + i));

	// ******** FLOAT ARRAY ********
	printf("\n\n");
	printf("Enter The Number Of Elements You Want In Your 'float' Array : ");
	scanf("%u", &floatArrayLength_nkk);

	ptr_fArray = (float*)malloc(FLOAT_SIZE * floatArrayLength_nkk);
	if (ptr_fArray == NULL)
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR FLOATING-POINT ARRAY HAS FAILED !!! EXITTING NOW...\n\n");
		exit(0);
	}
	else
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR FLOATING-POINT ARRAY HAS SUCCEDED !!!\n\n");
	}

	printf("\n\n");
	printf("Enter The %d Floating-Point Elements To Fill Up The Float Array : \n\n", floatArrayLength_nkk);
	for (i = 0; i < floatArrayLength_nkk; i++)
		scanf("%f", (ptr_fArray + i));

	// ******** DOUBLE ARRAY ********
	printf("\n\n");
	printf("Enter The Number Of Elements You Want In Your 'double' Array : ");
	scanf("%u", &doubleArrayLength_nkk);

	ptr_dArray = (double*)malloc(DOUBLE_SIZE * doubleArrayLength_nkk);
	if (ptr_dArray == NULL)
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR 'DOUBLE' ARRAY HAS FAILED !!! EXITTING NOW...\n\n");
		exit(0);
	}
	else
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR DOUBLE ARRAY HAS SUCCEDED !!!\n\n");
	}

	printf("\n\n");
	printf("Enter The %d Double Elements To Fill Up The Double Array : \n\n", doubleArrayLength_nkk);
	for (i = 0; i < doubleArrayLength_nkk; i++)
		scanf("%lf", (ptr_dArray + i));

	// ******** CHAR ARRAY ********
	printf("\n\n");
	printf("Enter The Number Of Elements You Want In Your 'character' Array : ");
	scanf("%u", &charArrayLength_nkk);

	ptr_cArray = (char*)malloc(CHAR_SIZE * charArrayLength_nkk);
	if (ptr_cArray == NULL)
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR 'CHARACTER' ARRAY HAS FAILED !!! EXITTING NOW...\n\n");
		exit(0);
	}
	else
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR CHARACTER ARRAY HAS SUCCEDED !!!\n\n");
	}

	printf("\n\n");
	printf("Enter The %d Character Elements To Fill Up The Character Array : \n\n", charArrayLength_nkk);
	for (i = 0; i < charArrayLength_nkk; i++)
	{
		*(ptr_cArray + i) = getch();
		printf("%c\n", *(ptr_cArray + i));
	}


	// ******** DISPLAY OF ARRAYS ********
	
	// ******** INTEGER ARRAY ********
	printf("\n\n");
	printf("The Integer Array Entered By You, Consisting Of %d Elements Is As Follows : \n\n", intArrayLength_nkk);
	for (i = 0; i < intArrayLength_nkk; i++)
		printf("%d \t \t At Address : %p\n", *(ptr_iArray + i), (ptr_iArray + i));

	// ******** FLOAT ARRAY ********
	printf("\n\n");
	printf("The FLOAT Array Entered By You, Consisting Of %d Elements Is As Follows : \n\n", floatArrayLength_nkk);
	for (i = 0; i < floatArrayLength_nkk; i++)
		printf("%f \t \t At Address : %p\n", *(ptr_fArray + i), (ptr_fArray + i));

	// ******** DOUBLE ARRAY ********
	printf("\n\n");
	printf("The Double Array Entered By You, Consisting Of %d Elements Is As Follows : \n\n", doubleArrayLength_nkk);
	for (i = 0; i < doubleArrayLength_nkk; i++)
		printf("%lf \t \t At Address : %p\n", *(ptr_dArray + i), (ptr_dArray + i));

	// ******** CHARACTER ARRAY ********
	printf("\n\n");
	printf("The Character Array Entered By You, Consisting Of %d Elements Is As Follows : \n\n", charArrayLength_nkk);
	for (i = 0; i < charArrayLength_nkk; i++)
		printf("%c \t \t At Address : %p\n", *(ptr_cArray + i), (ptr_cArray + i));


	// ******** FREEING MEMORY OCCUPIED BY ARRAYS (IN REVERSE ORDER OF ALLOCATION) ********
	if (ptr_cArray)
	{
		free(ptr_cArray);
		ptr_cArray = NULL;

		printf("\n\n");
		printf("MEMORY ALLOCATED FOR CHARACTER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}
	
	if (ptr_dArray)
	{
		free(ptr_dArray);
		ptr_dArray = NULL;

		printf("\n\n");
		printf("MEMORY ALLOCATED FOR DOUBLE ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}

	if (ptr_fArray)
	{
		free(ptr_fArray);
		ptr_fArray = NULL;

		printf("\n\n");
		printf("MEMORY ALLOCATED FOR FLOATING-POINT ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}

	if (ptr_iArray)
	{
		free(ptr_iArray);
		ptr_iArray = NULL;

		printf("\n\n");
		printf("MEMORY ALLOCATED FOR INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}

	return(0);
}
