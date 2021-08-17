#include <iostream>

int main()
{
    try
    {
        throw 5;
    }
    catch (double x)
    {
        std::cerr << "Double exception caught of value: " << x << "\n";
    }
    catch (...)
    {
        std::cerr << "Exception caught of undetermined type\n";
    }

    return 0;
}
