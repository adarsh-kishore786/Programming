/*
	reference_operator.cpp

	Demonstrates the reference (&) operator.
*/

#include <iostream>

int main()
{
	int value {5};
	int& ref {value};

	int x {5};
	int& y {x};
	int& z {y};

	// References act as alisases for the object being referenced
	value = 0;
	std::cout << "value = ref = " << value << " = " << ref << "\n";

	ref = 7;
	std::cout << "value = ref = " << value << " = " << ref << "\n";

	std::cout << "&value = &ref = " << &value << " = " << &ref << "\n";
}