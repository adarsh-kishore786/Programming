/*
	oper_overloading.cpp

	This program demonstrates the concept 
	of operator overloading.
*/

#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents): m_cents {cents} {}
	int getCents() const
	{
		return m_cents;
	}

	friend Cents operator+(const Cents& c1, const Cents& c2);
	friend Cents operator-(const Cents& c1, const Cents& c2);
};

Cents operator+(const Cents& c1, const Cents& c2)
{
	return Cents(c1.m_cents + c2.m_cents);
}

Cents operator-(const Cents& c1, const Cents& c2)
{
	return Cents(c1.m_cents - c2.m_cents);
}

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents centSum { cents1 + cents2 };
	Cents centDiff { cents2 - cents1 };

	std::cout << "I have " << centSum.getCents() << " cents.\n";
	std::cout << "I gave " << cents1.getCents() << " of my " << cents2.getCents() << " cents and now I have "
	 			<< centDiff.getCents() << " cents left.\n";

	return 0;
}