#include<stdio.h>

#define SYMBOLICONST	999


int main(void)
{
	//code
	printf("\n\n");

	printf("Size of 'int'				=%ld bytes\n", sizeof(int));
	printf("Size of 'unsigned int'		=%ld bytes\n", sizeof(unsigned int));
	printf("Size of 'long'				=%ld bytes\n", sizeof(long));
	printf("Size of 'long long'			=%ld bytes\n", sizeof(long long));

	printf("Size of 'float'				=%ld bytes\n", sizeof(float));
	printf("Size of 'double',			=%ld bytes\n", sizeof(double));
	printf("Size of 'long double',		=%ld bytes\n", sizeof(long double));

	printf("Size of Symbolic Constant	=%ld bytes\n", sizeof(SYMBOLICONST));
	printf("Size of 'char'				=%ld bytes\n", sizeof(char));
	printf("Size of 'NULL'				=%ld bytes\n", sizeof(NULL)); //((void*)0));


	printf("\n--------------------------------------------------------------------------------\n");
	
	printf("After removing the warning of %ld and implicit casting into long");

	printf("Size of 'int'				=%ld bytes\n", (long)sizeof(int));
	printf("Size of 'unsigned int'		=%ld bytes\n", (long)sizeof(unsigned int));
	printf("Size of 'long'				=%ld bytes\n", (long)sizeof(long));
	printf("Size of 'long long'			=%ld bytes\n", (long)sizeof(long long));

	printf("Size of 'float'				=%ld bytes\n", (long)sizeof(float));
	printf("Size of 'double',			=%ld bytes\n", (long)sizeof(double));
	printf("Size of 'long double',		=%ld bytes\n", (long)sizeof(long double));

	printf("Size of Symbolic Constant	=%ld bytes\n", (long)sizeof(SYMBOLICONST));
	printf("Size of 'char'				=%ld bytes\n", (long)sizeof(char));
	printf("Size of 'NULL'				=%ld bytes\n", (long)sizeof(NULL)); //((void*)0));

	int i;
	printf("Size of 'escape sequence character'			=%ld bytes\n", (long)sizeof(i));
	printf("Size of 'escape sequence character'			=%ld bytes\n", (long)sizeof("\\0"));
	printf("Size of 'escape sequence character as string literal'	=%ld bytes\n", (long)sizeof(L'\\0'));
	printf("Size of 'escape sequence character'				=%ld bytes\n", (long)sizeof(L"\\0"));
	printf("Size of 'number'				=%ld bytes\n", (long)sizeof("\\n"));


	printf("\n\n");

	return(0);
}
