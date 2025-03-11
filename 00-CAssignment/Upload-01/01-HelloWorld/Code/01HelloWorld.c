#include<stdio.h>

#define A "Hello"
#define B 300

enum
{
	ZERO = 0,
	TWO = 2,
	FOUR,
	SIX,
	EIGHT

};
int main(void)
{
	int a = -10, b = 3, c= 0;
		int d = c++ && ++b || a++;
	//code
	printf("Hello World Neo!!! %d %d %d %d\n", a,b,c,d);
	return(0);
}