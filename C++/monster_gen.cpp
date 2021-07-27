/*
	monster_gen.cpp

	Generating monster game.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Monster
{
public:
	enum class Type
	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		max_monster_types
	};

private:
	Type m_type {};
	string m_name {};
	string m_roar {};
	int m_hp {};

public:
	Monster(Type type, const string& name, const string& roar, int hp):
		m_type {type}, m_name {name}, m_roar {roar}, m_hp {hp}
	{}

	void print()
	{
		cout << m_name << " the " << getType(m_type) << " has " <<
			m_hp << " hit points and says " << m_roar << endl;
	}

	string getType(Type type)
	{
		switch(type)
		{
			case Type::dragon: return "dragon";
			case Type::goblin: return "goblin";
			case Type::ogre: return "ogre";
			case Type::orc: return "orc";
			case Type::skeleton: return "skeleton";
			case Type::troll: return "troll";
			case Type::vampire: return "vampire";
			case Type::zombie: return "zombie";
		}
		return "???";
	}	
};

class MonsterGenerator
{

private:
	static int getRandomNumber(int min, int max)
	{
		static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

public:
	static Monster generateMonster()
	{
		auto type 
		{ static_cast<Monster::Type>(getRandomNumber(0, (int)Monster::Type::max_monster_types - 1)) };

		static const vector<string> s_names { "Bones", "Dracula", "Azog", "Smaug", "Gollum",
						"Loki" };
		static const vector<string> s_roars { "*rattle*", "*growl*", "*grunt*", "*roar*", 
						"*pound*", "*shout*" };

		auto name { s_names[getRandomNumber(0, (int)s_names.size() - 1)] };
		auto roar { s_roars[getRandomNumber(0, (int)s_roars.size() - 1)] };

		auto hp { getRandomNumber(1, 100) };
		return { type, name, roar, hp };
	}
};

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	rand();

	Monster m { MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}