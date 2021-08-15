#include <iostream>
#include <string>

class Base
{
protected:
    int m_val {};

public:
    Base(int val): m_val{ val } {}

    friend std::ostream& operator<<(std::ostream& os, const Base& b)
    {
        return b.print(os);
    }

    virtual std::ostream& print(std::ostream& os) const
    {
        os << "This is a Base of value " << m_val;
        return os;
    }

    virtual const std::string getName() const { return "Base"; }
    virtual const int getValue() const final { return m_val; }
};

class Derived : public Base
{
public:
    Derived(int val): Base(val)
    {
        m_val *= val;
    }

    std::ostream& print(std::ostream& os) const override
    {
        os << "This is a Derived of value " << m_val;
        return os;
    }

    virtual const std::string getName() const override { return "Derived"; }
};

int main()
{
    Base b{7};
    std::cout << b << "\n";

    Derived d{5};
    std::cout << d << "\n";

    Base &b1 { d };
    std::cout << b1 << "\n";
}
