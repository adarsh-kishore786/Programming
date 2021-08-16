#include <iostream>

int main()
{
    try
    {
        throw 4.5;
        std::cout << "This never prints\n";
    }
    catch (double x)
    {
        std::cerr << "We caught a double of value: " << x << "\n";
    }

    return 0;
}
