/*
	tuple.cpp

	This program shows std::tuple data structure.
*/

#include <iostream>
#include <tuple>

std::tuple<int, double, char> getTuple()
{
	return {5, 3.14, 'a'};
}

int main()
{
	int a;
	double b;
	char c;

	std::tuple<int, double, char> s = getTuple();
	std::tie(a, b, c) = getTuple();

	std::cout << "Tuple(" << 1 << ") = " << std::get<0>(s) << "\n";
	std::cout << "Tuple(" << 2 << ") = " << std::get<1>(s) << "\n";
	std::cout << "Tuple(" << 3 << ") = " << std::get<2>(s) << "\n\n";

	// Can also print elements like this
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "c = " << c << "\n";	
}