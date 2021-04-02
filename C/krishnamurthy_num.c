/*
	krishnamurthy_num.c

	This program inputs numbers from command
	line arguments and finds if they are 
	Krishnamurthy numbers.
*/

#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * fact(n - 1);
}

int is_krishnamurthy(int n)
{
	int temp = n;
	int sum = 0;
	while (temp != 0)
	{
		int d = temp % 10;
		sum += fact(d);
		temp /= 10;
	}
	return sum == n;
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
		int n = atoi(argv[i]);
		if (is_krishnamurthy(n))
			printf("%d is a Krishnamurthy number.\n", n);
		else
			printf("%d is not a Krishnamurthy number.\n", n);
	}
	return 0;
}