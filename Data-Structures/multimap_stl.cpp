/*
    multimap_stl.cpp

    This program demonstrates the data 
    structure multimap in C++ STL. Multimap
    is similar to map, with the addition that
    multiple values can have the same key. 
    Also, multimap keeps its keys in sorted 
    order always.
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const multimap<T1, T2>& mm)
{
    for (auto i = mm.begin(); i != mm.end(); i++)
        os << i->first << ": " << i->second << endl;
    return os;
}

int main()
{
    multimap<int, int> gquiz1; // empty

    gquiz1.insert({1, 40});
    gquiz1.insert({2, 30});
    gquiz1.insert({3, 60});
    gquiz1.insert({8, 50});
    gquiz1.insert({6, 50});
    gquiz1.insert({6, 10});

    cout << "gquiz1:\n" << gquiz1 << endl;
    gquiz1.insert({4, 50});
    gquiz1.insert({6, 70});

    multimap<int, int> gquiz2 (gquiz1.begin(), gquiz1.end());
    cout << "gquiz2:\n" << gquiz2 << endl;

    // erase all elements with key 6
    gquiz1.erase(6);
    cout << "gquiz1:\n" << gquiz1 << endl;

    // erase all keys upto 3 (excluding)
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
    cout << "gquiz2:\n" << gquiz2 << endl;

    cout << "Lower bound value of key 3 = " << gquiz1.lower_bound(3)->second << endl;
    cout << "Upper bound value of key 3 = " << gquiz1.upper_bound(3)->second << endl;

    cout << "Using equal_range(3):" << endl;
    auto er = gquiz1.equal_range(3);
    cout << "Lower bound: (" << er.first->first << ", " << er.first->second << ")" << endl;
    cout << "Upper bound: (" << er.second->first << ", "<< er.second->second << ")" << endl;
}