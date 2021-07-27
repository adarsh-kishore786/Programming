/*
`	squares_pattern.c

	This program prints a pattern using 
	the perfect squares.
*/

#include <stdio.h>

int main()
{
	int n;
	printf("Enter the number of rows: ");
	fscanf(stdin, "%d", &n);

	int length = 1;
	int space_length = n - 1;
	for (int i = 1; i <= n*n; )
	{
		for (int j = 0; j < space_length; j++)
			printf("  ");
		for (int j = 0; j < length; j++)
		{
			printf("%2d  ", i*i);
			i++;
		}
		length += 2;
		space_length--;
		printf("\n");
	}
}