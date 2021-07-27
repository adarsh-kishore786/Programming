/*
	type_aliases.cpp

	This program demonstrates the typedef
	statement and other aliasing statements.
*/

#include <iostream>

// using type aliasing also allows more
// meaningful looking code

using testScore_t = int;

testScore_t getScore()
{
	return 100;
}

int main()
{
	typedef double distance_t; // double can now be referred to as distance_t
	distance_t d { 5.345 };

	std::cout << "d = " << d << std::endl;

	typedef double speed_t;
	speed_t s { d }; // both s and d are ultimately the same data type
					 // so this is allowed
	std::cout << "s = " << s << std::endl;

	// An improved syntax
	using mytype_t = long;
	mytype_t g { 56754555 };
	std::cout << "g = " << g << std::endl;
	std::cout << "score = " << getScore() << std::endl;
}