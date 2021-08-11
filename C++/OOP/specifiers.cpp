#include <iostream>
#include <string_view>

class A
{
public:
    virtual std::string_view getName1(int x) { return "A"; }
    virtual std::string_view getName2(int x) { return "A"; }

    virtual std::string_view getName(int x) final { return "A"; }
};

class B : public A
{
public:
    // virtual std::string_view getName1(short int x) override { return "B"; }
       // Compiler error signatures don't match
    // virtual std::string_view getName2(int x) const override { return "B"; }
       // Compiler error signatures don't match
    // std::string_view getName(int x) override { return "B"}; // Error, final

    std::string_view getName1(int x) override { return "B"; }
};

class Base
{
public:
    // This version of getThis() returns a pointer to a Base class
    virtual Base* getThis()
    {
        std::cout << "called Base::getThis()\n";
        return this;
    }

    void printType() { std::cout << "returned a Base\n"; }
};

class Derived : public Base
{
public:
    // Covariant return types are allowed
    Derived* getThis() override
    {
        std::cout << "called Derived::getThis()\n";
        return this;
    }

    void printType() { std::cout << "returned a Derived\n"; }
};

int main()
{
    // B b{};
    // A& rBase{ b };
    // std::cout << rBase.getName1(1) << "\n";
    // std::cout << rBase.getName2(2) << "\n";
    // std::cout << rBase.getName(3) << "\n";

    Derived d{};
    Base* b{ &d };
    d.getThis()->printType();
    b->getThis()->printType();

    return 0;
}
