/*
	cstyle_string.cpp

	This program is used to print a C 
	style string character by character using
	pointers.
*/

#include <iostream>

int main()
{
	char str[] = "Hello, World!";

	for (char* p = str; *p != '\0'; p++)
		std::cout << *p;
}