#include<stdio.h>

int main(void)
{
	//code
	printf("\n\n");
	printf("***********************************************************************************************************************");
	printf("\n\n");

	printf("Hello World!!! \n\n");
	
	int nkk_a = 13;
	printf("Integer Decimal Value of 'nkk_a' = %d \n", nkk_a);
	printf("Integer Octal Value of 'nkk_a' = %o \n", nkk_a);
	printf("Integer Hexadecimal Value of 'nkk_a' (Hexadecimal Letters In Lower Case) = %x \n", nkk_a);
	printf("Integer Hexadecimal Value of 'nkk_a' (Hexadecimal Letters In Lower Case) = %X \n\n", nkk_a);
	
	char nkk_ch = 'A';
	printf("Character nkk_ch = %c\n", nkk_ch);
	char nkk_str[] = "Astromedicomp's Real Time Rendering Batch";
	printf("String str = %s \n\n", nkk_str);
	
	long nkk_num = 30121995L;
	printf("Long Integer = %ld \n\n", nkk_num);
	
	unsigned int nkk_b = 7;
	printf("Long Integer = %u \n\n", nkk_b);
	
	float nkk_f_num = 3012.1995f;
	printf("Floating Point Number With Just %%f 'nkk_f_num' = %f \n", nkk_f_num);
	printf("Floating Point Number With Just %%4.2f 'nkk_f_num' = %4.2f \n", nkk_f_num);
	printf("Floating Point Number With Just %%6.5f 'nkk_f_num' = %6.5f \n", nkk_f_num);
	
	double nkk_d_pi = 3.14159265358979323846;
	printf("Double Precision Floating Point Number Without Exponential = %g\n", nkk_d_pi);
	printf("Double Precision Floating Point Number With Exponential(Lower Case) = %e\n", nkk_d_pi);
	printf("Double Precision Floating Point Number With Exponential(Upper Case) = %E\n", nkk_d_pi);
	printf("Double Hexadecimal Value of 'nkk_d_pi' (Hexadecimal Letters In Lower Case) = %a\n", nkk_d_pi);
	printf("Double Hexadecimal Value of 'nkk_d_pi' (Hexadecimal Letters In Upper Case) = %A\n", nkk_d_pi);
	
	printf("***********************************************************************************************************************");
	
	printf("\n\n");
	return(0);
}