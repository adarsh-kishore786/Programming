/*
	for_each.cpp

	This program demonstrates the 
	for each loop syntax.
*/

#include <iostream>

int main()
{
	constexpr int fibonacci[] { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	for (const auto& number : fibonacci)
		std::cout << number << " ";
	std::cout << "\n";

	std::string array[] { "peter", "likes", "frozen", "yogurt" };
	for (const auto& str : array)
		std::cout << str << " ";
	std::cout << "\n";

	constexpr int scores[] { 84, 92, 76, 81, 56 };
	int maxScore { scores[0] };

	for (const auto& score : scores)
		if (score > maxScore)
			maxScore = score;

	std::cout << "Maximum score: " << maxScore << "\n";
	std::string names[] { "Alex", "Betty", "Caroline", "Dave", "Emily" };

	maxScore = 0;
	int i{0};
	for (const auto& score : scores)
	{
		if (score > maxScore)
		{
			std::cout << "Student " << names[i] << " beat the previous best score of "
				<< maxScore << " by " << (score - maxScore) << " points.\n";
			maxScore = score;
		}
		i++;
	}
}