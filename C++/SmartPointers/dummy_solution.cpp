#include <iostream>

template<class T>
class SmartPointer
{
    T* m_ptr;

public:
    SmartPointer(T* ptr=nullptr):
        m_ptr(ptr)
    {
        std::cout << "Pointer memory allocated.\n";
    }

    ~SmartPointer()
    {
        delete m_ptr;
        std::cout << "Pointer memory deallocated.\n";
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};

class Resource
{
public:
    void sayHi() { std::cout << "Hi!\n"; }
};

int main()
{
    SmartPointer<Resource> res(new Resource());

    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (x == 0)
        return 1;

    res->sayHi();
    // No explicit deletion

    // This program has a flaw, it doesn't provide a copy constructor
    // So the defualt copy cobnstructor provided does shallow copy due to
    // which pointer lives get linked actually.
    // SmartPointer<Resource> res2(res);
    return 0;
}
