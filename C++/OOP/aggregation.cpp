#include <iostream>
#include <string>

class Teacher
{
private:
    std::string m_name {};

public:
    Teacher(const std::string& name)
    {
        m_name = name;
    }

    const std::string& getName() const
    {
        return m_name;
    }
};

class Department
{
private:
    const Teacher& m_teacher;

public:
    Department(const Teacher& teacher): m_teacher { teacher } {}
};

int main()
{
    // The existence of bob does NOT depend on 
    // the existence of the department, unlike 
    // in object composition
    Teacher bob{ "Bob" };

    {
        Department department { bob };
    }
    // Department goes out of scope here and is destroyed 
    // but Bob is still in scope

    std::cout << bob.getName() << " still exists.\n";

    return 0;
}