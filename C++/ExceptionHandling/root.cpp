#include "math.h"
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    double x {};
    std::cin >> x;

    try
    {
        if (x < 0.0)
            throw "Cannot take square root of negative number";

        std::cout << "Square root of " << x << " is " << sqrt(x) << "\n";
    }
    catch (const char* exception)
    {
        std::cerr << "Error: " << exception << "\n";  
    }
}
