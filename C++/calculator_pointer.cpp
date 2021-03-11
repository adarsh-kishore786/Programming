/*
	calculator_pointer.cpp

	This program creates a calculator
	using function pointers.
*/

#include <iostream>
#include <functional>
#include <string>

using ArithmeticFunction = std::function<int(int, int)>;

bool search(const std::string& str, char c)
{
	for (const auto& e : str)
		if (e == c)
			return true;
	return false;
}

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

ArithmeticFunction getArithmeticFunction(char op)
{
	switch (op)
	{
		default: // default will be addition
		case '+': return add;
		case '-': return subtract;
		case '*': return multiply;
		case '/': return divide;
	}
}

int getInteger()
{
	std::cout << "Enter an integer: ";
	int a {};
	std::cin >> a;

	return a;
}

char getOperator()
{
	char op {};
	while (!search("+-*/", op))
	{
		std::cout << "Enter an operator: ";
		std::cin >> op;

		if (!search("+-*/", op))
			std::cout << "Invalid operator entered. Try again.\n";
	}
	return op;
}

int main()
{
	int a { getInteger() };
	char op { getOperator() };
	int b { getInteger() };

	std::cout << a << " " << op << " " << b << " = " << getArithmeticFunction(op)(a, b);
}