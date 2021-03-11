/* unformatted_output.c

   This program demonstrates the
   unformattes input and output 
   functions getchar(), gets()
   and putchar(), puts().

   Author: Adarsh
*/

#include <stdio.h>

int main()
{
	char ch;

	printf("Type any alphabet:\n");
	ch = getchar();
	fflush(stdin);

	printf("You typed: ");
	putchar(ch);
	putchar('.');
	puts("");

	char footballer[40];
	puts("Enter name:");
	gets(footballer);
	fflush(stdin);

	puts("Happy footballing!");
	puts(footballer);
}