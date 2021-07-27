/*
	overloading_array.cpp
*/

#include <iostream>
#include <cassert>

class IntArray
{
private:
	int m_array[];
	int m_size;

public:
	IntArray(int size)
	{
		m_size = size;
		m_array = new int[m_size];
	}

	IntArray(const IntArray& array)
	{
		m_size = array.m_size;
		m_array = new int[m_size];
		for (int i = 0; i < m_size; i++)
			m_array[i] = array.m_array[i];
	}

	~IntArray()
	{
		m_size = 0;
		delete[] m_array;
	}

	friend int& operator[](IntArray& array, int index)
	{
		assert (index >= 0 && index < array.m_size);
		return array.m_array[index];
	}
};

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
	IntArray a { fillArray() };
}