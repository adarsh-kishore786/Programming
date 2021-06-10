/*
    vector_stl.cpp

    This program demonstrates the vector
    STL in C++.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1;

    // Inserting elements at the back of the vector
    for (int i = 1; i <= 5; i++)
        v1.push_back(i);

    cout << "Output of begin and end: ";
    for (auto i = v1.begin(); i != v1.end(); i++)
        cout << *i << " ";

    cout << "\nOutput of cbegin and cend: ";
    for (auto i = v1.cbegin(); i != v1.cend(); i++)
        cout << *i << " ";

    cout << "\nOutput of rbegin and rend: ";
    for (auto i = v1.rbegin(); i != v1.rend(); i++)
        cout << *i << " ";
    
    cout << "\nOutput of crbegin and crend: ";
    for (auto i = v1.crbegin(); i != v1.crend(); i++)
        cout << *i << " ";

    // Size, capacity of vector
    cout << "\nSize: " << v1.size() << endl;
    cout << "Capacity: " << v1.capacity() << endl;
    cout << "Max Size: " << v1.max_size() << endl;

    v1.resize(4);
    cout << "\nAfter resizing:" << endl;
    cout << "Size: " << v1.size() << endl;
    cout << "Capacity: " << v1.capacity() << endl;
    cout << "Max Size: " << v1.max_size() << endl;

    // Checking if vector is empty or not
    cout << "\nv1 is empty: " << v1.empty() << endl;
    vector<int> v2(0);
    cout << "v2 is empty: " << v2.empty() << endl;

    // Element access
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    // This does not do bounds checking. Use at() for that
    // Eg-
    cout << "v[100] = " << v1[100] << endl;
    //cout << "v.at(100) = " << v1.at(100) << endl; Error
    cout << "v.at(0): " << v1.at(0) << endl;

    cout << "v1.front() = " << v1.front() << endl;
    cout << "v1.back() = " << v1.back() << endl;

    // Modifiers
    v2.assign(5, 10); // Assign value 10 5 times
    cout << "v2 = ";
    for (auto& e : v2)
        cout << e << " ";
    cout << endl;

    v1.pop_back(); // Remove the last element
    cout << "v1 = ";
    for (auto& e : v1)
        cout << e << " ";
    cout << endl;

    // Insert at position
    v1.insert(v1.begin() + 1, 10);
    cout << "v1 = ";
    for (auto& e : v1)
        cout << e << " ";
    cout << endl;

}