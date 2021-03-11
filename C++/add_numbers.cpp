/*
	add_numbers.cpp

	Inputs numbers using the function readNumber()
	defined in io_numbers.cpp and outputs their sum
	using the writeAnswer() function in io_numbers.cpp
	Uses forward declarations in header file io_numbers.h
*/

#include "io_numbers.h"
#include <iostream>

int main()
{
	int a{ readNumber() };
	int b{ readNumber() };
	writeAnswer(a, b);
}