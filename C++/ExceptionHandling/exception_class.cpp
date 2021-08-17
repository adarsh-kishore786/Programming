#include <iostream>
#include <string>

class ArrayException
{
private:
    std::string m_error;

public:
    ArrayException(std::string error):
        m_error{error} {}

    const char* getError() const { return m_error.c_str(); }
};

class IntArray
{
private:
    int m_data[3];

public:
    IntArray() {}

    int getLength() const { return 3; }

    int& operator[](const int index)
    {
        if (index < 0 || index >= getLength())
            throw ArrayException("Invalid Index");

        return m_data[index];
    }
};

int main()
{
    IntArray array;

    try
    {
        int value{ array[5] };
    }
    catch (const ArrayException &exception)
    {
        std::cerr << "An array exception occured (" << exception.getError() << ")\n";
    }

    return 0;
}
