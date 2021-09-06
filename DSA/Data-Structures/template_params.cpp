/*
    template_params.cpp

    This program demonstrates template 
    functions and classes with a non-template
    parameter.
*/

#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
bool compare(T& x, T& y, bool greater)
{
    if (greater)
        return x > y;
    return x < y;
}

template <class T, int size>
class Array
{
private:
    T arr[size];

public:

    Array() {};

    friend ostream& operator<<(ostream& os, const Array& other)
    {
        for (auto e : other.arr)
            os << e << " ";
        return os;
    }

    T& operator[](int index)
    {
        assert(index >= 0 && index < size);
        return arr[index];
    }
};

int main()
{
    int x = 1, y = 2;
    cout << x << " > " << y << ": " << compare(x, y, true) << endl;
    cout << x << " < " << y << ": " << compare(x, y, false) << endl;

    double a = 5.6, b = -1.01;
    cout << a << " > " << b << ": " << compare(a, b, true) << endl;
    cout << a << " < " << b << ": " << compare(a, b, false) << endl; 

    Array<double, 5> arr; 
    arr[0] = 3.14159;
    arr[1] = 2.71828;
    arr[2] = 0.5;
    arr[3] = 9;
    arr[4] = 0;
    
    cout << arr << endl;

    return 0;
}