/*
	get_integer_main.cpp

	Main file for get_integer.cpp
*/

#include "get_integer.h"
#include "add.h"

#include <iostream>

int main()
{
	int x{ getInteger() };
	int y{ getInteger() };

	std::cout << x << " + " << y << " = " << add(x, y);
}