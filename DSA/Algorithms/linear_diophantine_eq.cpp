/*
    linear_diophantine_eq.cpp

    This program demonstrates how to solve the 
    linear diophantine equation in two 
    variables ax + by = c where a, b, c are known
    integers and x,y are unknown integers.
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y)
{
    x = 1, y = 0;
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

int gcd(int a, int b)
{
    int x = 1, y = 0;
    return gcd(a, b, x, y);
}

bool solnExists(int a, int b, int c)
{
    if (!a && !b)
        return !c;
    return !(c % gcd(abs(a), abs(b)));
}   

void findOneSolution(int a, int b, int c, int &x, int &y, int &g)
{
    g = gcd(abs(a), abs(b), x, y);

    x *= c / g;
    y *= c / g;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
}
// All possible solutions are x = x_0 + kb/g, y = y_0 - ka/g

// We are working with normalized eq. (a/g)x + (b/g)y = (c/g)
void shift_solution(int &x, int &y, int a, int b, int cnt)
{
    x += cnt * a;
    y -= cnt * b;
}

int num_solution(int a, int b, int c, int minx, int maxx, int miny, int maxy)
{
    int x, y, g;
    if (!solnExists(a, b, c))
        return 0;

    findOneSolution(a, b, c, x, y, g);
    a /= g;
    b /= g;

    int sign_a = (a > 0) ? 1 : -1;
    int sign_b = (b > 0) ? 1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int lx2 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int rx1 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}

int main()
{
    int a = -5, b = 6, c = 90;
    int x, y, g;
    cout << "One solution of " << a << "x + " << b << "y = " << c << endl;

    if (solnExists(a, b, c))
    {
        findOneSolution(a, b, c, x, y, g);
        cout << "x = " << x << ", y = " << y << endl;
    }
    else
        cout << "No solution exists." << endl;
}
