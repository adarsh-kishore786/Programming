/*
    tuple_stl.cpp

    This program demonstrates the tuple STL.
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2, typename T3>
ostream& operator<<(ostream& os, tuple<T1, T2, T3>& t)
{
    os << get<0>(t) << endl;
    os << get<1>(t) << endl;
    os << get<2>(t) << endl;
    return os;
}

int main()
{
    // Making tuples
    tuple<char, int, double> t1('A', 6, 3.14);
    cout << t1 << endl;

    tuple<int, int, string> t2;
    t2 = make_tuple(2, 3, "Hello");
    cout << t2 << endl;

    // tuple is mutable
    get<0>(t1) = 'B';
    get<1>(t1) = 10;
    get<2>(t1) = 2.71828;
    cout << t1 << endl;

    // Number of elements in tuple
    cout << "t1 has " << tuple_size<decltype(t1)>::value << " elements.\n";

    // Swapping tuples
    tuple<int, int, string> t3(10, 23, "World");
    cout << "Before swapping:\nt2 = " << t2 << endl;
    cout << "t3 = " << t3 << endl;

    t2.swap(t3);

    cout << "After swapping:\nt2 = " << t2 << endl;
    cout << "t3 = " << t3 << endl;

    // unpacking a tuple
    int a, b; 
    string c;

    tie(a, b, c) = t3;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    tie(a, ignore, c) = t2; // ignore second element
    cout << "\na = " << a << endl;
    cout << "c = " << c << endl;

    // concat two tuples
    tuple<int> t5(10);
    tuple<char, double> t6('A', 5.6);

    auto t7 = tuple_cat(t5, t6);
    cout << "t7:\n" << t7 << endl;
}