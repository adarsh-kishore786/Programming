/*
	fgets_function.c

	This program demonstrates the fgets 
	function, a better alternative than 
	gets function.
*/

#include <stdio.h>

int main()
{
	char str[10];

	printf("Enter a few words: ");
	fgets(str, sizeof(str), stdin);
	
	printf("%s", str);
}