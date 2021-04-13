/*
	this_pointer.cpp

	Shows the "this" pointer of classes.
*/

#include <iostream>
using namespace std;

class Calculator
{
private:
	int value;

public:
	Calculator(int value=0)  
	{
		this->value = value;
	}

	Calculator& add(int val) 
	{
		value += val;
		return *this;
	}

	Calculator& sub(int val)
	{
		value -= val;
		return *this;
	}

	Calculator& mul(int val)
	{
		value *= val;
		return *this;
	}

	int getValue()
	{
		return value;
	}
};

int main()
{
	Calculator calc { 7 };
	calc.add(3).mul(10).sub(2); // ((7 + 3) * 10) - 2 = 98
	cout << "Final value: " << calc.getValue() << endl;
}