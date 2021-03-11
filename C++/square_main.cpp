/*
	square_main.cpp

	Program calculates some things related to
	squares.
*/

#include "square.h"
#include <iostream>

int main()
{
	std::cout << "A square has " << getSquareSides() << " sides.\n";
	std::cout << "A square of length 5 has perimeter length " << 
			getSquarePerimeter(5) << ".\n";

	return 0;
}