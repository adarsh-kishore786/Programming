#include <cmath>
#include <iostream>

double sqrt_(double x)
{
    if (x < 0)
        throw "Cannot take square root of negative number";
    return sqrt(x);
}

int main()
{
    std::cout << "Enter a number: ";
    double x;
    std::cin >> x;

    try
    {
        double d = sqrt_(x);
        std::cout << "The square root of " << x << " is " << d << "\n";
    }
    catch (const char* exception)
    {
        std::cerr << "Error: " << exception << "\n";
    }

    return 0;
}
