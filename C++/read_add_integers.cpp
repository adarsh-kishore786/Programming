/*
	read_add_integers.cpp

	This program reads two integers from
	the user and outputs their sum.
*/

#include <iostream>

int readNumber()
{
	int num;
	std::cout << "Enter an integer: ";
	std::cin >> num;

	return num;
}

void writeAnswer(int a, int b)
{
	int sum{ a + b };
	std::cout << a << " + " << b << " = " << sum << std::endl;
}

int main()
{
	int a{ readNumber() };
	int b{ readNumber() };
	writeAnswer(a, b);
}