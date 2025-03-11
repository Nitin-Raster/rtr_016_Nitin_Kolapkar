#include <stdio.h>

// DEFINING STRUCT
struct MyPoint
{
	int x;
	int y;
} point_A_nkk, point_B_nkk, point_C_nkk, point_D_nkk, point_E_nkk; // Declaring 5 struct variable of type 'struct MyPoint' globally ...

int main(void)
{
	// Code
	// Assigning Data Values To The Data Members Of 'Struct MyPoint' variable 'point_A'
	point_A_nkk.x = 3;
	point_A_nkk.y = 0;

	// Assigning Data Values To The Data Members Of 'Struct MyPoint' variable 'point_B'
	point_B_nkk.x = 1;
	point_B_nkk.y = 2;

	// Assigning Data Values To The Data Members Of 'Struct MyPoint' variable 'point_C'
	point_C_nkk.x = 9;
	point_C_nkk.y = 7;

	// Assigning Data Values To The Data Members Of 'Struct MyPoint' variable 'point_D'
	point_D_nkk.x = 45;
	point_D_nkk.y = 13;

	// Assigning Data Values To The Data Members Of 'Struct MyPoint' variable 'point_E'
	point_E_nkk.x = 4;
	point_E_nkk.y = 3;

	// Displaying Values Of The Data Members Of 'struct MyPoint' (all variables)
	printf("\n\n");
	printf("Co-Ordinates (x,y) Of Point 'A' Are : (%d, %d)\n\n", point_A_nkk.x, point_A_nkk.y);
	printf("Co-Ordinates (x,y) Of Point 'B' Are : (%d, %d)\n\n", point_B_nkk.x, point_B_nkk.y);
	printf("Co-Ordinates (x,y) Of Point 'C' Are : (%d, %d)\n\n", point_C_nkk.x, point_C_nkk.y);
	printf("Co-Ordinates (x,y) Of Point 'D' Are : (%d, %d)\n\n", point_D_nkk.x, point_D_nkk.y);
	printf("Co-Ordinates (x,y) Of Point 'E' Are : (%d, %d)\n\n", point_E_nkk.x, point_E_nkk.y);

	return(0);
}
