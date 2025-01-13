#include <stdio.h> //'stdio.h' contains declarations of 'printf()'

// ****** USER DEFINED FUNCTIONS : METHOD OF CALLING FUNCTION 3 ******
// ****** CALLING ONLY ONE FUNCTION DIRECTLY IN main(), REST OF THE FUNCTIONS TRACE THEIR CALL INDIRECTLY TO main() ******

int main(int argc, char* argv[], char* envp[])
{
	// Function prototypes
	void Function_Country(void);

	// Code
	Function_Country(); // function call

	return (0);
}

void Function_Country(void) // Function Definition
{
	// Function declarations
	void Function_OfAMC(void);

	// Code
	Function_OfAMC();

	printf("\n\n");

	printf("I live In India");

	printf("\n\n");
}

void Function_OfAMC(void) // Function Definition
{
	// Function declaration
	void Function_Surname(void);

	// Code
	Function_Surname();

	printf("\n\n");

	printf("Of ASTROMEDICOMP");
}

void Function_Surname(void) // Function Definition
{
	// Function declarations
	void Function_MiddleName(void);
	
	// Code
	Function_MiddleName();

	printf("\n\n");

	printf("Kolapkar");
}

void Function_MiddleName(void) // Function Definition
{
	//Function Declarations
	void Function_FirstName(void);

	// Code
	Function_FirstName();

	printf("\n\n");

	printf("Kishor");
}

void Function_FirstName(void) // Function Definition
{
	//Function Declaration
	void Function_Is(void);

	// Code
	Function_Is();

	printf("\n\n");

	printf("Nitin");
}

void Function_Is(void) // Function Definition
{
	// Function Declaration
	void Function_Name(void);

	// Code
	Function_Name();

	printf("\n\n");

	printf("Is");
}

void Function_Name(void) // Function Definition
{
	//Function Declarations
	void Function_My(void);

	//code
	Function_My();

	printf("\n\n");

	printf("Name");
}

void Function_My(void) // Function Definition
{
	// Code
	printf("\n\n");

	printf("My");
}

