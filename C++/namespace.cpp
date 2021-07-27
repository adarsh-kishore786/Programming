/*
	namespace.cpp

	Ths program explores the concept of
	unnamed namespace.
*/

#include <iostream>

namespace // All identifiers inside this unnamed namespace have internal linkage, they are private
{
	int x { 5 };

	void doSomething()
	{
		std::cout << "x = " << x << std::endl;
	}
	// Now x is not directly accessible to other files than this

	int getX()
	{
		return x;
	}

	void setX(int xn)
	{
		x = xn;
	}
}
// useful for hiding code from other files

int main()
{
	doSomething();
	std::cout << "x = " << getX() << std::endl;
	std::cout << "x = " << x << std::endl;
}