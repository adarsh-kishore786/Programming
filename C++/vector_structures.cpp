/*
	vector_structures.cpp

	This program explores the user defined
	data types by creating structures for 
	vectors.
*/

#include <iostream>
using namespace std;

struct Vector
{
	int sz;		  // No of elements
	double* elem; // Pointer to elements
};

void vector_init(Vector& v, int s)
{
	v.elem = new double[s]; // elem is now initialized to 
							// point to an array of doubles
	v.sz = s;
}

// reads s doubles from cin and returns their sum
double read_and_sum(int s) 
{
	Vector v;	
	vector_init(v, s);

	for (int i = 0; i < s; i++)
		cin >> v.elem[i];

	double sum = 0;

	for (int i = 0; i < s; i++)
		sum += v.elem[i];

	return sum;
}

int main()
{
	cout << read_and_sum(5);
}