/*
	find.cpp

	This program demonstrates the use
	of the std::find function.
*/

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> input()
{
	int n;
	std::cout << "Enter length of array: ";
	std::cin >> n;

	std::vector<int> ar(n);
	for (auto& v : ar)
	{
		std::cout << "Enter a number: ";
		std::cin >> v;
	}

	return ar;
}

int main()
{
	std::vector<int> arr { input() };

	int val {};
	std::cout << "Enter value to find: ";
	std::cin >> val;

	auto found { std::find(arr.begin(), arr.end(), val) };

	if (found == arr.end())
		std::cout << "Entered value is not in array.";
	else
	{
		std::cout << "Entered value exists.";
		std::cout << "\nEnter a value to replace it: ";
		int replace {};
		std::cin >> replace;

		*found = replace;

		std::cout << "Array after replacing:\n";
		for (const auto& v : arr)
			std::cout << v << " ";
	}
}