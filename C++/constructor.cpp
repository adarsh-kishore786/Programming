/*
	constructor.cpp

	This program demonstrates class
	constructors.
*/

#include <cassert>
#include <iostream>

class Fraction
{
private:
	int m_num;
	int m_den;

public:
	Fraction(int num=0, int den=1)
	{
		assert(den != 0);

		m_num = num;
		m_den = den;
	}

	void print()
	{
		std::cout << "Fraction is: " << m_num << " / " << m_den << "\n";
	}
};

class Date
{
private:
	int m_day;
	int m_month;
	int m_year;

public:
	Date() = default; // Explicitly create a default constructor

	Date(int day, int month, int year)
	{
		m_day = day;
		m_month = month;
		m_year = year;
	}

	void print()
	{
		std::cout << "Date: " << m_day << "/" << m_month <<
					 "/" << m_year << "\n";
	}
};

int main()
{
	Fraction f1; // initialized to 0 / 1

	Fraction f2 {3, 5};

	f1.print();
	f2.print();

	Date d1; 
	d1.print();

	Date d2 {22, 3, 2021};
	d2.print();
}