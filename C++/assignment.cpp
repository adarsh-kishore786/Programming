/*
	assignment.cpp

	This program showcases the {} way
	of assignment of operators, which is
	superior to the traditional = operator.
*/

#include <iostream>
#include <complex>
#include <vector>

int main()
{
	double d1 = 2.3; // Regular method
	double d2 {2.3}; // {} method
	std::complex<int> z1 = 1; // z1 = 1 + 0i
	std::complex<int> z2 {2, 3}; // z2 = 2 + 3i
	std::complex<double> z3 {5.67, 3.14159};
	std::vector<int> v {1, 2, 3, 4, 5, 6}; // A vector of ints

	int i1 = 7.2; // i1 becomes 7 without telling you
	//int i2 {7.2}; //Raises error
	double i2 {7.2};

	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << z1 << std::endl;
	std::cout << z2 << std::endl;
	std::cout << z3 << std::endl; 
	
	std::cout << "{ ";
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "}" << std::endl;

	std::cout << i1 << std::endl;
	std::cout << i2 << std::endl;
}