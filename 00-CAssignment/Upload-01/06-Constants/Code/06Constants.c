#include<stdio.h>

#define MY_PI 3.1415926535897932 
#define AMC_STRING "Astromedicomp RTR"

// If First Constant Is Not Assigned a Value, It Is Assumed To Be 0 i.e.: 'SUNDAY' Will be 0
// And The Rest Of The Constants Are Assigned Consecutive Integer Values From 0 onwards i.e. 'MONDAY' Will be 1, 'TUESDAY' Will Be 2, and so on...

//Un-named enums
enum
{
	SUNDAY = 1,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};

enum
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

//Named Enums
enum Numbers
{
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN
};

enum boolean
{
	TRUE = 1,
	FALSE = 0
};

int main(void)
{
	//local constant declarations
	const double epsilon = 0.000001;
	
	//code
	printf("\n\n");
	printf("Local Constant Epsilon=%lf\n\n", epsilon);
	
	printf("Sunday is Day Number = %d\n", SUNDAY);
	printf("Monday is Day Number = %d\n", MONDAY);
	printf("Tuesday is Day Number = %d\n", TUESDAY);
	printf("Wednesday is Day Number = %d\n", WEDNESDAY);
	printf("THURSDAY is Day Number = %d\n", THURSDAY);
	printf("FRIDAY is Day Number = %d\n", FRIDAY);
	printf("SATURDAY is Day Number = %d\n", SATURDAY);
	
	printf("One Is ENUM Number = %d\n", ONE);
	printf("Two Is ENUM Number = %d\n", TWO);
	printf("Three Is ENUM Number = %d\n", THREE);
	printf("Four Is ENUM Number = %d\n", FOUR);
	printf("Five Is ENUM Number = %d\n", FIVE);
	printf("Six Is ENUM Number = %d\n", SIX);
	printf("Seven Is ENUM Number = %d\n", SEVEN);
	printf("Eight Is ENUM Number = %d\n", EIGHT);
	printf("Nine Is ENUM Number = %d\n", NINE);
	printf("TEN Is ENUM Number = %d\n", TEN);
	
	printf("January Is Month Number = %d\n", JANUARY);
	printf("February Is Month Number = %d\n", FEBRUARY);
	printf("March Is Month Number = %d\n", MARCH);
	printf("April Is Month Number = %d\n", APRIL);
	printf("May Is Month Number = %d\n", MAY);
	printf("June Is Month Number = %d\n", JUNE);
	printf("July Is Month Number = %d\n", JULY);
	printf("August Is Month Number = %d\n", AUGUST);
	printf("September Is Month Number = %d\n", SEPTEMBER);
	printf("October Is Month Number = %d\n", OCTOBER);
	printf("November Is Month Number = %d\n", NOVEMBER);
	printf("December Is Month Number = %d\n", DECEMBER);
	
	printf("Value of TRUE IS = %d\n", TRUE);
	printf("Value of FALSE IS = %d\n\n", FALSE);
	
	printf("MY_PI Macro value = %.10lf\n\n", MY_PI);
	printf("Area Of Circle Of Radius 2 units = %f\n\n", (MY_PI * 2.0f, 2.0f)); // pi * r * r = area of circle if radius 'r'
	
	printf("\n\n");
	
	printf(AMC_STRING);
	printf("\n\n");
	
	printf("AMC_STRING is: %s\n", AMC_STRING);
	printf("\n\n");
	
	return(0);
}
