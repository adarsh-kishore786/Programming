/*
	physics_constants.cpp

	Demonstrates the various constants defined 
	in constants.h header file.
*/

#include "constants.h"
#include <iostream>

int main()
{
	std::cout << "pi = " << constants::pi << std::endl;
	std::cout << "e  = " << constants::e << std::endl;
	std::cout << "g  = " << constants::g << std::endl;
}