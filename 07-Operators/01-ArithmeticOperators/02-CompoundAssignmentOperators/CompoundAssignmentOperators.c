#include<stdio.h>

int main(void)
{
	//variable declarations
	int a;
	int b;
	int x;
	
	//code
	printf("\n\n");
	printf("Enter a Number: ");
	scanf("%d", &a);
	
	printf("\n\n");
	printf("Enter another number: ");
	scanf("%d", &b);
	
	printf("\n\n");
	
	// Since, In All the following 5 cases, The Operand on the left 'a' is getting repeated immediately on the right (e.g. : a = a + b or a = a - b),
	//We are using compound assignment operators +=, -=, *=, /= and %=

	// Since, 'a' Will be assigned the value of (a + b) at the expression (a += b), We must save the original value of 'a' to another variable (x)
	x = a;
	a += b; //a = a + b;
	printf("Addition of A = %d And B = %d Gives %d. \n", x, b, a);
	
	//Value of 'a' Altered in tyhe above expression is used here...
	//Since, 'a' will be assigned the value of (a - b) at the expression (a -= b), We must save the original value of 'a' to another variable (x)
	x = a;
	a -= b; //a = a - b;
	
	printf("Substraction of A = %d And B = %d Gives %d.\n", x, b, a);
	
	//Value of 'a' Altered in the above expression is used here...
	//Since, 'a' Will be assigned the value of (a * b) at the expression (a *= b), We must Save the Original value of 'a' to another variable(x)
	x = a;
	a *= b; // a = a * b;
	printf("Multiplication of A= %d And B = %d Gives %d.\n", x, b, a);
	
	//Value of 'a' altered in the above expression is used here
	//Since, 'a' will be assigned the value of (a / b) at the expression (a /= b), We must save the original value of 'a' to another variable (x)
	x = a;
	a /= b; // a = a / b;
	printf("Division of A =%d And B = %d Gives Quotient %d.\n", x, b, a);
	
	//Value of 'a' altered in the above expression is used here...
	//Since, 'a' Will be assigned the value of (a % b) at the expression (a %= b), We must save the original value of 'a' to another variable (x)
	x = a;
	a %= b; //a = a % b;
	printf("Division of A = %d and B = %d Gives Remainder %d.\n", x, b, a);
	
	printf("\n\n");
	
	return(0);
	
}