/*
    merge_sort.cpp

    This program sorts an array using
    merge sort.
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

using vec = vector<int>;

// For printing the vector
ostream& operator<<(ostream& os, vec v)
{
    for (auto& e : v)
        cout << e << " ";
    return os;
}

vec input()
{
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vec v(n);
    for (auto& e : v)
    {
        cout << "Enter a value: ";
        cin >> e;
    }

    return v;
}

vec merge_(vec v1, vec v2)
{
    int s1 = v1.size();
    int s2 = v2.size();

    vec v(s1 + s2);
    int i = 0, j = 0;

    // Insert near INFINTY at the end
    v1.push_back(numeric_limits<int>::max()); 
    v2.push_back(numeric_limits<int>::max());

    for (int k = 0; k < v.size(); k++)
    {
        if (v1[i] < v2[j])
            v[k] = v1[i++];
        else
            v[k] = v2[j++];
    }
    return v;
}

vec mergeSort(vec& v)
{
    int l = v.size();
    int mid = (l + 1) / 2;

    vec v1 {};
    vec v2 {};

    for (int i = 0; i < l; i++)
    {
        if (i < mid)
            v1.push_back(v[i]);
        else
            v2.push_back(v[i]);
    }
    //cout << "v1 = " << v1 << "\nv2 = " << v2 << endl;
    if (v1.size() != 1)
        v1 = mergeSort(v1);
    if (v2.size() != 1)
        v2 = mergeSort(v2);
    
    return merge_(v1, v2);
}

int main()
{
    vec v = input();
    cout << v << endl;
    cout << mergeSort(v) << endl; 
}