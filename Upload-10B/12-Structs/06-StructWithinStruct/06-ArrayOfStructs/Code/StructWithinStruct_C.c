#include <stdio.h>

struct MyNumber
{
	int num;
	int num_table[10];
};

struct NumTables
{
	struct MyNumber n;
};

int main(void)
{
	// Variable Declarations
	struct NumTables table_nkk[10]; // an Array of 10 'struct NumTables'
	int i, j;

	// Code
	for (i = 0; i < 10; i++)
	{
		table_nkk[i].n.num = (i + 1);
	}

	for (i = 0; i < 10; i++)
	{
		printf("\n\n");
		printf("Table Of %d : \n\n", table_nkk[i].n.num);
		for (j = 0; j < 10; j++)
		{
			table_nkk[i].n.num_table[j] = table_nkk[i].n.num * (j + 1);
			printf("%d * %d = %d\n", table_nkk[i].n.num, (j + 1), table_nkk[i].n.num_table[j]);
		}
	}
	return(0);
}

