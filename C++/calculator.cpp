/*
	calculator.cpp

	This program demonstrates a basic calculator.
*/

#include <iostream>

double getNumber()
{
	std::cout << "Enter a double value: ";
	double a {};
	std::cin >> a;

	return a;
}

double calculate(double a, double b, char op)
{
	switch (op)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

int main()
{
	double a { getNumber() };
	double b { getNumber() };

	std::cout << "Enter one of the following: +, -, *, or /: ";
	char op {};
	std::cin >> op;

	std::cout << a << " " << op << " " << b << 	" is " << calculate(a, b, op);
}