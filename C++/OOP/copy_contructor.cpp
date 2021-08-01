#include <cassert>
#include <iostream>

class Fraction
{
private:
	int m_numerator {};
	int m_denominator {};

public:
	// Default constructor
	Fraction(int numerator=0, int denominator=1):
		m_numerator {numerator}, m_denominator {denominator}
	{
		assert(denominator != 0);
	}

	// Copy constructor is created by default, but we can create
	// our explicit copy constructor also
	Fraction(const Fraction& fraction):
		m_numerator { fraction.m_numerator }, m_denominator { fraction.m_denominator }
	{
		std::cout << "Copy constructor called.\n";
	} 

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

// We can also hide the copy constructor to make it impossible to do 
// copy initialization
class Complex
{
private:
	double m_real {};
	double m_imag {};

	Complex(const Complex& complex):
		m_real{complex.m_real}, m_imag{complex.m_imag}
	{}

public:
	Complex(double real, double imag):
		m_real{real}, m_imag{imag} {}

	friend std::ostream& operator<<(std::ostream& out, const Complex& complex);
};

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
	out << complex.m_real << " + (" << complex.m_imag << ")i";
	return out;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
	out << f.m_numerator << "/" << f.m_denominator;
	return out;
}

void fractionTest()
{
	// Direct initialization
	int x (5);
	Fraction fiveThirds(5, 3);

	std::cout << "x = " << x << std::endl;	
	std::cout << "f = " << fiveThirds << std::endl;

	// Uniform initialization
	int y {5};
	Fraction f {7, 9};

	std::cout << "\ny = " << y << std::endl;
	std::cout << "f = " << f << std::endl;

	// Copy initialization
	int z = 6; // Copy initialize an integer
	Fraction six = Fraction(6); // Copy initialize a fraction, will invoke Fraction(6, 1)
	Fraction seven = 7; // Compiler will try to find a way to convert 7 to Fraction, will call
	// Fraction(7, 1) and do copy initialization

	std::cout << "\nz = " << x << std::endl;
	std::cout << "six = " << six << std::endl;
	std::cout << "seven = " << seven << std::endl;

	Fraction fcopy(fiveThirds); // Direct initialization, with what constructor?
	std::cout << "\nfcopy = " << fcopy << std::endl;
}

int main()
{
	fractionTest();

	Complex c1{7, 3};
	Complex c2(8, 3);

	std::cout << "\nc1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl;

	// Complex c3 = c2; Copy initialization not allowed
	// Complex c3(c2); Direct initialization with copy constructor not allowed
	// Complex c3{c2}; Uniform initialization with copy constructor not allowed
	Complex c3 = {0, 0};
	c3 = Complex(0, 0);
	std::cout << "c3 = " << c3 << std::endl;
	return 0;
}