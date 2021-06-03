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
T& max(T& x, T& y)
{
    return (x > y) ? x : y;
}

int main()
{
    Cents nickle { 5 };
    Cents dime { 10 };

    cout << int(max(2, 3)) << endl;
    cout << double(max(2.5, 1.01)) << endl;
    cout << char(max('A', 'a')) << endl;
    cout << Cents(max(nickle, dime)) << endl;
}