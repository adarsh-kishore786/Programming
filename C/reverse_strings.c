/* reverse_strings.c

   This program accepts an array
   of string from the user and
   reverses the strings in the 
   array.

   Author: Adarsh
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_list(char **names, int length)
{
	for (int i = 0; i < length; i++)
		printf("%d. %s\n", i + 1, *(names + i));
}

void reverse_strings(char **names, int length)
{
	for (int i = 0; i < length; i++)
	{
		strrev(*(names + i));
	}
}

int main()
{
	char **names;
	int length;

	printf("Enter number of strings to be entered:\n");
	scanf("%d", &length);
	fflush(stdin);

	names = malloc(length * sizeof(char*));

	for (int i = 0; i < length; i++)
	{
		char t[128];
		printf("Enter a string: ");
		gets(t);
		fflush(stdin);

		*(names + i) = malloc((strlen(t) + 1) * sizeof(char));
		strcpy(*(names + i), t);
	}

	printf("\nThe original list entered:\n");
	print_list(names, length);

	reverse_strings(names, length);

	printf("\nThe list after reversing individual elements:\n");
	print_list(names, length);
}