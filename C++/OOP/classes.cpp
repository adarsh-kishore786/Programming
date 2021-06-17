/*
	classes.cpp

	Classes are the basic features of OOP.
*/

#include <iostream>
#include <string>
// They are technically similar to structs
// But they can also contain member functions
// called methods
class DateClass
{
public:
	int m_year {};
	int m_month {};
	int m_day {};

	void print()
	{
		std::cout << m_day << "/" << m_month << "/" << m_year << ".\n";	
	}
};

class Employee
{
public:
	std::string m_name {};
	int m_id {};
	double m_wage {};

	void print()
	{
		std::cout << "Name: " << m_name << "\n"
				  << "ID  : " << m_id   << "\n"
				  << "Wage: " << m_wage << "\n";
		std::cout << "\n";
	}
};

int main()
{
	DateClass today { 2021, 03, 12 };
	std::cout << "Today is: ";
	today.print();

	today.m_day = 14;
	std::cout << "Day after tomorrow is: ";
	today.print();
	std::cout << "\n";

	Employee alex { "Alex", 1, 25.00 };
	Employee joe { "Joe", 2, 22.25 };

	alex.print();
	joe.print();

	return 0;
}