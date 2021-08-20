#include <iostream>

class Base
{
public:
    Base() {}
    virtual void print() { std::cout << "Base"; }
};

class Derived: public Base
{
public:
    Derived() {}
    void print() override { std::cout << "Derived"; }
};

int main()
{
    try
    {
        try
        {
            throw Derived{};
        }
        catch (Base& b)
        {
            std::cout << "Caught Base b, which is actually a ";
            b.print();
            std::cout << "\n";
            // throw b; // this will cause slicing
            throw; //this will be fine as the exact object reference as before
                    // is thrown
        }
    }
    catch (Base& b)
    {
        // On rethowing the base reference to a derived to a function which
        // takes Base, the object is effectively sliced
        std::cout << "Caught Base b, which is actually a ";
        b.print();
        std::cout << "\n";
    }
    return 0;
}
