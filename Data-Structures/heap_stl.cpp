/*
    heap_stl.cpp

    This program demonstrates the heap data 
    structure in C++ STL. Retrieval from a heap 
    always results in the largest value in the 
    heap.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1 = { 20, 30, 40, 25, 15 };

    make_heap(v1.begin(), v1.end());

    cout << "The maximum element in the heap is: " << v1.front() << endl;

    v1.push_back(50); 
    // Now reorder
    push_heap(v1.begin(), v1.end());
    cout << "The maximum element in the heap after push is: " << v1.front() << endl;

    pop_heap(v1.begin(), v1.end());
    v1.pop_back();
    cout << "The maximum element after popping: " << v1.front() << endl;
    
    cout << "Container is heap: " << is_heap(v1.begin(), v1.end()) << endl;
    // After sorting it is not a heap
    sort_heap(v1.begin(), v1.end());

    cout << "Heap elements are: ";
    for (auto& e : v1)
        cout << e << " ";
    cout << endl;
    cout << "Container is heap: " << is_heap(v1.begin(), v1.end()) << endl;
}