#include <iostream>
#include <string>

class Base
{
protected:
    int a {};
public:
    Base(int val): a{ val } {}

    virtual void print()
    {
        std::cout << "I'm a Base of value " << getVal() << "\n";
    }

    virtual int getVal() const final { return a; }
    virtual const std::string getName() const { return "Base"; }
};

class Derived: public Base
{
public:
    Derived(int val): Base(val)
    {
        a *= 2;
    }

    void print() override
    {
        std::cout << "I'm a Derived of value " << getVal() << "\n";
    }

    const std::string getName() const override { return "Derived"; }
};

// Should keep a reference to prevent slicing
// void printChange(const Base base)
// {
//     int v { base.getVal() };
//     std::cout << "Value of " << base.getName() << " is " << v + 5 << "\n";
// }

void printChange(const Base& base)
{
    int v { base.getVal() };
    std::cout << "Value of " << base.getName() << " is " << v + 5 << "\n";
}

int main()
{
    Base b{5};
    Derived d{8};

    b.print();
    d.print();

    Base &d1{ d };
    d1.print(); // Will be derived

    d1 = b;
    d1.print(); // Frankenobject, has value 5 (base value) but message of derived
    std::cout << "\n";
    printChange(b);
    printChange(Derived{8});
}
