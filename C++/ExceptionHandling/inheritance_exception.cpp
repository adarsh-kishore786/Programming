#include <iostream>

class Base
{
public:
    Base() {}
};

class Derived: public Base
{
public:
    Derived() {}
};

int main()
{
    // this will say "Caught a Base" because Derived-is-a-Base
    try
    {
        throw Derived();
    }
    catch (const Base &base)
    {
        std::cerr << "Caught a Base\n";
    }
    catch (const Derived &derived)
    {
        std::cerr << "Caught a Derived\n";
    }

    // this will say "Caught a Derived" because order is switched now
    try
    {
        throw Derived();
    }
    catch (const Derived &derived)
    {
        std::cerr << "Caught a Derived\n";
    }
    catch (const Base &base)
    {
        std::cerr << "Caught a Base\n";
    }
}
