/*
	Vector.cpp

	This program introduces the notion of
	a class through a vector class.
*/
#include <iostream>
using namespace std;

class Vector
{
private:
	double *elem;
	int sz;

public:
	Vector(int s)
	{
		elem = new double[s];
		sz = s;
	}

	double& operator[](int i) // subscripting operator
	{
		return elem[i];
	}

	int size()
	{
		return sz;
	}
};

double read_and_sum(int s)
{
	Vector v(s);

	cout << "Enter " << s << " elements:\n";
	for (int i = 0; i < v.size(); i++)
		cin >> v[i];

	double sum = 0; 
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		v[i]= 0;
	}
	cout << "All elements have contributed. Current vector:\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	return sum;
}

int main()
{
	cout << "What length of vector you would like? ";
	int length;
	cin >> length;
	cout << read_and_sum(length);


}