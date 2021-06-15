/*
    gcd.cpp

    This program demonstrates the Euclidean algorithm
    to calculate gcd(a, b) in O(log min(a, b)) time 
    cmplexity. It also shows its various variants.
*/

#include <bits/stdc++.h>
using namespace std;

int gcd_rec(int a, int b)
{
    return b ? gcd_rec(b, a % b) : a;
}

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        int temp = a;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b; // a / gcd(a, b) is guaranteed to be an integer as by definiton, gcd(a, b) | a
}

int main()
{
    int a = 56754;
    int b = 213456;

    cout << "GCD of " << a << " and " << b << ": " << gcd(a, b) << endl;
    cout << "LCM of " << a << " and " << b << ": " << lcm(a, b) << endl;
}