/*
	public_private_classes.cpp

	This program demonstrates the member 
	functions and variables in a class. They
	are kept private by default in a class, and
	can be made public by using public 
	keyword.
*/

#include <iostream>

class DateClass
{
	// Private by default
	int m_month; 
	int m_day;
	int m_year;

public:
	void setDate(int month, int day, int year)
	{
		m_month = month;
		m_day = day;
		m_year = year;
	}

	void print()
	{
		std::cout << m_day << "/" << m_month << "/" << m_year << "\n";
	}

	void copyFrom(const DateClass& d)
	{
		m_day = d.m_day;
		m_month = d.m_month;
		m_year = d.m_year;
	}
};

int main()
{
	DateClass date; 
	//date.m_month = 12; // Error: private variable
	date.setDate(3, 2, 2021);

	date.print();

	DateClass date2;
	date2.copyFrom(date);
	date2.print();

	return 0;
}