/*
    map_stl.cpp

    This program demonstrates map
    data structure in C++ STL. A map
    is like a dictionary which was used 
    in Python. A map keeps its keys in sorted order always.
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2> m)
{
    for (auto i = m.begin(); i != m.end(); i++)
        os << i->first << ": " << i->second << endl;
    return os;
}

int main()
{
    map<int, int> m;

    m.insert(pair<int, int>(1, 40));
    m.insert(pair<int, int>(2, 30));
    m.insert(pair<int, int>(3, 60));
    m.insert(pair<int, int>(8, 20));
    m.insert(pair<int, int>(5, 50));
    m.insert(pair<int, int>(6, 50));
    m.insert(pair<int, int>(7, 10));

    cout << "m:\n" << m << endl;

    map<int, int> m2(m.begin(), m.end());
    cout << "m2:\n" << m2 << endl;

    // Remove all elements upto key = 3
    m2.erase(m2.begin(), m2.find(3));
    cout << "m2:\n" << m2 << endl;

    // Remove key = 6
    m2.erase(6);
    cout << "m2:\n" << m2 << endl;

    cout << m2.lower_bound(4.5) -> second << endl;
    cout << m.upper_bound(5) -> second << endl;

    // equal_range() returns (lower_bound, upper_bound)
    auto it = m2.equal_range(5);
    cout << "m2.lower_bound(5) = " << it.first -> second << endl;
    cout << "m2.upper_bound(5) = " << it.second -> second << endl;
}