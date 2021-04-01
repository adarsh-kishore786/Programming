/*
	sort_names_pointers.c

	This program accepts an array of names
	from user and sorts them in lexographical
	order using pointers.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void swap(char **str1, char **str2)
{
	char *temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int less(char *str1, char *str2)
{
	for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		char c1 = toupper(str1[i]);
		char c2 = toupper(str2[i]);

		if (c1 < c2)
			return 1;
		else if (c1 > c2)
			return 0;
	}
	return 0;
}

void sort(char ***str_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		int pos = i;
		for (int j = i + 1; j < n; j++)
			if (!less((*str_array)[pos], (*str_array)[j]))
				pos = j;
		if (pos != i)
			swap(*str_array + i, *str_array + pos);
	}
}

void print_str(char **str_array, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d. %s\n", i+1, str_array[i]);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("No names entered. Try again.\n");
		return 1;
	}

	int n = argc - 1;
	char **str_array = malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		str_array[i] = (char*) malloc(sizeof(char) * strlen(argv[i + 1]));
		strcpy(str_array[i], argv[i + 1]);
	}
	printf("Original array:\n");
	print_str(str_array, n);

	sort(&str_array, n);
	printf("\n");

	printf("Sorted array:\n");
	print_str(str_array, n);

	return 0;
}