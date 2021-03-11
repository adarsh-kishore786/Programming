#include <stdio.h>

int add(int, int); // Function prototype

int main()
{
	int a = 5;
	int b = 6;

	int sum = add(a, b);

	printf("Sum: %d", sum);

	return 0;
}

// User defined function
int add(int x, int y)
{
	return x + y;
}