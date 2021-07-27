/*
	animal_legs.cpp

	This program uses an array and
	an enum to simulate an animal farm.
*/

#include <iostream>

namespace Animal
{
	enum Animal
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		max_animals
	};
}

void initialize(int legs[])
{
	legs[Animal::chicken] = 2;
	legs[Animal::dog] = 4;
	legs[Animal::cat] = 4;
	legs[Animal::elephant] = 4;
	legs[Animal::duck] = 4;
	legs[Animal::snake] = 0;
}

int main()
{
	int legs[Animal::max_animals] {};
	initialize(legs);

	std::cout << "An elephant has " << legs[Animal::elephant] << " legs.\n";
}