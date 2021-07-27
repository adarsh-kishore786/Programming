/*
	handling_errors.cpp

	This program shows some techniques to handle
	errors.
*/

#include <iostream>
#include <cstdlib>

// just ignore the case where error can occur
namespace v1
{
	void printDivision(int x, int y)
	{
		if (y != 0)
			std::cout << x << " / " << y << " = " << 
				static_cast<double>(x) / y << std::endl; 
	}
}

// give error on standard error stream
namespace v2
{
	void printDivision(int x, int y)
	{
		if (y != 0)
			std::cout << x << " / " << y << " = " << 
				static_cast<double>(x) / y << std::endl; 
		else
			std::cerr << "Error: Division by zero.\n";
	}
}

// Terminate program
inline namespace v3
{
	void printDivision(int x, int y)
	{
		if (y != 0)
			std::cout << x << " / " << y << " = " << 
				static_cast<double>(x) / y << std::endl; 
		else
		{
			std::cerr << "Error: Division by zero.\n";
			std::exit(1);
		}
	}
}


int main()
{
	printDivision(2, 4);
	printDivision(2, 0);
}