/*
	fraction_overloaded.cpp
*/

#include <iostream>
#include <cmath>

class Fraction
{
private:
	int m_num;
	int m_den;

	int gcd(int a, int b)
	{
		if (a == 0 || b == 0)
			return 1;
		int a1 = std::abs(a - b);
		int b1 = std::min(a, b);
		if (a1 == b1)
			return a1;

		gcd(a1, b1);
	}

public:
	Fraction(int num=0, int den=1) {
		int m_gcd = gcd(num, den);
		m_num = num / m_gcd;
		m_den = den / m_gcd;
	}

	void print()
	{
		std::cout << m_num << "/" << m_den << "\n";
	}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	int num { f1.m_num * f2.m_num };
	int den { f1.m_den * f2.m_den };
	return { num, den };
}

int main()
{
	Fraction f1{2, 5};
	f1.print();

	Fraction f2{3, 8};
	f2.print();

	Fraction f3{ f1 * f2 };
	f3.print();

	Fraction f4{ f1 * 2 };
	f4.print();

	Fraction f5{ 2 * f2 };
	f5.print();

	Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
	f6.print();

	Fraction f7{ 0, 6 };
	f7.print();

	return 0;
}