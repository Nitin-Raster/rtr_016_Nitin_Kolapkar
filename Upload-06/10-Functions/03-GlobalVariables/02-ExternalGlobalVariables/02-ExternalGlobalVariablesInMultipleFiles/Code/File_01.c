// ****** GLOBAL SCOPE ******

// global_count_nkk is a global variable declared in source code file 02_ExtGlobalVar_01ExtGlobVarInMultipleFile_C.c
// To Access it in this file, it must be first be re-declared as an external variable in the global scope of this file along with the 'extern' keyword and its proper data type
// Then, it can be used as any ordinary global variable throughout this file as well

#include<stdio.h>

extern int global_count_nkk;

void change_count_one(void)
{
	// Code
	global_count_nkk = global_count_nkk + 1;
	printf("change_count_one() : Value Of global_count_nkk in File_01 = %d\n", global_count_nkk);
}
