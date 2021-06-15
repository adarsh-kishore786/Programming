/*
    deque.cpp

    This program demonstrates the deque data 
    structure in C++ STL. A deque is a double ended 
    queue, which can be accessed from both ends.

    Deques are similar to vectors, but have faster 
    access time, so they are better for insertion/deletion.
    However, contiguous memory location storage is not 
    guaranteed.
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, deque<T>& d)
{
    for (auto i = d.begin(); i != d.end(); i++)
        os << *i << " ";
    return os;
}

int main()
{
    deque<int> gquiz;
    gquiz.push_back(10);
    gquiz.push_back(20);
    gquiz.push_front(30);
    gquiz.push_front(15);

    cout << "gquiz: " << gquiz << endl;
    cout << "Size: " << gquiz.size() << endl;
    cout << "Front: " << gquiz.front() << endl;
    cout << "Back: " << gquiz.back() << endl;
    cout << "At 2: " << gquiz.at(2) << endl;
    
    cout << "\nAfter popping front:" << endl;
    gquiz.pop_front();
    cout << "gquiz: " << gquiz << endl;

    cout << "\nAfter popping back: " << endl;
    gquiz.pop_back();
    cout << "gquiz: " << gquiz << endl;
}