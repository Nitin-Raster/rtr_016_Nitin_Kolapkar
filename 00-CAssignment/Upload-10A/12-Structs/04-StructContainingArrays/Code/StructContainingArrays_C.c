#include <stdio.h>

#define INT_ARRAY_SIZE 10
#define FLOAT_ARRAY_SIZE 5
#define CHAR_ARRAY_SIZE 26

#define NUM_STRINGS 10
#define MAX_CHARACTERS_PER_STRINGS 20

#define ALPHABET_BEGINNING 65 // 'A'

struct MyDataOne
{
	int iArray[INT_ARRAY_SIZE];
	float fArray[FLOAT_ARRAY_SIZE];
};

struct MyDataTwo
{
	char cArray[CHAR_ARRAY_SIZE];
	char strArray[NUM_STRINGS][MAX_CHARACTERS_PER_STRINGS];
};

int main(void)
{
	// Varibale Declarations
	struct MyDataOne data_one_nkk;
	struct MyDataTwo data_two_nkk;
	int i_nkk;

	// code
	// ******** PIECE-MEAL ASSIGNMENT (HARD-CODED) ********
	data_one_nkk.fArray[0] = 0.1f;
	data_one_nkk.fArray[1] = 1.2f;
	data_one_nkk.fArray[2] = 2.3f;
	data_one_nkk.fArray[3] = 3.4f;
	data_one_nkk.fArray[4] = 4.5f;

	// ******** LOOP ASSIGNMENT (USER INPUT) ********
	printf("\n\n");
	printf("Enter %d Integers : \n\n", INT_ARRAY_SIZE);
	for (i_nkk = 0; i_nkk < INT_ARRAY_SIZE; i_nkk++)
		scanf("%d", &data_one_nkk.iArray[i_nkk]);

	// ******** LOOP ASSIGNMENT (HARD-CODED) ********
	for (i_nkk = 0; i_nkk < CHAR_ARRAY_SIZE; i_nkk++)
		data_two_nkk.cArray[i_nkk] = (char)(i_nkk + ALPHABET_BEGINNING);

	// ******** PIECE-MEAL ASSIGNMENT (HARD-CODED) ********
	strcpy(data_two_nkk.strArray[0], "Welcome !!!");
	strcpy(data_two_nkk.strArray[1], "This");
	strcpy(data_two_nkk.strArray[2], "Is");
	strcpy(data_two_nkk.strArray[3], "ASTROMEDICOMP's");
	strcpy(data_two_nkk.strArray[4], "Real");
	strcpy(data_two_nkk.strArray[5], "Time");
	strcpy(data_two_nkk.strArray[6], "Rendering");
	strcpy(data_two_nkk.strArray[7], "Batch");
	strcpy(data_two_nkk.strArray[8], "Of");
	strcpy(data_two_nkk.strArray[9], "2024-2025 !!!");

	// ******** DISPLAYING DATA MEMBERS OF 'struct DataOne_nkk' AND THEIR VALUES ********
	printf("\n\n");
	printf("Members Of 'struct DataOne_nkk' Along with Their Assigned Values Are : \n\n");

	printf("\n\n");
	printf("Integer Array (data_one.iArray[]) : \n\n");
	for (i_nkk = 0; i_nkk < INT_ARRAY_SIZE; i_nkk++)
		printf("data_one_nkk.iArray[%d] = %d\n", i_nkk, data_one_nkk.iArray[i_nkk]);

	printf("\n\n");
	printf("Floating-Point Array (data_one.fArray[]) : \n\n");
	for (i_nkk = 0; i_nkk < FLOAT_ARRAY_SIZE; i_nkk++)
		printf("data_one_nkk.fArray[%d] = %f\n", i_nkk, data_one_nkk.fArray[i_nkk]);

	// ******** DISPLAYING DATA MEMBERS OF 'struct DataTwo' AND THEIR VALUES ********
	printf("\n\n");
	printf("Members Of 'struct DataTwo_nkk' Alongwith Their Assigned Values Are : \n\n");

	printf("\n\n");
	printf("Character Array (data_two.cArray[]) : \n\n");
	for (i_nkk = 0; i_nkk < CHAR_ARRAY_SIZE; i_nkk++)
		printf("data_two_nkk.cArray[%d] = %c\n", i_nkk, data_two_nkk.cArray[i_nkk]);

	printf("\n\n");
	printf("String Array (data_two.strArray[]) : \n\n");
	for (i_nkk = 0; i_nkk < NUM_STRINGS; i_nkk++)
		printf("%s ", data_two_nkk.strArray[i_nkk]);

	printf("\n\n");

	return(0);
}