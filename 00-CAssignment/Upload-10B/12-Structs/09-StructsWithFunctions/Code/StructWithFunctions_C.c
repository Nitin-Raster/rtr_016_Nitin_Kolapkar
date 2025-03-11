#include <stdio.h>

// DEFINING STRUCT
struct MyData
{
	int i;
	float f;
	double d;
	char c;
};

int main(void)
{
	// Function Prototype
	struct MyData AddStructMembers(struct MyData, struct MyData, struct MyData);

	// Variable Declarations
	struct MyData data_nkk1, data_nkk2, data_nkk3, answer_data_nkk;

	// Code
	// ******** Data1 ********
	printf("\n\n\n\n");
	printf("******** DATA 1 ********\n\n");
	printf("Enter Integer Value For 'i' Of 'struct MyData data_nkk1' : ");
	scanf("%d", &data_nkk1.i);

	printf("\n\n");
	printf("Enter Floating-Point Value For 'f' Of 'struct MyData data_nkk1' : ");
	scanf("%f", &data_nkk1.f);

	printf("\n\n");
	printf("Enter 'Double' Value For 'd' Of 'struct MyData data_nkk1' : ");
	scanf("%lf", &data_nkk1.d);

	printf("\n\n");
	printf("Enter Character Value For 'c' Of 'struct MyData data_nkk1' : ");
	data_nkk1.c = getch();
	printf("%c", data_nkk1.c);

	// ******** Data2 ********
	printf("\n\n\n\n");
	printf("******** DATA 2 ********\n\n");
	printf("Enter Integer Value For 'i' Of 'struct MyData data_nkk2' : ");
	scanf("%d", &data_nkk2.i);

	printf("\n\n");
	printf("Enter Floating-Point Value For 'f' Of 'struct MyData data_nkk2' : ");
	scanf("%f", &data_nkk2.f);

	printf("\n\n");
	printf("Enter 'Double' Value For 'd' Of 'struct MyData data_nkk2' : ");
	scanf("%lf", &data_nkk2.d);

	printf("\n\n");
	printf("Enter Character Value For 'c' Of 'struct MyData data_nkk2' : ");
	data_nkk2.c = getch();
	printf("%c", data_nkk2.c);

	// ******** Data3 ********
	printf("\n\n\n\n");
	printf("******** DATA 3 ********\n\n");
	printf("Enter Integer Value For 'i' Of 'struct MyData data_nkk3' : ");
	scanf("%d", &data_nkk3.i);

	printf("\n\n");
	printf("Enter Floating-Point Value For 'f' Of 'struct MyData data_nkk3' : ");
	scanf("%f", &data_nkk3.f);

	printf("\n\n");
	printf("Enter 'Double' Value For 'd' Of 'struct MyData data_nkk3' : ");
	scanf("%lf", &data_nkk3.d);

	printf("\n\n");
	printf("Enter Character Value For 'c' Of 'struct MyData data_nkk3' : ");
	data_nkk3.c = getch();
	printf("%c", data_nkk3.c);

	// ******** CALLING FUNCTION AddStructMembers() WHICH ACCEPTS THREE VARIABLES OF TYPE 'struct MyData' AS PARAMETERS AND ADDS UP THE RESPECTIVE MEMBERS OF  TYOE 'stuct MyData' AS PARAMETERS AND ADDS UP THE RESPECTIVE MEMBERS AND RETURNS THE ANSWER IN ANOTHER struct OF SAME TYPE ********
	answer_data_nkk = AddStructMembers(data_nkk1, data_nkk2, data_nkk3);

	printf("\n\n\n\n");
	printf("******** ANSWER ********\n\n");
	printf("answer_data_nkk.i = %d\n", answer_data_nkk.i);
	printf("answer_data_nkk.f = %f\n", answer_data_nkk.f);
	printf("answer_data_nkk.d = %lf\n", answer_data_nkk.d);

	answer_data_nkk.c = data_nkk1.c;
	printf("answer_data_nkk.c (from data1) = %c\n\n", answer_data_nkk.c);

	answer_data_nkk.c = data_nkk2.c;
	printf("answer_data_nkk.c (from data2) = %c\n\n", answer_data_nkk.c);

	answer_data_nkk.c = data_nkk3.c;
	printf("answer_data_nkk.c (from data3) = %c\n\n", answer_data_nkk.c);

	return(0);
}

struct MyData AddStructMembers(struct MyData md_one, struct MyData md_two, struct MyData md_three)
{
	// Variable Declarations
	struct MyData answer;

	// code
	answer.i = md_one.i + md_two.i + md_three.i;
	answer.f = md_one.f + md_two.f + md_three.f;
	answer.d = md_one.d + md_two.d + md_three.d;
	return(answer);
}