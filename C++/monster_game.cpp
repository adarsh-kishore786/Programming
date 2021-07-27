/*
	monster_game.cpp

	Demonstrates various concepts to give 
	info about a monster in game.
*/

#include <iostream>
#include <string>

enum class Type
{
	ogre,
	dragon,
	orc,
	giant_spider,
	slime
};

struct Monster
{
	std::string name;
	Type type;
	int hp;
};

std::string type(Monster m)
{
	switch (m.type)
	{
		case Type::ogre: return "Ogre";
		case Type::dragon: return "Dragon";
		case Type::orc: return "Orc";
		case Type::giant_spider: return "Giant Spider";
		case Type::slime: return "Slime";
	}
}

void printMonster(Monster m)
{
	std::cout << "This " << type(m) << " is named " << m.name
			  << " and has " << m.hp << " HP.\n";
}

Monster initialize(std::string name, Type type, int hp)
{
	return {name, type, hp};
}

int main()
{
	Monster m1 = initialize("Torg", Type::ogre, 145);
	Monster m2 = initialize("Blurp", Type::slime, 23);

	printMonster(m1);
	printMonster(m2);
}