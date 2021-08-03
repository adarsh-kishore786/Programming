#include <iostream>
#include <cassert>

class IntArray
{
private:
    int *m_array { nullptr };
    int m_size {};

public:
    IntArray(int size)
    {
        assert (size > 0 && "IntArray length should be a positive integer");
        m_size = size;
        m_array = new int[m_size]{};
    }

    // Copy Constructor
    IntArray(const IntArray& ia)
    {
        this.m_size = ia.m_size;
        m_array = new int[m_size]{};

        for (int i = 0; i < m_size; i++)
            m_array[i] = ia.m_array[i];
    }

    ~IntArray()
    {
        delete[] m_array;
    }

    int& operator[](const int i)
    {
        assert (i >= 0 && i < m_size);
        return *(m_array + i);
    }

    friend std::ostream& operator<<(std::ostream& os, const IntArray& ia);

    IntArray& operator= (const IntArray& array)
	{
		// self-assignment guard
		if (this == &array)
			return *this;

		// If this array already exists, delete it so we don't leak memory
		delete[] m_array;

		m_length = array.m_length;

		// Allocate a new array
		m_array = new int[m_length];

		// Copy elements from original array to new array
		for (int count{ 0 }; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];

		return *this;
	}
};

std::ostream& operator<<(std::ostream& os, const IntArray& ia)
{
    for (int i = 0; i < ia.m_size; i++)
        std::cout << *(ia.m_array + i) << " ";
    return os;
}

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };
	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	std::cout << b << '\n';

	return 0;
}
