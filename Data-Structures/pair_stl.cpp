/* 
    pair_stl.cpp

    This program demonstrates the pair 
    in STL.
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p)
{
    os << p.first << " " << p.second;
    return os;
}

int main()
{
    pair<int, char> pair1;

    pair1.first = 100;
    pair1.second = 'G';

    cout << pair1 << endl;

    // Different ways to initialize a pair
    pair<string, double> p2("Geeks for Geeks", 1.23);

    cout << p2 << endl;

    // IF not initialized, the values of pair are initialized
    // to default value
    pair<int, string> p;
    cout << p << endl;

    // The make_pair() command is used to make pairs from two data
    p2 = make_pair("Hello", 2.71828);
    cout << p2 << endl;

    pair<string, double> p1("Bye", 8.1);
    cout << "Before swapping:" << endl;
    cout << "p1: " << p1 << "\n" << "p2: " << p2 << endl;

    p1.swap(p2);

    cout << "After swapping:" << endl;
    cout << "p1: " << p1 << "\n" << "p2: " << p2 << endl;

    // tie() function of pairs
    string a;
    double b;
    tie(a, b) = p2;
    cout << endl << "a: " << a << "\nb: " << b << endl;
}