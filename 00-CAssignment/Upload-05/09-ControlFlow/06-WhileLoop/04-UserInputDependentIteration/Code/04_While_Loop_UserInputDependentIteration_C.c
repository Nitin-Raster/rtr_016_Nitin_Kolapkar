#include<stdio.h>

int main(void)
{
	// Variable Declarations
	int i_num, num_nkk, i_nkk;

	// Code
	printf("\n\n");

	printf("Enter An Integer Value From Which Iteration Must Begin : ");
	scanf("%d", &i_num);

	printf("How Many Digits Do You Want To Print From %d Onwards ? : ", i_num);
	scanf("%d", &num_nkk);

	printf("Printing Digits %d to %d : \n\n", i_num, (i_num + num_nkk));

	i_nkk = i_num;
	while (i_nkk <= (i_num + num_nkk))
	{
		printf("\t%d\n", i_nkk);
		i_nkk++;
	}
}