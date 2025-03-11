#include <stdio.h>

struct Rectangle
{
	struct MyPoint
	{
		int x;
		int y;
	} point_01_nkk, point_02_nkk;
} rect_nkk = { {2, 3}, {5, 6} };

int main(void)
{
	// Variable Declarations
	int length, breadth, area;

	// Code
	length = rect_nkk.point_02_nkk.y - rect_nkk.point_01_nkk.y;
	if (length < 0)
		length = length * -1;

	breadth = rect_nkk.point_02_nkk.x - rect_nkk.point_01_nkk.x;
	if (breadth < 0)
		breadth = breadth * -1;

	area = length * breadth;

	printf("\n\n");
	printf("Length Of Rectangle = %d\n\n", length);
	printf("Breadth Of Rectangle = %d\n\n", breadth);
	printf("Area Of Rectangle = %d\n\n", area);

	return(0);
}