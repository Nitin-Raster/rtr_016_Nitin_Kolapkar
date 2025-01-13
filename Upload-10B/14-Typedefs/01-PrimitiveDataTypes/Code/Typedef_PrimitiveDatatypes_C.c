#include <stdio.h>

// Global typedef
typedef int MY_INT; // "type" int has been re"def"ined as MY_INT ... Now, "MY_INT" can be treated just like "int"

int main(void)
{
	// Function prototype
	MY_INT Add(MY_INT, MY_INT);

	// Typedef
	typedef int MY_INT; // "type" int has been re"def"ined as MY_INT ... Now, "MY_INT" can be treated just like "int"
	typedef float NKK_FLOAT; // "type" float has been re"def"ined as NKK_FLOAT ... Now, "NKK_FLOAT" can be treated just like "float"
	typedef char CHARACTER; // "type" char has been re"def"ined as CHARACTER ... Now, "CHARACTER" can be treated just like "char"
	typedef double MY_DOUBLE; // "type" double has been re"def"ined as MY_DOUBLE ... Now, "MY_DOUBLE" can be treated just like "double"

	// ******** JUST LIKE IN Win32SDK !!! ********
	typedef unsigned int UINT;
	typedef UINT HANDLE;
	typedef HANDLE HWND;
	typedef HANDLE HINSTANCE;

	// Variable Declarations
	MY_INT a = 10, i;
	MY_INT iArray[] = { 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 };

	NKK_FLOAT f_nkk = 17.17f;
	const NKK_FLOAT f_nkk_pi = 3.14f;

	CHARACTER ch = '*';
	CHARACTER chArray_01[] = "HELLO";
	CHARACTER chArray_02[][10] = {"RTR", "Batch", "2024-2025"};

	MY_DOUBLE d = 7.77777;

	// ******** JUST RANDOM NUMBERS - THEY HAVE NOTHING TO DO WITH ANY WINDWOS'S HANDLE OR INSTANCE HANDLE !!! This is just for understanding ********
	UINT uint = 1234;
	HANDLE handle = 789;
	HWND hwnd = 4567;
	HINSTANCE hInstance = 963852;

	// Code
	printf("\n\n");
	printf("Type MY_INT variable a = %d\n", a);

	printf("\n\n");
	for (i = 0; i < (sizeof(iArray) / sizeof(int)); i++)
	{
		printf("Type MY_INT array variable iArray[%d] = %d\n", i, iArray[i]);
	}
	printf("\n\n");

	printf("\n\n");
	printf("Type NKK_FLOAT variable f_nkk = %f\n", f_nkk);
	printf("Type NKK_FLOAT constant f_nkk_pi = %f\n", f_nkk_pi);

	printf("\n\n");
	printf("Type MY_DOUBLE variable d = %lf\n", d);

	printf("\n\n");
	printf("Type CHARACTER variable ch = %c\n", ch);

	printf("\n\n");
	printf("Type CHARACTER array variable chArray_01 = %s\n", chArray_01);

	printf("\n\n");
	for (i = 0; i < (sizeof(chArray_02) / sizeof(chArray_02[0])); i++)
	{
		printf("%s\t", chArray_02[i]);
	}
	printf("\n\n");

	printf("\n\n");
	printf("Type UINT variable uint = %u\n\n", uint);
	printf("Type HANDLE variable handle = %u\n\n", handle);
	printf("Type HWND variable hwnd = %u\n\n", hwnd);
	printf("Type HINSTANC variable hInstance = %u\n\n", hInstance);
	printf("\n\n");

	MY_INT x = 90;
	MY_INT y = 30;
	MY_INT ret;

	ret = Add(x, y);
	printf("ret = %d", ret);

	return(0);
}

MY_INT Add(MY_INT a, MY_INT b)
{
	// code
	MY_INT c;
	c = a + b;
	return(c);
}
