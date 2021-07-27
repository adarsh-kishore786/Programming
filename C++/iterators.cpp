/*
	iterators.cpp

	This program demonstrates the use
	of iterators.
*/

#include <array>
#include <iostream>
#include <iterator>

int main()
{
	std::array<int, 7> data {0, 1, 2, 3, 4, 5, 6};

	// The simplest iterator is a pointer
	auto begin { &data[0] };
	auto end { begin + data.size() };

	// for-loop with pointer
	for (auto p = begin; p < end; p++)
		std::cout << *p << " ";
	std::cout << "\n";

	// C++ provides inbuit functions for the same thing
	auto begin1 { data.begin() };
	auto end1 { data.end() };

	for (auto p = begin1; p < end1; p++)
		std::cout << *p << " ";
	std::cout << "\n";

	// The iterator header contains some standard functions for this
	auto b { std::begin(data) };
	auto e { std::end(data) };

	for (auto p = b; p < e; p++)
		std::cout << *p << " ";
	std::cout << "\n";
}