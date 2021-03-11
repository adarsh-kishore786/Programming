/*
	find_pointer.cpp

	This program implements a find 
	function which searches an array
	for a value using pointers.
*/

#include <iostream>
#include <algorithm>

int* find(int* start, int* end, int val)
{
	for (int* p = start; p < end; p++)
		if (val == *p)
			return p;
	return end;
}

int main()
{
	int arr[] { 2, 5, 4, 10, 8, 20, 16, 40 };

	int* adr { find(std::begin(arr), std::end(arr), 20) };

	if (adr == std::end(arr))
		std::cout << "Element not found in array.\n";
	else
		std::cout << "Element found at position " << (adr - std::begin(arr)) << std::endl;
}