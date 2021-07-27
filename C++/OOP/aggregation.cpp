#include <iostream>
#include <string>
#include <vector>
#include <functional>

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
    std::vector<std::reference_wrapper<const Teacher>> m_teachers {};

public:
    void add(const Teacher& teacher)
    {
        m_teachers.push_back(teacher);
    }

    friend std::ostream& operator<<(std::ostream& os, const Department& dept)
    {
        os << "Department: ";
        for (const auto& e : dept.m_teachers)
            os << e.get().getName() << " ";
        return os;
    }
};

int main()
{
    // // The existence of bob does NOT depend on 
    // // the existence of the department, unlike 
    // // in object composition
    // Teacher bob{ "Bob" };

    // {
    //      Department dept {};
    //     // Department goes out of scope here and is destroyed 
    //     // but Bob is still in scope
    // }

    // std::cout << bob.getName() << " still exists.\n";

    Teacher t1{ "Bob" };
    Teacher t2{ "Frank" };
    Teacher t3{ "Beth" };

    {
        Department dept {};
        dept.add(t1);
        dept.add(t2);
        dept.add(t3);

        std::cout << dept << std::endl;
    }
    // Department goes out of scope here but teachers still exist.

    std::cout << t1.getName() << " exists!\n";
    std::cout << t2.getName() << " exists!\n";
    std::cout << t3.getName() << " exists!\n";

    return 0;
}