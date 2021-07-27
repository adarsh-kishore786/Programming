/*
    container_class.cpp

    This program demonstrates the use of the custom made
    IntArray class. This shows use of container classes
    in C++.
*/

#include <iostream>
#include "IntArray.h"

int main()
{
    IntArray array(10);

    for (int i = 0; i < 10; i++)
        array[i] = i + 1;
    
    std::cout << "Array: " << array;

    array.resize(8);
    std::cout << "Array: " << array;    

    array.insertBefore(20, 5);
    std::cout << "Array: " << array;

    array.remove(3);
    std::cout << "Array: " << array;

    array.insertAtEnd(30);
    array.insertAtBeginning(40);
    std::cout << "Array: " << array;
}