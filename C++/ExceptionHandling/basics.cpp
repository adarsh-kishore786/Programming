#include <iostream>
#include <string>

int main()
{
    try
    {
        // Statements that can throw exceptions.
        // throw 5.4;
        // throw 0;
        throw "Hi!";
    }
    catch (int x)
    {
        std::cerr << "We caught an int exception of value " << x << "\n";
    }
    catch (double)
    {
        std::cerr << "We caught an exception of type double\n";
    }
    catch (const char* str)
    {
        std::cerr <<  "We caught an exception of type std::string of value " << str << "\n";
    }
    std::cout << "Continuing our merry journey!\n";

    return 0;
}
