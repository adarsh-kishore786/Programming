/*
	signed_unsigned.c

	This program compares the effect of 
	signed and unsigned casting.
*/

#include <stdio.h>
#include <stdlib.h>

int fun1(unsigned word) 
{
	return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) 
{
	return ((int) word << 24) >> 24;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("No numbers entered. Try again.\n");
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		unsigned int n = (int) strtol(argv[i], NULL, 16);
		printf("n = %#X, fun1(n) = %#X, fun2(n) = %#X\n"
			, n, fun1(n), fun2(n));
	}

	return 0;
}