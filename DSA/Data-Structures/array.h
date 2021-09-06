/*
    array.h

    This program demonstrates the concept of 
    a template class.
*/

// This is an array of any data type. the vector class is implemented like this
#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>

template <class T>
class Array
{
private:
    int m_length{};
    T *m_data{};

public:
    Array(int length)
    {
        assert(length > 0);
        m_length = length;
        m_data = new T[m_length];
    }

    // Our data type is immutable
    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    ~Array()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    T& operator[](int index)
    {
        assert (index < m_length && index >= 0);
        return m_data[index];
    }

    int getLength() const;
};

template <class T>
int Array<T>::getLength() const
{
    return m_length;
} 

#endif