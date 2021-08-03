#include <iostream>

class Cents
{
private:
    int m_cents {};

public:
    Cents(int cents=0): m_cents {cents} {}

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }

    // overloaded int cast
    operator int() const { return m_cents; }
};

class Dollars
{
private:
    int m_dollars {};

public:
    Dollars(int dollars=0): m_dollars { dollars } {}

    operator Cents() const { return Cents{ m_dollars * 100 }; }
};

void printInt(int x)
{
    std::cout << x << std::endl;
}

void printCents(Cents cents)
{
    std::cout << cents << std::endl;
}

int main()
{
    Cents cents{7};
    printInt(cents);

    Dollars dollars{9};
    printCents(dollars);

    return 0;
}
