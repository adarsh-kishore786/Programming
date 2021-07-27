/*
	dungeon_items.cpp

	This program demonstrates the use of 
	std::accumulate using a dungeon items game.
*/

#include <iostream>
#include <numeric> // std::accumulate
#include <algorithm> 
#include <array>
#include <string>

enum class Dungeon_items
{
	health_potion,
	torch,
	arrow,
	max_items
};

std::string item(Dungeon_items i)
{
	switch (i)
	{
		case Dungeon_items::health_potion: return "Health Poition";
		case Dungeon_items::torch: return "Torch";
		case Dungeon_items::arrow: return "Arrow";
	}
}

int countTotalItems(std::array<int, (int)Dungeon_items::max_items> items)
{
	return std::accumulate(items.begin(), items.end(), 0); // initial sum to be taken as 0
}

int main()
{
	std::array<int, (int)Dungeon_items::max_items> items {};
	items[(int)Dungeon_items::health_potion] = 2;
	items[(int)Dungeon_items::torch] = 5;
	items[(int)Dungeon_items::arrow] = 10;

	for (int i = 0; i < (int)items.size(); i++)
		std::cout << item((Dungeon_items)i) << ": " << items[i] << "\n";

	std::cout << "\nTotal items: " << countTotalItems(items) << "\n";
}