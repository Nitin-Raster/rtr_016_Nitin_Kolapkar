#include <stdio.h>

// ****** GLOBAL SCOPE ******
int global_count_nkk;

int main(void)
{
	// Function Prototypes
	void change_count(void);
	void change_count_one(void); // Function Defines in File_01.c
	void change_count_two(void); // Function Defines in File_02.c
	
	// Code
	printf("\n");

	change_count();
	change_count_one(); // Function Defined in File_01.c
	change_count_two(); // Function Defined in File_02.c

	return(0);
}

void change_count(void) // Function Definition
{
	// Code
	global_count_nkk = global_count_nkk + 1;
	printf("Global_count_nkk = %d\n", global_count_nkk);
}
