/*
	edit_conversion_code.c

	This program demonstrates the edit 
	conversion code in C.
*/

#include <stdio.h>

int main()
{
	char str[50];

	printf("Enter a string: ");
	scanf("%[^\n]s", str);
	fflush(stdin);

	printf("%s\n", str);

	printf("Enter another string: ");
	scanf("%[^0-9]s", str);
	fflush(stdin);

	printf("%s\n", str);

	printf("Enter another string: ");
	scanf("%[^a-z]s", str);
	fflush(stdin);

	printf("%s\n", str);

	printf("Enter another string: ");
	scanf("%[0-9 A-Z]s", str);
	fflush(stdin);

	printf("%s\n", str);
}