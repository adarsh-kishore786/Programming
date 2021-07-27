/*
	find_for_each.cpp

	This demonstrates a linear search algo
	using for-each loop.
*/

#include <iostream>

int main()
{
	const std::string names[] {"Alex", "Betty", "Caroline", "Dave", "Emily",
								"Fred", "Greg", "Holly"};

	std::cout << "Enter a name: ";
	std::string name {};
	std::cin >> name;
	bool found = false;

	for (const auto& n : names)
		if (name == n)
		{
			std::cout << name << " was found.\n";
			found = true;
			break;
		}

	if (!found)
		std::cout << name << " was not found.\n";
}