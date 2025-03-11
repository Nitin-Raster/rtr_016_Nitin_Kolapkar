#include <stdio.h>
#include <stdarg.h>

int main(void)
{
	// function prototype
	int CalculateSum(int, ...);

	// Variable Declarations
	int answer;

	// Code
	printf("\n\n");

	answer = CalculateSum(5, 10, 20, 30, 40, 50);
	printf("Answer = %d\n\n", answer);

	answer = CalculateSum(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	printf("Answer = %d\n\n", answer);

	answer = CalculateSum(0);
	printf("Answer = %d\n\n", answer);

	return(0);
}

int CalculateSum(int num, ...) // VARIADIC FUNCTION
{
	// Function Declarations
	int va_CalculateSum(int, va_list);

	// Variable Declarations
	int sum_total = 0;
	va_list numbers_list;

	// Code
	va_start(numbers_list, num);

	sum_total = va_CalculateSum(num, numbers_list);

	va_end(numbers_list);
	return(sum_total);
}

int va_CalculateSum(int num, va_list list) // Variadic Function
{
	// Variable Declaration
	int sum_total = 0;
	int n;

	// Code
	while (num)
	{
		n = va_arg(list, int);
		sum_total = sum_total + n;
		num--;
	}

	return(sum_total);
}

