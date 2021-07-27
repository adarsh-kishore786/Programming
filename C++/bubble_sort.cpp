/*
	bubble_sort.cpp

	This program demonstrates the bubble
	sort program.
*/

#include <iostream>
#include <ctime>
#include <algorithm>
#include <chrono>

double getTime()
{
	return static_cast<double>(std::time(nullptr));
}

int getLength()
{
	std::cout << "Enter length of array: ";
	int n {};
	std::cin >> n;

	return n;
}

void initialize(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter element " << i << " of array: ";
		std::cin >> arr[i];
	}
}

void printArray(int arr[], int n)
{
	std::cout << "\nArray: " << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
}

void bubble_sort(int arr[], int n)
{
	bool swap = false;
	for (int i = 0; i < n - 1; i++)
	{
		swap = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j+1] < arr[j])
			{
				std::swap(arr[j], arr[j + 1]);
				swap = true;
			}
		}
		if (!swap) 
	    {
	    	std::cout << "Early termination on iteration " << (i + 1) << std::endl;
	    	return;
	    }
	}
}

int main()
{
	int n { getLength() };
	int arr[n] {};
	initialize(arr, n);

	std::cout << "Before sorting: ";
	printArray(arr, n);

	auto start = std::chrono::high_resolution_clock::now();
	bubble_sort(arr, n);
	auto stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "\nAfter sorting: ";
	printArray(arr, n);
	std::cout << "\nTook " << duration.count() << " ms." << std::endl;
}