/*
	lambda_captures.cpp

	This program demnstrates lambda
	capture expressions.
	A lambda function has the expression
	[capture expression] (param) -> return
	{}
*/

#include <iostream>
#include <array>
#include <algorithm>
#include <string>

int main()
{
	std::array<std::string, 4> arr { "apple", "banana", "walnut", "lemon" };

	std::cout << "Search for: ";
	std::string s_str {};
	std::cin >> s_str;

	auto substr 
	{
		[s_str] (std::string str) 
		{
			return (str.find(s_str) != std::string::npos);
		}
	};

	auto found = std::find_if(arr.begin(), arr.end(), substr);

	if (found == arr.end())
		std::cout << s_str << " does not exist.\n";
	else
		std::cout << s_str << " exists in " << *found << ".\n";
}