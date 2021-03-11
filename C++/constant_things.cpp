/*
	constant_things.cpp

	This program explores use of const, 
	constexpr etc
*/

#include <iostream>

constexpr double gravity { 9.8 }; // Now gravity is constant
constexpr int sidesInSquare { 4 };

int main()
{
	//gravity = 9.8; // Not allowed

	// const are of two types- runtime and compile time const.
	// runtime const. can be evaluated only at runtime, eg
	// userAge. Compile time const can be evaluated at compile 
	// time, eg. gravity and sidesInSquare
	// constexpr is used to explicitly declare a variable
	// compile-time const. 

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	const int userAge { age };
	std::cout << "User age is " << userAge << ".\n";
}