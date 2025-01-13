#include <stdio.h>
#include <conio.h>

struct MyPoint
{
	int x;
	int y;
};

int main(void)
{
	// Variable Declarations
	struct MyPoint point_A_nkk, point_B_nkk, point_C_nkk, point_D_nkk, point_E_nkk; // Declaring 5 struct variable 

	// Code
	// User Input For Values Of Data Members Of 'struct MyPoint' variabke 'point_A_nkk'
	printf("\n\n");
	printf("Enter X-Coordinates For Point 'A' : ");
	scanf("%d", &point_A_nkk.x);
	printf("Enter Y-Coordinates For Point 'A' : ");
	scanf("%d", &point_A_nkk.y);

	// User Input For Values Of Data Members Of 'struct MyPoint' variabke 'point_B_nkk'
	printf("\n\n");
	printf("Enter X-Coordinates For Point 'B' : ");
	scanf("%d", &point_B_nkk.x);
	printf("Enter Y-Coordinates For Point 'B' : ");
	scanf("%d", &point_B_nkk.y);

	// User Input For Values Of Data Members Of 'struct MyPoint' variabke 'point_C_nkk'
	printf("\n\n");
	printf("Enter X-Coordinates For Point 'C' : ");
	scanf("%d", &point_C_nkk.x);
	printf("Enter Y-Coordinates For Point 'C' : ");
	scanf("%d", &point_C_nkk.y);

	// User Input For Values Of Data Members Of 'struct MyPoint' variabke 'point_D_nkk'
	printf("\n\n");
	printf("Enter X-Coordinates For Point 'D' : ");
	scanf("%d", &point_D_nkk.x);
	printf("Enter Y-Coordinates For Point 'D' : ");
	scanf("%d", &point_D_nkk.y);

	// User Input For Values Of Data Members Of 'struct MyPoint' variabke 'point_E_nkk'
	printf("\n\n");
	printf("Enter X-Coordinates For Point 'E' : ");
	scanf("%d", &point_E_nkk.x);
	printf("Enter Y-Coordinates For Point 'E' : ");
	scanf("%d", &point_E_nkk.y);

	// Display Value Of Data Members Of 'struct MyData' (all variables)
	printf("\n\n");
	printf("Co-ordinates (x, y) Of Point 'A' Are = (%d, %d)\n\n", point_A_nkk.x, point_A_nkk.y);
	printf("Co-ordinates (x, y) Of Point 'B' Are = (%d, %d)\n\n", point_B_nkk.x, point_B_nkk.y);
	printf("Co-ordinates (x, y) Of Point 'C' Are = (%d, %d)\n\n", point_C_nkk.x, point_C_nkk.y);
	printf("Co-ordinates (x, y) Of Point 'D' Are = (%d, %d)\n\n", point_D_nkk.x, point_D_nkk.y);
	printf("Co-ordinates (x, y) Of Point 'E' Are = (%d, %d)\n\n", point_E_nkk.x, point_E_nkk.y);

	return(0);
}
