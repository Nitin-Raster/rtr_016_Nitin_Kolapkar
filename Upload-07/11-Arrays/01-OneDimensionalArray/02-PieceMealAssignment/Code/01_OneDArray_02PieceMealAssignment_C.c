#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int iArrayOne_nkk[10];
	int iArrayTwo_nkk[10];

	// Code

	// ****** iArrayOne_nkk[] ******
	iArrayOne_nkk[0] = 3;
	iArrayOne_nkk[1] = 6;
	iArrayOne_nkk[2] = 9;
	iArrayOne_nkk[3] = 12;
	iArrayOne_nkk[4] = 15;
	iArrayOne_nkk[5] = 18;
	iArrayOne_nkk[6] = 21;
	iArrayOne_nkk[7] = 24;
	iArrayOne_nkk[8] = 27;
	iArrayOne_nkk[9] = 30;

	printf("\n\n");
	printf("Piece-meal (Hard-coded) Assignment And Display Of Elements to Array 'iArrayOne_nkk[]': \n\n");
	printf("1st Element Of Array 'iArrayOne_nkk[]' Or Element At 0th Index Of Array 'iArrayOne_nkk' = %d\n", iArrayOne_nkk[0]);
	printf("2nd Element Of Array 'iArrayOne_nkk[]' Or Element At 2nd Index Of Array 'iArrayOne_nkk' = %d\n", iArrayOne_nkk[1]);
	printf("3rd Element Of Array 'iArrayOne_nkk[]' Or Element At 3rd Index Of Array 'iArrayOne_nkk' = %d\n", iArrayOne_nkk[2]);
	printf("4th Element Of Array 'iArrayOne_nkk[]' Or Element At 4th Index Of Array 'iArrayOne_nkk' = %d\n", iArrayOne_nkk[3]);
	printf("5th Element Of Array 'iArrayOne_nkk[]' Or Element At 5th Index Of Array 'iArrayOne_nkk' = %d\n", iArrayOne_nkk[4]);
	printf("6th Element Of Array 'iArrayOne_nkk[]' Or Element At 6th Index Of Array 'iArrayOne_nkk' = %d\n", iArrayOne_nkk[5]);
	printf("7th Element Of Array 'iArrayOne_nkk[]' Or Element At 7th Index Of Array 'iArrayOne_nkk' = %d\n", iArrayOne_nkk[6]);
	printf("8th Element Of Array 'iArrayOne_nkk[]' Or Element At 8th Index Of Array 'iArrayOne_nkk' = %d\n", iArrayOne_nkk[7]);
	printf("9th Element Of Array 'iArrayOne_nkk[]' Or Element At 9th Index Of Array 'iArrayOne_nkk' = %d\n", iArrayOne_nkk[8]);
	printf("10th Element Of Array 'iArrayOne_nkk[]' Or Element At 10th Index Of Array 'iArrayOne_nkk' = %d\n", iArrayOne_nkk[9]);


	// ****** iArrayTwo_nkk[] ******
	printf("\n\n");

	printf("Enter 1st Element of Array 'iArrayTwo_nkk[]' : ");
	scanf("%d", &iArrayTwo_nkk[0]);
	printf("Enter 2nd Element of Array 'iArrayTwo_nkk[]' : ");
	scanf("%d", &iArrayTwo_nkk[1]);
	printf("Enter 3rd Element of Array 'iArrayTwo_nkk[]' : ");
	scanf("%d", &iArrayTwo_nkk[2]);
	printf("Enter 4th Element of Array 'iArrayTwo_nkk[]' : ");
	scanf("%d", &iArrayTwo_nkk[3]);
	printf("Enter 5th Element of Array 'iArrayTwo_nkk[]' : ");
	scanf("%d", &iArrayTwo_nkk[4]);
	printf("Enter 6th Element of Array 'iArrayTwo_nkk[]' : ");
	scanf("%d", &iArrayTwo_nkk[5]);
	printf("Enter 7th Element of Array 'iArrayTwo_nkk[]' : ");
	scanf("%d", &iArrayTwo_nkk[6]);
	printf("Enter 8th Element of Array 'iArrayTwo_nkk[]' : ");
	scanf("%d", &iArrayTwo_nkk[7]);
	printf("Enter 9th Element of Array 'iArrayTwo_nkk[]' : ");
	scanf("%d", &iArrayTwo_nkk[8]);
	printf("Enter 10th Element of Array 'iArrayTwo_nkk[]' : ");
	scanf("%d", &iArrayTwo_nkk[9]);

	printf("\n\n");
	printf("Piece-meal (User Input) Assignment And Display Of Elements to Array 'iArrayTwo_nkk[]': \n\n");
	printf("1st Element Of Array 'iArrayTwo_nkk[]' Or Element At 0th Index Of Array 'iArrayTwo_nkk' = %d\n", iArrayTwo_nkk[0]);			  													 
	printf("2nd Element Of Array 'iArrayTwo_nkk[]' Or Element At 2nd Index Of Array 'iArrayTwo_nkk' = %d\n", iArrayTwo_nkk[1]);
	printf("3rd Element Of Array 'iArrayTwo_nkk[]' Or Element At 3rd Index Of Array 'iArrayTwo_nkk' = %d\n", iArrayTwo_nkk[2]);
	printf("4th Element Of Array 'iArrayTwo_nkk[]' Or Element At 4th Index Of Array 'iArrayTwo_nkk' = %d\n", iArrayTwo_nkk[3]);
	printf("5th Element Of Array 'iArrayTwo_nkk[]' Or Element At 5th Index Of Array 'iArrayTwo_nkk' = %d\n", iArrayTwo_nkk[4]);
	printf("6th Element Of Array 'iArrayTwo_nkk[]' Or Element At 6th Index Of Array 'iArrayTwo_nkk' = %d\n", iArrayTwo_nkk[5]);
	printf("7th Element Of Array 'iArrayTwo_nkk[]' Or Element At 7th Index Of Array 'iArrayTwo_nkk' = %d\n", iArrayTwo_nkk[6]);
	printf("8th Element Of Array 'iArrayTwo_nkk[]' Or Element At 8th Index Of Array 'iArrayTwo_nkk' = %d\n", iArrayTwo_nkk[7]);
	printf("9th Element Of Array 'iArrayTwo_nkk[]' Or Element At 9th Index Of Array 'iArrayTwo_nkk' = %d\n", iArrayTwo_nkk[8]);
	printf("10th Element Of Array 'iArrayTwo_nkk[]' Or Element At 10th Index Of Array 'iArrayTwo_nkk' = %d\n", iArrayTwo_nkk[9]);

	return(0);
}