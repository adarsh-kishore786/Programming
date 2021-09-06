/*
    set_stl.cpp

    This program demonstrates the set
    data structure in C++ STL. A set is a type of 
    associative container in which value of each
    element is unique.
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printSet(const set<T>& s)
{
    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
}

int main()
{
    set<int, greater<int>> s1;

    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);

    // Only one 50 will be added
    s1.insert(50);
    s1.insert(10);

    cout << "s1: ";
    for (auto i = s1.begin(); i != s1.end(); i++)
        cout << *i << " ";
    cout << endl;

    set<int> s2(s1.begin(), s1.end());
    cout << "s2: ";
    printSet(s2);
    cout << endl;

    int num = s2.erase(50);
    cout << "s2.erase(50): " << num << " element removed.\n";
    cout << "s2: ";
    printSet(s2);
    cout << endl;

    // The lower_bound(g) function
    // return an iterator to the element to g or just
    // greater. The upper_bound(g) function returns an iterator
    // immediately after g
    cout << "s2.upper_bound(40): " << *(s2.upper_bound(40)) << endl;
    cout << "s2.upper_bound(39): " << *(s2.upper_bound(39)) << endl;

    cout << "s1.lower_bound(39): " << *(s1.lower_bound(39)) << endl;
}