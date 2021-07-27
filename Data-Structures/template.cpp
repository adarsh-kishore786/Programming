/*
    template.cpp

    This program demonstrates the use of templates
    in C++.
*/

#include <iostream>
using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents) : m_cents {cents} {}

    friend bool operator<(Cents& c1, Cents& c2)
    {
        if (c1.m_cents < c2.m_cents)
            return true;
        return false;
    }

    friend bool operator>(Cents& c1, Cents& c2)
    {
        return c2 < c1;
    }

    friend ostream& operator<<(ostream& os, const Cents& c)
    {
        os << c.m_cents << endl;
        return os;
    }
};

template <typename T>
T& max_(T& x, T& y)
{
    return (x > y) ? x : y;
}

int main()
{
    Cents nickle { 5 };
    Cents dime { 10 };

    int a = 2, b = 3;
    double c = 2.5, d = 1.01;
    char e = 'A', f = 'a';

    cout << int(max_(a, b)) << endl;
    cout << double(max_(c, d)) << endl;
    cout << char(max_(e, f)) << endl;
    cout << Cents(max_(nickle, dime)) << endl;

    cout << "Hello, World!" << endl;
}