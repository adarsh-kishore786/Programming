/*
    average.c

    Given a sequence of n (>= 10) integers, not all
    same, form their sequence S and then form
    subsequences S(k) (k < n / 2) formed by removing the
	first and last k elements of S. Print the pair of 
	subsequences whose absolute value of difference of sums is 
	less than 1.2
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_seq(int *s, int length)
{
	printf("<");
	for (int i = 0; i < length; i++)
		printf("%d ", s[i]);
	printf(">");
}

void sum_subseq(int *s, int length, int **sum, int index)
{
	for (int i = index + 1; i < length - (index + 1); i++)
		*(*sum + index) += s[i];
}

void print_min(int *sum, int length, int n)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			float avg1 = (float) sum[i] / (n - 2 * (i + 1));
			float avg2 = (float) sum[j] / (n - 2 * (j + 1));
			if (fabs(avg1 - avg2) < 1.2)
				printf("(S%d, S%d)\n", (i + 1), (j + 1));				
		}
	}
}


int main()
{
	char line[1000]; // any big enough value
	int n, *s;
	printf("Enter length of sequence: ");
	sscanf(gets(line), "%d", &n);

	s = (int*) malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		printf("Enter a value: ");
		sscanf(gets(line), "%d", &s[i]);
	}

	print_seq(s, n);

	int k = n / 2;
	if (n % 2 == 0) k--; // Eg- when n = 10, k = 5 - 1 = 4
	int *sum = (int*) malloc(k * sizeof(int));
	for (int i = 0; i < k; i++)
		sum[i] = 0;

	for (int index = 0; index < k; index++)
		sum_subseq(s, n, &sum, index);

	printf("\nSums:\n");
	for (int i = 0; i < k; i++) 
		printf("S%d: %d\n", (i + 1), sum[i]);

	print_min(sum, k, n);

	return 0;
}