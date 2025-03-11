#include <stdio.h>

struct MyPoint
{
	int x;
	int y;
} ;

struct Rectangle
{
	struct MyPoint point_01_nkk;
	struct MyPoint point_02_nkk;

};

struct Rectangle rect_nkk = { {1, 2}, {7, 8} };

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