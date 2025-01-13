#include <stdio.h>

int main(void)
{
	// DEFINING STRUCT
	struct MyPoint
	{
		int x;
		int y;
	} point_nkk; // Declaring a single struct variable of type 'struct MyPoint' locally ...

	// DEFINING STRUCT
	struct MyPointProperties
	{
		int quadrant;
		char axis_location[10];
	}point_properties_nkk; //declaring a single variable of tyoe 'struct MyPointProperties' locally

	// Code
	// User Input For The Data Members Of 'struct MyPoint' variable 'point_nkk'
	printf("\n\n");
	printf("Enter X-Coordinates For A Point : \n");
	scanf("%d", &point_nkk.x);
	printf("Enter Y-Coordinates For A Point : \n");
	scanf("%d", &point_nkk.y);

	printf("\n\n");
	printf("Point Co-Ordinates (x, y) Are : (%d, %d) !!!\n\n", point_nkk.x, point_nkk.y);

	if (point_nkk.x == 0 && point_nkk.y == 0)
		printf("The Point Is The Origin (%d, %d) !!! \n", point_nkk.x, point_nkk.y);
	else // Atleast One Of The Two Values ( Either 'X' or 'Y' or BOTH) is a non-zero value...
	{
		if (point_nkk.x == 0) // If 'X'IS ZERO... OBVIOUSLY 'Y' IS THE NON-ZERO VALUE 
		{
			if (point_nkk.y < 0) // If 'Y' IS -ve
				strcpy(point_properties_nkk.axis_location, "Negative Y");

			if (point_nkk.y > 0) // If 'Y' IS +ve
				strcpy(point_properties_nkk.axis_location, "Positive Y");

			point_properties_nkk.quadrant = 0; //A Point Lying On Any Of The Co-ordinate Axes Is NOT A Part Of ANY Quadrant...
			printf("The Point Lies On The %s Axis !!!\n\n", point_properties_nkk.axis_location);

		}
		else if (point_nkk.y == 0) // If 'Y' IS ZERO...OBVIOUSLY 'X' IS THE NON-ZERO VALUE
		{
			if (point_nkk.x < 0) // If 'X' IS -ve
				strcpy(point_properties_nkk.axis_location, "Negative X");

			if (point_nkk.x > 0) // If 'X' IS +ve
				strcpy(point_properties_nkk.axis_location, "Positive X");

			point_properties_nkk.quadrant = 0; // A Point Lying On Any Of The Co-ordinates Axes Is NOT A Part Of ANY Quadrant...
			printf("The Point Lies On The %s Axis !!!\n\n", point_properties_nkk.axis_location);
		}
		else // BOTH 'X' AND 'Y' ARE NON-ZERO
		{
			point_properties_nkk.axis_location[0] = '\0'; // A Point Lying IN ANY OF The 4 Quadrant Cannot Be Lying On Any Of The Co-ordinate Axes...

			if (point_nkk.x > 0 && point_nkk.y > 0)	// 'X' IS +ve AND 'Y' IS +ve
				point_properties_nkk.quadrant = 1;

			else if (point_nkk.x < 0 && point_nkk.y > 0)	// 'X' IS -ve AND 'Y' IS +ve
				point_properties_nkk.quadrant = 2;

			else if (point_nkk.x < 0 && point_nkk.y < 0) // 'X' IS -ve AND 'Y' IS -ve
				point_properties_nkk.quadrant = 3;

			else										// 'X' IS +ve AND 'Y' IS -ve
				point_properties_nkk.quadrant = 4;

			printf("The Point Lies In Quadrant Number %d !!!\n\n", point_properties_nkk.quadrant);
		}
	}

	return(0);
}
