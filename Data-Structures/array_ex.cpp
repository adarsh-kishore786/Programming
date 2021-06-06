/*
    array_ex.cpp

    This program uses the array.h template to create 
    an array of variable of variable data type.
*/

#include <iostream>
#include "array.h"
using namespace std;

int main()
{
    Array<int> intArray(12);
    Array<double> doubleArray(12);

    for (int i = 0; i < 12; i++)
    {
        intArray[i] = i;
        doubleArray[i] = i + 0.5;
    }

    for (int i = 0; i < 12; i++)
        cout << intArray[i] << "\t" << doubleArray[i] << "\n";
    
    return 0;
}