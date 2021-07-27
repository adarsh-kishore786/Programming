/*
	range_for_loop.c

	This program explores the range_for_loop
	in C++, which is similar to the for loop
	in Python.
*/

#include <iostream>
#include <vector>
#include <complex>

void print_vector(std::vector<int> &v)
{
	for (auto x : v)
		std::cout << x << " ";
	std::cout << std::endl;
}

void print_vector(std::vector<std::complex<double>> &zv)
{
	for (auto z : zv)
		std::cout << z << " ";
	std::cout << std::endl;
}

void print_matrix(std::vector<std::vector<double>> &m)
{
	std::cout << "\nMatrix:" << std::endl; 
	for (auto v : m)
	{
		for (auto x : v)
			std::cout << x << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	int v[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	for (auto x : v)
		std::cout << x << " ";
	std::cout << std::endl;

	std::vector<int> ve {4, 7, 10, 4};
	print_vector(ve);

	char name[] = "Hello, I'm C++";

	for (auto x : name)
		std::cout << x;
	std::cout << std::endl;

	std::vector<std::complex<double>> z {{1.7, 2.718}, {3.14, 4.6}}; 
	print_vector(z);

	std::vector<std::vector<double>> matrix = 
		{
			{1.5, 5.3, 8.6, 4.5},
			{3.2, 5.5, 2.2, 0.9, 7.8},
			{7.8, 9.2, -3.5}
		};

	print_matrix(matrix);

	std::cout << "Passing by value (original not modified): " << std::endl;
	for (auto x : v)
	{
		x++;
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::cout << "Original: " << std::endl;
	for (auto x : v)
		std::cout << x << " ";
	std::cout << std::endl;

	std::cout << "Passing by reference (original modified): " << std::endl;
	for (auto& x : v)
	{
		x++;
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::cout << "Original: " << std::endl;
	for (auto x : v)
		std::cout << x << " ";
	std::cout << std::endl;
}