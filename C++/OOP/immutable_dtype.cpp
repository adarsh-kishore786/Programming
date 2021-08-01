#include <iostream>

class Immutable
{
private:
    int m_val;

public:
    // Default constructor
    Immutable(int val): m_val{val} {}

    // Copy constructor is deleted, so it can't be used
    Immutable(const Immutable&) = delete;

    friend std::ostream& operator<<(std::ostream& out, const Immutable& imm);
};

std::ostream& operator<<(std::ostream& out, const Immutable& imm)
{
    out << imm.m_val;
    return out;
}

int main()
{
    Immutable i1(5);
    std::cout << i1 << "\n";

    // Immutable i2 = i1; // Error
    // std::cout << i2 << "\n";
}
