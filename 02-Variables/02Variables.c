#include<stdio.h>

int main(void)
{
	//variable declarations
	int nkk_i = 5;
	float nkk_f = 3.9f;
	double nkk_d = 8.041997;
	char nkk_c = 'A';

	//code
	printf("\n\n");

	printf("nkk_i = %d\n", nkk_i);
	printf("nkk_f = %f\n", nkk_f);
	printf("nkk_d = %lf\n", nkk_d);
	printf("nkk_c = %c\n", nkk_c);

	printf("\n\n");

	nkk_i = 43;
	nkk_f = 6.54f;
	nkk_d = 26.1294;
	nkk_c = 'P';

	printf("nkk_i = %d\n", nkk_i);
	printf("nkk_f = %f\n", nkk_f);
	printf("nkk_d = %lf\n", nkk_d);
	printf("nkk_c = %c\n", nkk_c);

	return(0);
}