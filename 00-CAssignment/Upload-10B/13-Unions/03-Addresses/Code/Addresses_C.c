#include <stdio.h>

struct MyStruct
{
	int i;
	float f;
	double d;
	char c;
};

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
	struct MyStruct s_nkk;
	union MyUnion u_nkk;

	// Code
	printf("\n\n");
	printf("Members Of Struct Are : \n\n");

	s_nkk.i = 8;
	s_nkk.f = 8.8888f;
	s_nkk.d = 8.8888;
	s_nkk.c = 'N';

	printf("s_nkk.i = %d\n\n", s_nkk.i);
	printf("s_nkk.f = %f\n\n", s_nkk.f);
	printf("s_nkk.d = %lf\n\n", s_nkk.d);
	printf("s_nkk.c = %c\n\n", s_nkk.c);


	printf("Addresses Of Members Of Struct Are : \n\n");
	printf("s_nkk.i = %p\n\n", &s_nkk.i);
	printf("s_nkk.f = %p\n\n", &s_nkk.f);
	printf("s_nkk.d = %p\n\n", &s_nkk.d);
	printf("s_nkk.c = %p\n\n", &s_nkk.c);

	printf("MyStruct s = %p\n\n", &s_nkk);

	printf("\n\n");
	printf("Members Of Union Are : \n\n");

	u_nkk.i = 5;
	printf("u_nkk.i = %d\n\n", u_nkk.i);

	u_nkk.f = 5.5555f;
	printf("u_nkk.f = %f\n\n", u_nkk.f);

	u_nkk.d = 6.66666;
	printf("u_nkk.d = %lf\n\n", u_nkk.d);

	u_nkk.c = 'B';
	printf("u_nkk.c = %c\n\n", u_nkk.c);


	printf("Addresses Of Members Of Union Are : \n\n");
	printf("u_nkk.i = %p\n\n", &u_nkk.i);
	printf("u_nkk.f = %p\n\n", &u_nkk.f);
	printf("u_nkk.d = %p\n\n", &u_nkk.d);
	printf("u_nkk.c = %p\n\n", &u_nkk.c);

	printf("MyUnion u = %p\n\n", &u_nkk);

	return (0);
}

