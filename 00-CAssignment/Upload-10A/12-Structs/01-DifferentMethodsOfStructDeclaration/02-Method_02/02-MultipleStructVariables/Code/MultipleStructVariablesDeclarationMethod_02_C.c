#include <stdio.h>

// DEFINING STRUCT
struct MyPoint
{
	int x;
	int y;
};

struct MyPoint point_A_nkk, point_B_nkk, point_C_nkk, point_D_nkk, point_E_nkk; // Declaring 5 struct variable of type 'struct MyPoint' globally ...

int main(void)
{
	// Code
	// Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_A'
	point_A_nkk.x = 7;
	point_A_nkk.y = 7;

	// Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_B'
	point_B_nkk.x = 8;
	point_B_nkk.y = 8;

	// Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_C'
	point_C_nkk.x = 5;
	point_C_nkk.y = 9;

	// Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_D'
	point_D_nkk.x = 2;
	point_D_nkk.y = 6;

	// Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_E'
	point_E_nkk.x = 6;
	point_E_nkk.y = 4;


	// Dispalying Values Of The Data Memebrs Of 'struct MyPoint' (all variables)
	printf("\n\n");
	printf("Co-ordinates (x,y) Of Point 'A' Are : (%d, %d)\n\n", point_A_nkk.x, point_A_nkk.y);
	printf("Co-ordinates (x,y) Of Point 'B' Are : (%d, %d)\n\n", point_B_nkk.x, point_B_nkk.y);
	printf("Co-ordinates (x,y) Of Point 'C' Are : (%d, %d)\n\n", point_C_nkk.x, point_C_nkk.y);
	printf("Co-ordinates (x,y) Of Point 'D' Are : (%d, %d)\n\n", point_D_nkk.x, point_D_nkk.y);
	printf("Co-ordinates (x,y) Of Point 'E' Are : (%d, %d)\n\n", point_E_nkk.x, point_E_nkk.y);

	return(0);
}

