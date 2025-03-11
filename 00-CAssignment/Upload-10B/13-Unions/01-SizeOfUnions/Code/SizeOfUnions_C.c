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
	printf("Size Of MyStruct = %lu\n", sizeof(s_nkk));
	printf("\n\n");
	printf("Size Of MyUnion = %lu\n", sizeof(u_nkk));
	return (0);
}

