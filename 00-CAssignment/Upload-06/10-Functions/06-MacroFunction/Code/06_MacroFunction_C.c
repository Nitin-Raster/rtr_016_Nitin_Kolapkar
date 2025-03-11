#include <stdio.h>

#define MAX_NUMBER(a,b) ((a > b) ? a : b)

int main(int argc, char *argv[], char *envp[])
{
	// Variable declarations
	int iNum_01_nkk;
	int iNum_02_nkk;
	int iResult_nkk;

	float fNum_01_nkk;
	float fNum_02_nkk;
	float fResult_nkk;

	// Code
	// ****** COMPARING INTEGER VALUES ******
	printf("\n\n");
	printf("Enter An Integer Number : \n\n");
	scanf("%d", &iNum_01_nkk);

	printf("\n\n");
	printf("Enter An Integer Number : \n\n");
	scanf("%d", &iNum_02_nkk);

	iResult_nkk = MAX_NUMBER(iNum_01_nkk, iNum_02_nkk);
	printf("\n\n");
	printf("Result Of Macro Function MAX_NUMBER() = %d\n", iResult_nkk);

	printf("\n\n");

	// ****** COMPARING FLOATING - POINT VALUES ******
	printf("\n\n");
	printf("Enter a Floating Point Number : \n\n");
	scanf("%f", &fNum_01_nkk);

	printf("\n\n");
	printf("Enter Another Floating Point Number : \n\n");
	scanf("%f", &fNum_02_nkk);

	fResult_nkk = MAX_NUMBER(fNum_01_nkk, fNum_02_nkk);
	printf("\n\n");
	printf("Result Of Macro Function MAX_NUMBER() = %f\n", fResult_nkk);

	printf("\n\n");

	return(0);

}

