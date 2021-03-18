/*
	member_list.cpp

	This program demonstrates concept
	of using member lists in constructor
	initialization.
*/

#include <iostream>

class Something
{
private:
	// const int m_value1; // This is error. Can't assign to a constant
	int m_value1;
	double m_value2;
	char m_value3;

public:
	Something()
	{
		// These are assignments, not initialization
		m_value1 = 1;
		m_value2 = 2.2;
		m_value3 = 'c';

	}

	void print()
	{
		std::cout << "Value 1: " << m_value1 << "\n";
		std::cout << "Value 2: " << m_value2 << "\n";
		std::cout << "Value 3: " << m_value3 << "\n\n";
	}
};

class Something2
{
private:
	// This works as we are initializing in member initializing list
	// Not assigning
	const int m_value1;
	double m_value2;
	char m_value3;

public:
	Something2() : m_value1 { 1 }, m_value2 { 2.2 }, m_value3 { 'c' }
	{}

	void print()
	{
		std::cout << "Value 1: " << m_value1 << "\n";
		std::cout << "Value 2: " << m_value2 << "\n";
		std::cout << "Value 3: " << m_value3 << "\n\n";
	}
};

// We can give our own values also
class Something3
{
private:
	const int m_val1 { 5 };
	const double m_val2 { 3.14159 };
	const char m_val3 { 'c' };

public:
	Something3() = default;
	
	Something3(int v1, double v2, char v3):
		m_val1 { v1 },
		m_val2 { v2 },
		m_val3 { v3 }
	{}

	void print()
	{
		std::cout << "Value 1: " << m_val1 << "\n";
		std::cout << "Value 2: " << m_val2 << "\n";
		std::cout << "Value 3: " << m_val3 << "\n\n";
	}
};

int main()
{
	Something s;
	s.print();

	Something2 s2;
	s2.print();

	Something3 s3;
	s3.print();

	Something3 s4 { 2, 2.718, 'd' };
	s4.print();
}