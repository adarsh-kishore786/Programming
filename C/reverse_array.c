/*
	reverse_array.c

	This program accepts an array entered
	by user and prints it in reverse.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void reverse_array(int *ar, int l)
{
	int first, last;
	for (first = 0, last = l - 1; first < last; first++, last--)
		swap(ar + first, ar + last);
}

void print_array(int *ar, int l)
{
	for (int i = 0; i < l; i++)
		printf("%d ", ar[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("No array entered. Try again.\n");
		return 1;
	}

	int n = argc - 1;
	int ar[n];

	for (int i = 0; i < n; i++)
		ar[i] = atoi(argv[i + 1]);

	printf("Original array: ");
	print_array(ar, n);

	reverse_array(ar, n);
	printf("Reversed array: ");
	print_array(ar, n);
}