#ifndef INTARRAY_H
#define INTARRAY_H 

#include <cassert>
#include <iostream>

class IntArray
{
private:
    int m_length {};
    int *m_data {};

public:
    IntArray() = default;

    IntArray(int length): m_length { length } 
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length]{};
    } 

    ~IntArray()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }

    // reallocate() will destroy any previous elements stored in
    // the array
    void reallocate(int newLength)
    {
        erase();

        if (newLength <= 0)
            return;

        m_data = new int[newLength];
        m_length = newLength;
    }

    void resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0) 
        {
            erase();
            return;
        }

        int *data { new int[newLength] };

        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

            for (int i = 0; i < elementsToCopy; i++)
                data[i] = m_data[i];
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        int *data { new int[m_length + 1] };

        for (int i = 0; i < index; i++)
            data[i] = m_data[i];
        
        data[index] = value;

        for (int i = index + 1; i <= m_length; i++)
            data[i] = m_data[i - 1];
        
        delete[] m_data;

        m_data = data;
        m_length++;
    }

    void remove(int index)
    {
        assert(index >= 0 && index < m_length);

        if (m_length == 1)
        {
            erase();
            return;
        }

        int *data { new int[m_length - 1] };

        for (int i = 0; i < index; i++)
            data[i] = m_data[i];
        
        for (int i = index + 1; i < m_length; i++)
            data[i - 1] = m_data[i];

        delete[] m_data;

        m_data = data;
        m_length--;
    }

    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }

    friend std::ostream& operator<<(std::ostream& os, const IntArray& arr)
    {
        for (int i = 0; i < arr.m_length; i++)
            os << arr.m_data[i] << " ";
        os << "\n";
        return os;
    }   
};  
#endif