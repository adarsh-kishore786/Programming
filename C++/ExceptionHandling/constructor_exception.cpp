#include <iostream>

class Member
{
public:
    Member()
    {
        std::cout << "Member allocated some resources.\n";
    }

    ~Member()
    {
        std::cout << "Member cleaned up.\n";
    }
};

class A
{
private:
    int m_x;
    Member m_member;

public:
    A(int x): m_x{x}
    {
        if (x <= 0)
            throw 1;
    }

    ~A()
    {
        std::cout << "~A()\n";
    }
};

int main()
{
    try
    {
        A a{0};
    }
    catch (int)
    {
        std::cerr << "Oops\n";
    }
    return 0;
}
