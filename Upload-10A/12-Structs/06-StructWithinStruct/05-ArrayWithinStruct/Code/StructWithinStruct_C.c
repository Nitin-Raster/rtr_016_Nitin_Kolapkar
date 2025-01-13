#include <stdio.h>

struct MyNumber
{
	int num;
	int num_table[10];
};

struct NumTables
{
	struct MyNumber a;
	struct MyNumber b;
	struct MyNumber c;
};

int main(void)
{
	// Variable Declarations
	struct NumTables tables_nkk;
	int i_nkk;

	// Code
	tables_nkk.a.num = 2;
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		tables_nkk.a.num_table[i_nkk] = tables_nkk.a.num * (i_nkk + 1);
	printf("\n\n");
	printf("Table Of %d : \n\n", tables_nkk.a.num);
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("%d * %d = %d\n", tables_nkk.a.num, (i_nkk + 1), tables_nkk.a.num_table[i_nkk]);

	tables_nkk.a.num = 3;
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		tables_nkk.a.num_table[i_nkk] = tables_nkk.a.num * (i_nkk + 1);
	printf("\n\n");
	printf("Table Of %d : \n\n", tables_nkk.a.num);
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("%d * %d = %d\n", tables_nkk.a.num, (i_nkk + 1), tables_nkk.a.num_table[i_nkk]);

	tables_nkk.a.num = 4;
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		tables_nkk.a.num_table[i_nkk] = tables_nkk.a.num * (i_nkk + 1);
	printf("\n\n");
	printf("Table Of %d : \n\n", tables_nkk.a.num);
	for (i_nkk = 0; i_nkk < 10; i_nkk++)
		printf("%d * %d = %d\n", tables_nkk.a.num, (i_nkk + 1), tables_nkk.a.num_table[i_nkk]);

	return(0);
}
