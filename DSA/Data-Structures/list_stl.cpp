/*
    list_stl.cpp

    This program demonstrates the list data structure
    in C++. It is a doubly linked list useful for fast
    insertion and deletion but not so much for accessing
    each data element. 
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, list<T>& list)
{
    for (auto i = list.begin(); i != list.end(); i++)
        os << *i << " ";
    return os;
}

int main()
{
    list<int> gqlist1, gqlist2;

    for(int i = 0; i < 10; i++)
    {
        gqlist1.push_back(i * 2);
        gqlist2.push_front(i * 3);
    }

    cout << "gqlist 1: " << gqlist1 << endl;
    cout << "gqlist 2: " << gqlist2 << endl << endl;

    cout << "gqlist1.front(): " << gqlist1.front() << endl;
    cout << "gqlist2.front(): " << gqlist2.front() << endl;

    cout << "\ngqlist1.back(): " << gqlist1.back() << endl;
    cout << "gqlist2.back(): " << gqlist2.back() << endl;

    cout << "\nPopped gqlist1 in front and gqlist2 in back:\n";
    gqlist1.pop_front();
    gqlist2.pop_back();

    cout << "gqlist 1: " << gqlist1 << endl;
    cout << "gqlist 2: " << gqlist2 << endl << endl;

    cout << "Sort gqlist1: " << endl;
    gqlist1.sort();
    cout << "Reverse gqlist2: " << endl;
    gqlist2.reverse();

    cout << "gqlist 1: " << gqlist1 << endl;
    cout << "gqlist 2: " << gqlist2 << endl << endl;
}