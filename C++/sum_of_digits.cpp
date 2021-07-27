/*
	sum_of_digits.cpp

	This program reads a number from
	user and prints the sum of its 
	digits.
*/

#include <iostream>

int sum(int n)
{
	if (n >= 0 && n <= 9)
		return n;
	return (n % 10) + sum(n / 10);
}

int main()
{
	int n {};
	std::cout << "Enter a number: ";
	std::cin >> n;

	std::cout << "The sum of its digits is: " << sum(n);
}