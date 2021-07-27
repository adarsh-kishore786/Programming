/* string_examples.c

   This program demonstrates the creation
   and use of strings in C.

   Author: Adarsh
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	// single character array
	char letter = 'A';

	// string literal using pointers
	char *name1 = "Engineer Man"; // this is now stored in ROM; hard-coded, can't be changed

	// string literal without pointers
	char name2[] = "Engineer Man"; // editable

	// another way
	char name3[] = {'E', 'n', 'g', 'i', 'n', 'e', 'e', 'r', ' ', 'M', 'a', 'n', '\0'};

	// pointer to a char
	char name4[128];

	strcpy(name4, "Engineer Man"); // Another way
	printf("%s\n", name4);
	printf("%d\n", strlen(name4));
}