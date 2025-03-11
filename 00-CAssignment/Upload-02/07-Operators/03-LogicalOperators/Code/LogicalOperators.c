#include<stdio.h>

int main(void)
{
	//variable declarations
	int a;
	int b;
	int c;
	int result;
	
	//code
	printf("\n\n");
	printf("Enter first integer:");
	scanf("%d", &a);
	
	printf("\n\n");
	printf("Enter second integer:");
	scanf("%d", &b);
	
	printf("\n\n");
	printf("Enter third integer:");
	scanf("%d", &c);
	
	printf("If Answer is = 0, It is 'FALSE'.\n");
	printf("If Answer is = 1, It is 'TRUE'.\n\n");

	result = (a <= b) && (b != c);
	printf("LOGICAL AND (&&) : Answer is TRUE (1) If and only Both Conditions are True. The Answer is FALSE (0), If Any One or Both conditions are False.\n\n");
	printf("A = %d Is Less than or equal to B = %d AND B = %d Is not equal to C = %d	\tAnswer = %d \n\n", a, b, b, c, result);

	result = (b >= a) || (a == c);
	printf("LOGICAL OR (||) : Answer is FALSE (0) If and only if Both Conditions are False. The Answer is TRUE (1), If Any One or Both conditions are True.\n\n");
	printf("Either B = %d Is Greater than or equal to A = %d OR A = %d Is  equal to C = %d	\tAnswer = %d \n\n", b, a, a, c, result);

	result = !a;
	printf("A = %d and using Logical NOT (!) Operator on A gives Result = %d\n\n", a, result);
	
	result = !b;
	printf("B = %d and using Logical NOT (!) Operator on B gives Result = %d\n\n", b, result);
	
	result = !c;
	printf("C = %d and using Logical NOT (!) Operator on C gives Result = %d\n\n", c, result);
	
	result = (!(a <= b) && !(b != c));
	printf("Using Logical NOT (!) On (a <= b) And also on (b != c) And then AND-ing them afterwords gives result = %d\n", result);
	
	printf("\n\n");
	
	result = !((b >= a) || (a == c));
	printf("Using Logical NOT (!) On entire logical expression (b >= a) || (a == c) Gives result = %d\n", result);
	
	printf("\n\n");
	
	return(0);
	
}