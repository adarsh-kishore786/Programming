/*
	sort_pointer.cpp

	This program demonstrates sorting of an
	array using a function pointer.
*/

#include <iostream>
#include <utility> // for std::swap
#include <vector>
#include <functional>

using vector = std::vector<int>;
using Comparision = bool (*)(int, int);

bool ascending(int x, int y)
{
	return x > y;
}

bool descending(int x, int y)
{
	return x < y;
}

bool customSort(int x, int y)
{
	if (x % 2 == 0 && y % 2 == 1)
		return false;
	if (x % 2 == 1 && y % 2 == 0)
		return true;

	if (x % 2 == 0)
		return ascending(x, y);
	return descending(x, y);
}

void printVector(const vector& arr)
{
	for (const auto& e : arr)
		std::cout << e << " ";
	std::cout << "\n";
}

void SelectionSort(vector& arr, Comparision sortFunction = ascending) // default parameters
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int pos = i;
		for (int j = i + 1; j < arr.size(); j++)
			if (sortFunction(arr[pos], arr[j]))
				pos = j;
		std::swap(arr[pos], arr[i]);
	}
}

int main()
{
	int n {};
	std::cout << "Enter length of array: ";
	std::cin >> n;

	vector arr(n);

	for (auto& e : arr)
	{
		std::cout << "Enter a number: ";
		std::cin >> e;
	}

	std::cout << "Before sorting: ";
	printVector(arr);

	SelectionSort(arr, ascending);
	std::cout << "\nAfter sorting in ascending order: ";
	printVector(arr);

	SelectionSort(arr, descending);
	std::cout << "\nAfter sorting in descending order: ";
	printVector(arr);

	SelectionSort(arr, customSort);
	std::cout << "\nA custom sort: ";
	printVector(arr);

	SelectionSort(arr);
	std::cout << "\nBy default, ascending sort: ";
	printVector(arr);
}