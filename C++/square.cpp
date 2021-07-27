/*
	square.cpp

	Defines the functions.
*/

#include "square.h"

int getSquareSides()
{
	return 4;
}

int getSquarePerimeter(int sideLength)
{
	return sideLength * getSquareSides();
}