/*
	structs.cpp

	This program demonstrates concept of 
	structures in C++.
*/

#include <iostream>
#include <string>

struct Employee
{
	// We can initialize with default values if we want
	int id{ 1 };
	std::string name{ "John Doe "};
	int age{ 34 };
	double wage{ 10000};
};

void printEmployee(Employee e)
{
	std::cout << "ID  : " << e.id << std::endl;
	std::cout << "Name: " << e.name << std::endl;
	std::cout << "Age : " << e.age << std::endl;
	std::cout << "Wage: " << e.wage << std::endl << std::endl;
}

int main()
{
	Employee joe{};
	joe.id = 5;
	joe.name = "Joe Carl";
	joe.age = 25;
	joe.wage = 32500.50;

	printEmployee(joe);
	Employee john{};
	printEmployee(john); // Default values

	Employee bond { 7, "James Bond", 47, 200000.0 };
	printEmployee(bond);

	// Today is joe's birthday
	joe.age++;
	printEmployee(joe);

	// Bond got a salary increment
	bond.wage += 10000.4;
	printEmployee(bond);
}