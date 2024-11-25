#include<stdio.h>
int main(void)
{
	// Variable Declarations
	int num_nkk;

	// Code 
	printf("\n\n");

	printf("Enter Value for 'num_nkk' : ");
	scanf("%d", &num_nkk);

	if (num_nkk < 0) // 'if' - 01
	{
		printf("Num = %d Is Less Than 0 (NEGATIVE) !!! \n\n", num_nkk);
	}
	else // 'else' - 01
	{
		if ((num_nkk > 0) && (num_nkk <= 100)) // 'if' - 02
		{
			printf("Num = %d Is Between 0 And 100 !!! \n\n", num_nkk);
		}
		else // 'else' - 02
		{
			if ((num_nkk > 100) && (num_nkk <= 200)) // 'if' - 03
			{
				printf("Num = %d Is Between 100 and 200 !!!\n\n", num_nkk);
			}
			else // 'else' -03
			{
				if ((num_nkk > 200) && (num_nkk <= 300)) // 'if' - 04
				{
					printf("Num = %d Is Between 200 and 300 !!!\n\n", num_nkk);
				}
				else // 'else' -04
				{
					if ((num_nkk > 300) && (num_nkk <= 400)) // 'if' - 05
					{
						printf("Num = %d Is Between 300 and 400 !!!\n\n", num_nkk);
					}
					else // 'else' - 05
					{
						if((num_nkk > 400) && (num_nkk <= 500)) // 'if' - 06
						{
							printf("Num = %d Is Between 400 And 500 !!!\n\n", num_nkk);
						}
						else // 'else' - 06
						{
							printf("Num = %d Is Greater Than 500 !!!\n\n", num_nkk);
						} // closing brace of 'else' - 06 

					} // closing brace of 'else' - 05

				} // closing brace of 'else' - 04

			} // closing brace of 'else' - 03

		} // closing brace of 'else' - 02

	} // closing brace of 'else' - 01

	return(0);
}
