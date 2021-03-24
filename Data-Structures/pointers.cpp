/*
	pointers.cpp

	Demonstrates pointers.
	(Only some new stuff)
*/

#include <iostream>
using namespace std;

int main()
{
	int i;
	int* p = &i;

	// Garbage value
	cout << "i = " << i << endl;
	cout << "p = &i = " << p << endl;
	cout << "*p = " << *p << endl << endl;

	i = 10;
	cout << "i = " << i << endl;
	cout << "p = &i = " << p << endl;
	cout << "*p = " << *p << endl << endl;

	int *q; // Dangling pointer
	cout << "q = " << q << endl;
	cout << "*q = " << *q << endl << endl; //Garbage

	int *r = nullptr;
	cout << "r = " << r << endl;
	cout << "*r = " << *r << endl; //Segmentation fault
}