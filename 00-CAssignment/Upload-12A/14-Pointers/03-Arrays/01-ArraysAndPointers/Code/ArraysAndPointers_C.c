#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int iArray_nkk[] = { 8, 16, 24, 32, 40, 48, 56, 64, 72, 80 };
	float fArray_nkk[] = { 2.3f, 5.5f, 6.6f, 8.8f, 9.9f };
	double dArray_nkk[] = { 1.22222, 2.3333, 3.4444 };
	char cArray_nkk[] = { 'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0' };

	// Code
	printf("\n\n");
	printf("Integer Array Elements And The Addresses They Occupy Are As Follows : \n\n");
	printf("iArray_nkk[0] = %d	\t At Address : %p\n", *(iArray_nkk + 0), (iArray_nkk + 0));
	printf("iArray_nkk[1] = %d	\t At Address : %p\n", *(iArray_nkk + 1), (iArray_nkk + 1));
	printf("iArray_nkk[2] = %d	\t At Address : %p\n", *(iArray_nkk + 2), (iArray_nkk + 2));
	printf("iArray_nkk[3] = %d	\t At Address : %p\n", *(iArray_nkk + 3), (iArray_nkk + 3));
	printf("iArray_nkk[4] = %d	\t At Address : %p\n", *(iArray_nkk + 4), (iArray_nkk + 4));
	printf("iArray_nkk[5] = %d	\t At Address : %p\n", *(iArray_nkk + 5), (iArray_nkk + 5));
	printf("iArray_nkk[6] = %d	\t At Address : %p\n", *(iArray_nkk + 6), (iArray_nkk + 6));
	printf("iArray_nkk[7] = %d	\t At Address : %p\n", *(iArray_nkk + 7), (iArray_nkk + 7));
	printf("iArray_nkk[8] = %d	\t At Address : %p\n", *(iArray_nkk + 8), (iArray_nkk + 8));
	printf("iArray_nkk[9] = %d	\t At Address : %p\n", *(iArray_nkk + 9), (iArray_nkk + 9));

	printf("\n\n");
	printf("Float Array Elements And The Addresses They Occupy Are As Follows : \n\n");
	printf("fArray_nkk[0] = %f	\t At Address : %p\n", *(fArray_nkk + 0), (fArray_nkk + 0));
	printf("fArray_nkk[1] = %f	\t At Address : %p\n", *(fArray_nkk + 1), (fArray_nkk + 1));
	printf("fArray_nkk[2] = %f	\t At Address : %p\n", *(fArray_nkk + 2), (fArray_nkk + 2));
	printf("fArray_nkk[3] = %f	\t At Address : %p\n", *(fArray_nkk + 3), (fArray_nkk + 3));
	printf("fArray_nkk[4] = %f	\t At Address : %p\n", *(fArray_nkk + 4), (fArray_nkk + 4));

	printf("\n\n");
	printf("Double Array Elements And The Addresses They Occupy Are As Follows : \n\n");
	printf("dArray_nkk[0] = %lf	\t At Address : %p\n", *(dArray_nkk + 0), (dArray_nkk + 0));
	printf("dArray_nkk[1] = %lf	\t At Address : %p\n", *(dArray_nkk + 1), (dArray_nkk + 1));
	printf("dArray_nkk[2] = %lf	\t At Address : %p\n", *(dArray_nkk + 2), (dArray_nkk + 2));

	printf("\n\n");
	printf("Character Array Elements And The Addresses They Occupy Are As Follows : \n\n");
	printf("cArray_nkk[0] = %c	\t At Address : %p\n", *(cArray_nkk + 0), (cArray_nkk + 0));
	printf("cArray_nkk[1] = %c	\t At Address : %p\n", *(cArray_nkk + 1), (cArray_nkk + 1));
	printf("cArray_nkk[2] = %c	\t At Address : %p\n", *(cArray_nkk + 2), (cArray_nkk + 2));
	printf("cArray_nkk[3] = %c	\t At Address : %p\n", *(cArray_nkk + 3), (cArray_nkk + 3));
	printf("cArray_nkk[4] = %c	\t At Address : %p\n", *(cArray_nkk + 4), (cArray_nkk + 4));
	printf("cArray_nkk[5] = %c	\t At Address : %p\n", *(cArray_nkk + 5), (cArray_nkk + 5));
	printf("cArray_nkk[6] = %c	\t At Address : %p\n", *(cArray_nkk + 6), (cArray_nkk + 6));
	printf("cArray_nkk[7] = %c	\t At Address : %p\n", *(cArray_nkk + 7), (cArray_nkk + 7));
	printf("cArray_nkk[8] = %c	\t At Address : %p\n", *(cArray_nkk + 8), (cArray_nkk + 8));
	printf("cArray_nkk[9] = %c	\t At Address : %p\n", *(cArray_nkk + 9), (cArray_nkk + 9));
	printf("cArray_nkk[10] = %c	\t At Address : %p\n", *(cArray_nkk + 10), (cArray_nkk + 10));
	printf("cArray_nkk[11] = %c	\t At Address : %p\n", *(cArray_nkk + 11), (cArray_nkk + 11));
	printf("cArray_nkk[12] = %c	\t At Address : %p\n", *(cArray_nkk + 12), (cArray_nkk + 12));
	printf("cArray_nkk[13] = %c	\t At Address : %p\n", *(cArray_nkk + 13), (cArray_nkk + 13));

	return(0);
}
