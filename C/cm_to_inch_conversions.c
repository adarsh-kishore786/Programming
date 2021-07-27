/*
	cm_to_inch_conversions.c

	This program is menu based. It asks user
	to convert cm to inch or inch to cm.
*/

#include <stdio.h>

int main()
{
	int n;
	printf("What would you like to do?\n");
	printf("1. Convert cm to inches\n");
	printf("2. Convert inches to cm\n");

	fscanf(stdin, "%d", &n);
	float cm, inch;
	switch (n)
	{
		case 1: printf("Enter the cms to be converted: ");
				fscanf(stdin, "%f", &cm);
				inch = 2.56 * cm;
				printf("%f cm = %f inches.\n", cm, inch);
				break;
		case 2: printf("Enter the inches to be converted: ");
				fscanf(stdin, "%f", &inch);
				cm = inch / 2.56;
				printf("%f inch = %f cm.\n", inch, cm);
				break;
		default: printf("Invalid choice. Try again.\n");
	}

	return 0;
}