/*
    stack_stl.cpp

    This program demonstrates the stack data
    structure in C++ STL. A stack is based on the 
    principle of LIFO (last in first out).
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printStack(stack<T> s)
{
    cout << "s: ";
    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    } 
    cout << endl;
}

int main()
{
    stack<int> s;
    s.push(21);
    s.push(22);
    s.push(24);
    s.push(25);

    cout << "A stack will print in reverse:" << endl;
    printStack(s);

    s.pop();
    printStack(s);
}