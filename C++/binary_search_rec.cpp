/*
	binary_search_rec.cpp

	This program does a binary search
	using a recursive function.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using vector = std::vector<int>;

int input()
{
	int n{};
	std::cout << "Enter number of elements in array: ";
	std::cin >> n;

	vector arr(n);
	for (auto& e : arr)
	{
		std::cout << "Enter an element: ";
		std::cin >> e;
	}

	return arr;
}

void printVector(const vector& v)
{
	for (const auto& e : v)
		std::cout << e << " ";
	std::cout << "\n";
}

bool binarySearch(const vector& v, int val, int min, int max)
{
	if (min > max)
		return false;
	int m { (min + max) / 2 };

	if (v[m] == val)
		return true;
	if (v[m] < val)
		return binarySearch(v, val, min, m - 1);
	return binarySearch(v, val, m + 1, max);
}

int main()
{
	vector v { input() };

	std::cout << "Array: ";
	printVector(v);

	std::sort(v.begin(), v.end());
	std::cout << "Sorted: ";
	printVector(v);

	std::cout << "Enter value to be searched: ";
	int val {};
	std::cin >> val;

	if (binarySearch(v, val, 0, v.size()))
		std::cout << val << " exists in the array.";
	else
		std::cout << val << " does not exist in the array.";
}