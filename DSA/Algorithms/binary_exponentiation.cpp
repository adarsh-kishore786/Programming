/*
    Binary Exponentiation is a trick that allows
    calculation of a^n using only O(log n) 
    multiplications instead of O(n).

    This trick will also apply to any operation 
    which has the associative property, like modular
    multiplication, matrix multiplication.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Matrix2D
{    
public:
    vector<vector<long long>> m {};

    Matrix2D(vector<vector<long long>> n) { m  = n; }
    Matrix2D() {
        m.push_back({1, 0});
        m.push_back({0, 1});
    }

    Matrix2D& operator*=(const Matrix2D& m1)
    {
        long long a00 = m[0][0] * m1.m[0][0] + m[0][1] * m1.m[1][0];
        long long a01 = m[0][0] * m1.m[0][1] + m[0][1] * m1.m[1][1];
        long long a10 = m[1][0] * m1.m[0][0] + m[1][1] * m1.m[1][0];
        long long a11 = m[1][0] * m1.m[0][1] + m[1][1] * m1.m[1][1];
        m.clear();
        m.push_back({a00, a01});
        m.push_back({a10, a11});
        return *this;
    }
};

ll binpow_rec(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow_rec(a, b/2);
    if (b % 2)
        return res * res * a;
    return res*res;
}

ll binpow(ll a, ll b) 
{
    ll p = 1;
    while (b > 0)
    {
        if (b & 1)
            p *= a;
        a *= a;
        b >>= 1;
    }
    return p;
}

ll pow_mod(ll a, ll b, ll n)
{
    ll p = 1;
    while (b > 0)
    {
        if (b & 1)
            p = (p * a % n) % n;
        a = (a * a) % n;
        b >>= 1;
    }
    return p;
}

// Matrix multiplication is also associative
ll getFibonacci(ll n)
{
    vector<vector<ll>> v = {
        {1, 1},
        {1, 0}
    };
    Matrix2D m(v);
    Matrix2D m1 {};
    while (n > 0)
    {
        if (n & 1)
            m1 *=  m;
        m *= m;
        n >>= 1;
    }
    return m1.m[0][0];
}

int main()
{
     ll a = 287, b = 8;
     cout << a << "^" << b << " as computed by recursion: " << binpow_rec(a, b) << endl;
     cout << a << "^" << b << " as computed by loop     : " << binpow(a, b) << endl;

     ll c = 234532134;
     ll d = 32456432;
     ll n = 32452433;
     cout << c << "^" << d << " mod " << n << " = " << pow_mod(c, d, n) << endl << endl;

    for (int i = 0; i < 50; i++)
        cout << getFibonacci(i) << " ";
    cout << endl << endl;
}