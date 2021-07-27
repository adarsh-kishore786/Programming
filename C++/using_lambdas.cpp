/*
	using_lambdas.cpp

	This program demontrates the use of lambdas, 
	which are anonymous functions.
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

int main()
{
	std::vector<std::string> arr {input()};

	// The general syntax of lambdas is
	// [Capture clause](params)->return type
	// {
    // }
    // In case return type is not specified, auto is used
    // which is good enough for trivial functions.

    auto hasNut {
    	[](std::string str)
    	{
    		return (str.find("nut") != std::string::npos);
    	}
    };
    
	auto found { std::find_if(arr.begin(), arr.end(), hasNut) };

	if (found == arr.end())
		std::cout << "No string contains nut";
	else
		std::cout << *found << " has nut.";
}