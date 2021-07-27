/*
	fraction.cpp

	This program multiplies two fractions
	using concept of structs.
*/

#include <iostream>

struct Fraction
{
	int numerator {};
	int denominator { 1 }; // Denominator mustn't be 0
};

Fraction getFrac()
{
	std::cout << "Enter the numerator: ";
	int numerator {};
	std::cin >> numerator;

	int denominator {};

	input: std::cout << "Enter the denominator: ";

	std::cin >> denominator;
	if (denominator == 0)
	{
		std::cout << "Denominator can't be zero. Try again\n";
		goto input;
	}

	return {numerator, denominator};
}

double multiply(Fraction a, Fraction b)
{
	double result { ((double)a.numerator * b.numerator) / ((double)a.denominator * b.denominator) };
	return result;
}

int main()
{
	Fraction a { getFrac() };
	Fraction b { getFrac() };
	std::cout << multiply(a, b) << std::endl;
}