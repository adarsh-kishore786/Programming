/*
    average.cpp

    This program finds the average using 
    a template.
*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T average(const vector<T>& v)
{
    T sum { 0 };
    for (auto e : v)
        sum += e;
    return sum /= v.size();
}

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents): m_cents {cents} {}

    friend ostream& operator<<(ostream& os, const Cents& c)
    {
        os << c.m_cents;
        return os;
    }

    Cents& operator+=(const Cents& c)
    {
        m_cents += c.m_cents;
        return *this;   
    }

    Cents& operator/=(int l)
    {
        m_cents /= l;
        return *this;
    }
};

int main()
{
    vector<int> v1;
    v1.push_back(5);
    v1.push_back(6);

    vector<double> v2 = { 5.0, 6.1, 100 };
    vector<char> v3 = { 'A', 'c' };
    vector<Cents> v4 = { {5}, {7} };
    
    cout << int(average(v1)) << endl;
    cout << double(average(v2)) << endl;
    cout << char(average(v3)) << endl;
    cout << Cents(average(v4)) << endl;
}