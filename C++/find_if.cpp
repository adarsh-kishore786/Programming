/*
	find_if.cpp

	This program demonstrates the 
	function std::find_if in algorithms.
	It finds a given element in a container
	satisfying some given constraints.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> input()
{
	int n {};
	std::cout << "Enter length of array: ";
	std::cin >> n;

	std::vector<std::string> arr(n);

	for (auto& v : arr)
	{
		std::cout << "Enter a string: ";
		std::cin >> v;
	}

	return arr;
	
}

bool hasnut(std::string str)
{
	return (str.find("nut") != std::string::npos);
}

int main()
{
	std::vector<std::string> arr {input()};

	auto found { std::find_if(arr.begin(), arr.end(), hasnut) };

	if (found == arr.end())
		std::cout << "No string contains nut";
	else
		std::cout << *found << " has nut.";
}