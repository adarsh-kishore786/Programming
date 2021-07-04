#include <iostream>
#include <string>

class Base
{
protected:
    int m_value;

public:
    Base(int value): m_value {value} 
    {}

    const std::string getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value) : Base(value) {}

    const std::string getName() const { return "Derived"; }
    int getValueDoubled() const { return m_value * 2; } 
};

int main()
{
    // This is the obvious part
    Derived derived { 5 };
    std::cout << "derived is a " << derived.getName() << " and has value "
        << derived.getValue() << "\n";
    
    Derived &rDerived { derived };
    std::cout << "rDerived is a " << rDerived.getName() << " and has value "
        << rDerived.getValue() << "\n";

    Derived *pDerived { &derived };
    std::cout << "pDerived is a " << pDerived->getName() << " and has value "
        << pDerived->getValue() << "\n\n";

    // This is non-obvious but legal
    Base &rBase { derived };
    Base *pBase { &derived };

    std::cout << "rBase is a " << rBase.getName() << " and has value " <<
        rBase.getValue() << "\n";
    std::cout << "pBase is a " << pBase->getName() << " and has value " <<
        pBase->getValue() << "\n\n";

    // rBase and pBase, though references to Derived, can only see members
    // of Base class. They cannot see Derived::getName() so they report their 
    // name as Base::getName(). Also, they cannot see the Derived::getValueDoubled()
    // function. For them, the functions of derived are 'virtual functions'.
}