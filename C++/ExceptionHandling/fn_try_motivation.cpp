#include <iostream>

class A
{
private:
    int m_x;

public:
    A(int x): m_x{x}
    {
        if (x <= 0)
            throw 1;
    }
};

class B: public A
{
public:
    B(int x): A{x}
    {
        // What if we wanted to handle the exception thrown by A
        // Can't use a regular try-catch as A is used in initializer
        // lists
    }
};

int main()
{
    try
    {
        B b{0};
    }
    catch (int)
    {
        std::cout << "Oops\n";
    }
    return 0;
}
