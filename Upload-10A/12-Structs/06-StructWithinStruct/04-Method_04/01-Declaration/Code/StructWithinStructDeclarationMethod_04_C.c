#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int length, breadth, area;

	struct MyPoint
	{
		int x;
		int y;
	};

	struct Rectangle
	{
		struct MyPoint point_01_nkk;
		struct MyPoint point_02_nkk;
	};

	struct Rectangle rect_nkk;

	// Code
	printf("\n\n");
	printf("Enter Leftmost X-Coordinates Of Rectancgle :");
	scanf("%d", &rect_nkk.point_01_nkk.x);

	printf("\n\n");
	printf("Enter Bottommost Y-Coordinates Of Rectancgle :");
	scanf("%d", &rect_nkk.point_01_nkk.y);

	printf("\n\n");
	printf("Enter Righmost X-Coordinates Of Rectancgle :");
	scanf("%d", &rect_nkk.point_02_nkk.x);

	printf("\n\n");
	printf("Enter Topmost Y-Coordinates Of Rectancgle :");
	scanf("%d", &rect_nkk.point_02_nkk.y);

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
