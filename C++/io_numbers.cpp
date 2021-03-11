/*
	io_numbers.cpp

	Contains functions for taking
	input and displaying output.
*/

#include <iostream>

int readNumber()
{
	int num{};
	std::cout << "Enter a number: ";
	std::cin >> num;

	return num;
}

void writeAnswer(int a, int b)
{
	int sum{ a + b };
	std::cout << a << " + " << b << " = " << sum << std::endl;
}