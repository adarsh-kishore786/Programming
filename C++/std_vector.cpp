/*
	std_vector.cpp

	This demonstrates the std::vector data
	type. They are C++ versions of 
	dynamic arrays and lot more.
*/

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> array; // No need to specify length
	array = {1, 4, 32};

	for (const auto& e : array)
		std::cout << e << " ";
	std::cout << "\n";

	std::cout << "array[2] = " << array[2] << "\n"; 
	std::cout << "array[5] = " << array[5] << "\n"; // No bounds checking
	std::cout << "array.at(2) = " << array.at(2) << "\n";
	//std::cout << "array.at(5) = " << array.at(5) << "\n"; // Error: bounds checking

	std::cout << "Size of array is: " << array.size() << "\n";

	// vector can be resized
	array.resize(5);
	for (int i = 3; i < 5; i++)
		array[i] = i*i;

	for (const auto& e : array)
		std::cout << e << " ";
	std::cout << "\nSize of array is: " << array.size() << "\n";
}