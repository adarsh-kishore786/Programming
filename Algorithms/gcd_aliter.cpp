/*
    gcd_aliter.cpp

    This program presents an alternative way to
    calculate the gcd(a, b) using the fact that
    if gcd(a, b) = g, then there exists integers 
    s and t such that
    as + bt = g
*/

#include <bits/stdc++.h>
using namespace std;

int gcd_rec(int a, int b, int& x, int& y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd_rec(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b); 
    return d;
}

int gcd(int a, int b)
{
    int x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int main()
{
    int a = 454334;
    int b = 54214;
    int x = 1, y = 0;
    cout << "gcd(" << a << ", " << b << ") = " << gcd_rec(a, b, x, y) << endl;
    cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << endl;
}