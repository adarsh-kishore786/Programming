/*
	default_captures.cpp

	This program demonstrates concept of default
	captures in lambda functions.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> areas {100, 25, 121, 40, 56};

	int width {};
	int height {};

	std::cout << "Enter width and height: ";
	std::cin >> width >> height;

	auto found { std::find_if(areas.begin(), areas.end(),
					[=](int knownArea) 
					{
						return (width * height == knownArea);
					})};

	if (found == areas.end())
		std::cout << "I don't know this area.\n";
	else
		std::cout << "This area exists.\n";
}