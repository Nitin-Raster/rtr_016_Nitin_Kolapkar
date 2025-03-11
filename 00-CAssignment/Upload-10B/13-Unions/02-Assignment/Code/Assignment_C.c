#include <stdio.h>

union MyUnion
{
	int i;
	float f;
	double d;
	char c;
};

int main(void)
{
	// Variable Declarations
	union MyUnion u1_nkk, u2_nkk;

	// Code
	// ******** MyUnion u1 ********
	printf("\n\n");
	printf("Members Of Union u1 Are : \n\n");

	u1_nkk.i = 8;
	u1_nkk.f = 8.8888f;
	u1_nkk.d = 8.8888;
	u1_nkk.c = 'N';

	printf("u1_nkk.i = %d\n\n", u1_nkk.i);
	printf("u1_nkk.f = %f\n\n", u1_nkk.f);
	printf("u1_nkk.d = %lf\n\n", u1_nkk.d);
	printf("u1_nkk.c = %c\n\n", u1_nkk.c);

	printf("Addresses Of Members Of Union u1 Are : \n\n");
	printf("u1_nkk.i = %p\n\n", &u1_nkk.i);
	printf("u1_nkk.f = %p\n\n", &u1_nkk.f);
	printf("u1_nkk.d = %p\n\n", &u1_nkk.d);
	printf("u1_nkk.c = %p\n\n", &u1_nkk.c);

	printf("MyUnion u1 = %p\n\n", &u1_nkk);

	// ******** MyUnion u2 ********
	printf("\n\n");
	printf("Members Of Union u2 Are : \n\n");

	u2_nkk.i = 7;
	printf("u2_nkk.i = %d\n\n", u2_nkk.i);

	u2_nkk.f = 7.7777f;
	printf("u2_nkk.f = %f\n\n", u2_nkk.f);

	u2_nkk.d = 7.77777;
	printf("u2_nkk.d = %lf\n\n", u2_nkk.d);

	u2_nkk.c = 'NN';
	printf("u2_nkk.c = %c\n\n", u2_nkk.c);


	printf("Addresses Of Members Of Union u2 Are : \n\n");
	printf("u2_nkk.i = %p\n\n", &u2_nkk.i);
	printf("u2_nkk.f = %p\n\n", &u2_nkk.f);
	printf("u2_nkk.d = %p\n\n", &u2_nkk.d);
	printf("u2_nkk.c = %p\n\n", &u2_nkk.c);

	printf("MyUnion u2 = %p\n\n", &u2_nkk);

	return (0);
}

