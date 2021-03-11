/*
	readymade_functions.cpp

	This program demonstrates some readymade
	functions defined in <functional> header.
*/

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

std::vector<int> input()
{
	int n;
	std::cout << "Enter number of elements: ";
	std::cin >> n;

	std::vector<int> v(n);

	for (auto& e : v)
	{
		std::cout << "Enter a number: ";
		std::cin >> e;
	}
	return v;
}

void printVector(const std::vector<int>& v)
{
	for (const auto& e : v)
		std::cout << e << " ";
	std::cout << "\n";
}

int main()
{
	std::vector<int> v { input() };

	std::cout << "Before sorting:\n";
	printVector(v);

	std::cout << "Sorting in ascending order:\n";
	std::sort(v.begin(), v.end(), std::less<int>{});
	printVector(v);

	std::cout << "Sorting in descending order:\n";
	std::sort(v.begin(), v.end(), std::greater<int>{});
	printVector(v); 

	auto customSort {
		[] (int x, int y) 
		{
			return x + y < x * y;
		}
	};

	std::cout << "Custom sort:\n";
	std::sort(v.begin(), v.end(), customSort);
	printVector(v);
}