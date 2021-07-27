/*
	bis_bic.c

	This program demonstrates the operations
	of bis and bic.
*/

#include <stdio.h>

int bis(int x, int m)
{
	return x | m;
}

int bic(int x, int m)
{
	return x & m;
}

int bool_or(int x, int y)
{
	return bis(x, y);
}

int bool_xor(int x, int y)
{
	int w = bic(x, ~y);
	int z = bic(~x, y);
	return bis(w, z);
}

int main()
{
	printf("Enter two numbers: ");
	int x, y;
	fscanf(stdin, "%d %d", &x, &y);

	printf("x = 0x%X, y = 0x%X\n", x, y);
	printf("x | y = 0x%X\n", bool_or(x, y));
	printf("x ^ y = 0x%X\n", bool_xor(x, y));

	return 0;
}