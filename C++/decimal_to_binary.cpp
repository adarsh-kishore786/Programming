/*
	decimal_to_binary.cpp

	This program reads a number from
	user and converts it to binary.
*/

#include <iostream>

void toBinary(unsigned int n)
{
	if (n > 1)
		toBinary(n / 2);
	std::cout << n % 2; 
}

int main()
{
	int n {};
	std::cout << "Enter a number: ";
	std::cin >> n;

	std::cout << "Number in binary: ";
	toBinary(n);
}