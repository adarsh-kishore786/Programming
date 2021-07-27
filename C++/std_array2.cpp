/*
	std_array2.cpp

	More features of std::array.
*/

#include <iostream>
#include <array>

struct House
{
	int number {};
	int stories {};
	int roomsPerStorey {};
};

int main()
{
	std::array<House, 3> houses {
		{
			{ 13, 4, 30 }, // Double brace initalizor for composite data types
			{ 14, 3, 10 },
			{ 15, 3, 40 }
		}
	};

	for (const auto& house : houses)
		std::cout << "House number " << house.number
				  << " has " << (house.stories * house.roomsPerStorey)
				  << " rooms.\n";
}