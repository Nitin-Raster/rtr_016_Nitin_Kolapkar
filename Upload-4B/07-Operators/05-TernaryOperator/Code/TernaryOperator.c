#include <stdio.h>

int main(void)
{
	// Variable Declacarions
	int a_nkk, b_nkk;
	int p_nkk, q_nkk;
	char ch_result_01, ch_result_02;
	int i_result_01, i_result_02;

	//code
	printf("\n\n");

	a_nkk = 7;
	b_nkk = 5;
	ch_result_01 = (a_nkk > b_nkk) ? 'A' : 'B';
	i_result_01 = (a_nkk > b_nkk) ? a_nkk : b_nkk;
	printf("Ternary Operator Answer 1 ----- %c and %d.\n\n", ch_result_01, i_result_01);

	p_nkk = 30;
	q_nkk = 30;
	ch_result_02 = (p_nkk != q_nkk) ? 'P' : 'Q';
	i_result_02 = (p_nkk != q_nkk) ? p_nkk : q_nkk;
	printf("Ternary Operator Answer 2 ----- %c and %d.\n\n", ch_result_02, i_result_02);


	p_nkk = 40;
	q_nkk = 30;
	ch_result_02 = (p_nkk != q_nkk) ? 'P' : 'Q';
	i_result_02 = (p_nkk != q_nkk) ? p_nkk : q_nkk;
	printf("Ternary Operator Answer 2 ----- %c and %d.\n\n", ch_result_02, i_result_02);

	printf("\n\n");
	return(0);

}