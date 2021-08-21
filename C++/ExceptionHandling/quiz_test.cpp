#include <iostream>
#include <stdexcept>

class Fraction
{
private:
    int m_num {};
    int m_den {};

public:
    Fraction(int num=0, int den=1)
    {
        if (den == 0)
            throw std::runtime_error("Invalid denominator");

        m_num = num;
        m_den = den;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f)
    {
        os << f.m_num << " / " << f.m_den;
        return os;
    }
};

int main()
{
    std::cout << "Enter the numerator: ";
    int numerator;
    std::cin >> numerator;

    std::cout << "Enter the denominator: ";
    int denominator;
    std::cin >> denominator;

    try
    {
        Fraction f(numerator, denominator);
        std::cout << "Your fraction is: " << f << '\n';
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}
