/*
	equality.c

	This program builds the == operator
	using only bitwise and logical 
	operators.
*/

#include <stdio.h>

int is_equal(int x, int y)
{
	int z = x ^ y;
	if (!z)
		return 1;
	return 0;
}

int main()
{
	printf("Enter two numbers: ");
	int x, y;
	fscanf(stdin, "%d %d", &x, &y);

	if (is_equal(x, y))
		printf("x and y are equal.\n");
	else
		printf("x and y are not equal.\n");

	return 0;
}