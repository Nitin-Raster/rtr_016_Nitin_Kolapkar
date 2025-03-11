#include<stdio.h>

int main(void)
{
	//variable declarations
	int a;
	int b;
	int result;
	
	//code
	printf("\n\n");
	printf("Enter One Integer : ");
	scanf("%d", &a);
	
	printf("\n\n");
	printf("Enter another integer: ");
	scanf("%d", &b);

	printf("\n\n");
	printf("If Answer is = 0, It is 'FALSE'.\n");
	printf("If Answer is = 1, It is 'TRUE'.\n\n");
	
	result = (a < b);
	printf("(a < b) A = %d Is Less than B = %d						\t Answer = %d\n", a, b, result);
	
	result = (a > b);
	printf("(a > b) A = %d Is Greater than B = %d					\t Answer = %d\n", a, b, result);

	result = (a <= b);
	printf("(a <= b) A = %d Is less than or equal to B = %d			\t Answer = %d\n", a, b, result);
	
	result = (a >= b);
	printf("(a >= b) A = %d Is Greater than or equal to B = %d		\t Answer = %d\n", a, b, result);
	
	result = (a == b);
	printf("(a == b) A = %d Is Equal to B = %d						\t Answer = %d\n", a, b, result);
	
	result = (a != b);
	printf("(a != b) A = %d Is Not Equal to B = %d					\t Answer = %d\n", a, b, result);
	
	return(0);
	
}