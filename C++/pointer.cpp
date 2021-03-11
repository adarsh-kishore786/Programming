/*
	pointer.cpp

	This program demonstrates the 
	concept of pointers.
*/

#include <iostream>

int main()
{
	int x { 5 };

	std::cout << "x = " << x << std::endl;
	std::cout << "Address of x = " << &x << std::endl;
	std::cout << "Value at address " << &x << " = " << *(&x) << std::endl;
}