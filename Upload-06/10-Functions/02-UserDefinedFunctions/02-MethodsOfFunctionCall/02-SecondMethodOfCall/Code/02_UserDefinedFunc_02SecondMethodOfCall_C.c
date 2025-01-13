#include <stdio.h> //'stdio.h' contains declarations of 'printf()'

// ****** USER DEFINED FUNCTIONS : METHOD OF CALLING FUNCTION 2 ******
// ****** CALLING ONLY TWO FUNCTIONS DIRECTLY IN main(), REST OF THE FUNCTIONS TRACE THEIR CALL INDIRECTLY TO main() ******

int main(int argc, char* argv[], char* envp[])
{
	// Function prototypes
	void display_information(void);
	void Function_Country(void);

	// Code
	display_information(); // function call
	Function_Country(); // function call

	return (0);
}

// ****** User-Defined Functions' Definitions... ******
void display_information(void) // Function Definition
{
	//Function prototypes
	void Function_My(void);
	void Function_Name(void);
	void Function_Is(void);
	void Function_FirstName(void);
	void Function_MiddleName(void);
	void Function_Surname(void);
	void Function_OfAMC(void);

	// Code

	// *** FUNCTION_CALLS ***
	Function_My();
	Function_Name();
	Function_Is();
	Function_FirstName();
	Function_MiddleName();
	Function_Surname();
	Function_OfAMC();
}

void Function_My(void) // Function Definition
{
	// Code
	printf("\n\n");

	printf("My");
}

void Function_Name(void) // Function Definition
{
	//code
	printf("\n\n");

	printf("Name");
}

void Function_Is(void) // Function Definition
{
	// Code
	printf("\n\n");

	printf("Is");
}

void Function_FirstName(void) // Function Definition
{
	// Code
	printf("\n\n");

	printf("Nitin");
}

void Function_MiddleName(void) // Function Definition
{
	// Code
	printf("\n\n");

	printf("Kishor");
}

void Function_Surname(void) // Function Definition
{
	// Code
	printf("\n\n");

	printf("Kolapkar");
}

void Function_OfAMC(void) // Function Definition
{
	// Code
	printf("\n\n");

	printf("Of ASTROMEDICOMP");
}

void Function_Country(void) // Function Definition
{
	// Code
	printf("\n\n");

	printf("I live In India");

	printf("\n\n");
}
