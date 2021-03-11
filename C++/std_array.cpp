/*
	std_array.cpp

	This program demonstrates the use of the
	std::array data type which does not decay 
	into pointer when passed into a function.
	Thus for-each loop can always be used, among
	other things.
*/

#include <algorithm> // For std::sort
#include <iostream>
#include <array> // For std::array

int getSize(const std::array<int, 3>& ar)
{
	return ar.size(); // No decay to pointers
}

int main()
{
	std::array<int, 3> myArray; // array of 3 integers
	// The length of array must be known at compile time

	std::array<int, 5> arr { 9, 7, 5, 3, 1 }; // initializer list

	myArray = {11}; // Elements 1 and 2 set to 0
	myArray = {4, 5, 6};
	//myArray = {8,9, 10, 334, 3}; // Not allowed. More elements than specified

	// Subscript operator is same as before
	std::cout << "myArray[2] = " << myArray[2] << "\n";
	// The at() is same as [] but does bounds checking

	//std::cout << "myArray[3] = " << myArray[3] << "\n"; // Undefined behaviour
	//std::cout << "myArray[3] = " << myArray.at(3) << "\n"; // Error

	myArray.at(1) = -3;
	std::cout << "myArray[1] = " << myArray.at(1) << "\n";

	// The size function gives length of array
	std::cout << "Size of myArray = " << myArray.size() << "\n";
	std::cout << "Size of myArray = " << getSize(myArray) << "\n";

	std::sort(arr.begin(), arr.end());
	std::cout << "Array after sorting forwards: ";

	for (auto e : arr)
		std::cout << e << " ";
	std::cout << "\n";

	std::sort(arr.rbegin(), arr.rend());
	std::cout << "Array after sorting backwards: ";

	for (auto e : arr)
		std::cout << e << " ";
	std::cout << "\n";
}