/*
	string_input.c

	This program inputs a string
	using characters.
*/

#include <stdio.h>

int main()
{
	char str[50];
	char c;
	int i = 0;

	printf("Enter a string: ");
	while ((c = getchar()) != '\n')
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';

	printf("%s", str);
}