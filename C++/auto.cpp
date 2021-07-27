/*
	auto.cpp

	Demonstrates the auto keyword.
*/

#include <iostream>

// Avoid leaving return type in ambiguity
// Thus avoid type reference for function return types
auto sum(int x, int y)
{
	return x + y;
}

int main()
{
	auto d = 5.45;
	std::cout << "d = " << d << std::endl;
	std::cout << "1 + 2 = " << sum(1, 2) << std::endl;
}