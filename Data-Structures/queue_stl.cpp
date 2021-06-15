/*
    queue_stl.cpp

    This program demonstrates the queue data structure
    in the C++ STL. queue is based on the principle of 
    FIFO (First In First Out).
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, queue<T> q)
{
    queue<T> temp = q;
    while (!temp.empty())
    {
        os << temp.front() << " ";
        temp.pop();
    }
    return os;
}

int main()
{
    queue<int> gq;
    gq.push(10);
    gq.push(20);
    gq.push(30);

    cout << "gq: " << gq << endl;
    cout << "gq.size(): " << gq.size() << endl;

    cout << "After popping, " << endl;
    gq.pop();
    cout << "gq: " << gq << endl;
}