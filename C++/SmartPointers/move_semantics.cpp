#include <iostream>

template<class T>
class SmartPointer
{
    T* m_ptr;

public:
    SmartPointer(T* ptr=nullptr): m_ptr(ptr)
    {}

    ~SmartPointer()
    {
        delete m_ptr;
    }

    SmartPointer(SmartPointer& a)
    {
        m_ptr = a.m_ptr; // transfer our dumb pointer from the source to our
                        // local object
        a.m_ptr = nullptr; // make sure that the source no longer owns the
                            // pointer
    }

    SmartPointer& operator=(SmartPointer& a)
    {
        if (&a == this)
            return *this;

        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
    Resource() { std::cout << "Resource allocated.\n"; }
    ~Resource() { std::cout << "Resource destroyed.\n"; }
};

int main()
{
    SmartPointer<Resource> res1(new Resource());
    SmartPointer<Resource> res2;

    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

    res2 = res1;

    std::cout << "Ownership transferred\n";

    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
}
