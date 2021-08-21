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
    B(int x) try: A{x}
    {
    }
    catch (int)
    {
        std::cerr << "Exception caught\n";
        // if an exception isn't thrown here, the current
        // exception is implicitly rethrown
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
