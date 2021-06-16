/*
    priority_queue_stl.cpp

    This program demonstrates priority queue
    data structure in C++ STL. A priority queue
    is a queue (FIFO), with elements arranged in 
    decreasing priority. (By default, decreasing order).
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, priority_queue<T> gq)
{
    while (gq.size())
    {
        os << gq.top() << " ";
        gq.pop();
    }
    return os;
}

int main()
{
    priority_queue<int> pq {};
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);

    cout << "pq: " << pq << endl;
    
    cout << "pq.size(): " << pq.size() << endl;
    cout << "pq.top(): " << pq.top() << endl;

    cout << "After pop:" << endl;
    pq.pop();
    cout << "pq: " << pq << endl;

    return 0;
}