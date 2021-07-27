/*
	get_integer.cpp

	Code for taking an integer input.
*/

#include <iostream>

int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{}; // default initialization
	std::cin >> x;
	return x;
}

int add(int x, int y)
{
	return x + y;
}
