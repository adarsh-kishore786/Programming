/*
	default_args.cpp

	C++ supports default args. Their declaration
	is simialr to Python.
*/

#include <iostream>

int factorial(int n=3)
{
	int p {1};
	for (int i = 2; i <= n; i++)
		p *= i;
	return p;
}

int main()
{
	std::cout << factorial(5) << "\n";
	std::cout << factorial() << "\n";
}