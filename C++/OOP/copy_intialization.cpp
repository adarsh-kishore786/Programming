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
        m_numerator{numerator}, m_denominator{denominator} {}

    // Copy constructor
    Fraction(const Fraction& fraction):
        m_numerator(fraction.m_numerator), m_denominator{fraction.m_denominator}
    {
        std::cout << "Copy constructor called.\n";
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

    int getNumerator() { return m_numerator; }
    void setNumerator(int numerator) { m_numerator = numerator; }
};

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
    out << fraction.m_numerator << "/" << fraction.m_denominator;
    return out;
}

Fraction makeNegative(Fraction f)
{
    f.setNumerator(-f.getNumerator());
    return f;
}

int main()
{
    Fraction fiveThirds(5, 3);
    std::cout << makeNegative(fiveThirds) << std::endl;

    return 0;
}
