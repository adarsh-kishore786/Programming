#include <iostream>
#include <cassert>
#include <string>

class Fraction
{
private:
    int m_numerator {};
    int m_denominator {};

public:

    // Default constructor
    Fraction(int numerator=0, int denominator=1):
        m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0);
    }

    // Copy constructor
    Fraction(const Fraction& fraction):
        m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        std::cout << "Copy constructor called.\n";
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
};

// Sometimes we may wish to turn off the implicit conversion of data types
// in constructor as it can lead to undesirable results. For this we can use
// the explicit keyword.
class MyString
{
private:
    std::string m_string;

public:
    // This prevents any use of MyString(char) constructor
    // This can be used to make the copy constructor = delete
    // which would make the object immutable
    MyString(char) = delete;
    
    // This constructor is not used for implicit conversions at all
    explicit MyString(int x)
    {
        m_string.resize(x);
    }

    MyString(const char* string)
    {
        m_string = string;
    }

    friend std::ostream& operator<<(std::ostream& out, const MyString& mystring);
};

std::ostream& operator<<(std::ostream& out, const MyString& mystring)
{
    out << mystring.m_string;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
    out << fraction.m_numerator << "/" << fraction.m_denominator;
    return out;
}

void printFraction(Fraction f)
{
    std::cout << f << std::endl;
}

void printString(MyString s)
{
    std::cout << s << std::endl;
}

int main()
{
    printFraction(6); // 6 is an int got implicitly converted to Fraction(6, 1)
    const char* msg = "abc";
    printString(msg);
    // printString('x'); will raise error as printString wants MyString, and there is
    // no implicit constructor to handle chars

    return 0;
}
