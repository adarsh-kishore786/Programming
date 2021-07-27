/*
	constant.cpp

	This program shows the use of 
	the const and constexpr keywords.
*/

#include <iostream>
#include <vector>

double sum(const std::vector<double> &vector)
{
	double sum = 0;
	for (int i = 0; i < vector.size(); i++)
		sum += vector[i];
	return sum;
}

void print_vector(const std::vector<double> &vector)
{
	for (int i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}

constexpr double square(double x)
{
	return x * x;
}

int main()
{
	const int dmv {17}; // dmv can't be changed
	int var {17};

	constexpr double max1 {1.4 * square(dmv)};
	//constexpr double max2 {1.4 * square(var)}; // error: var is not constant
	const double max3 = 1.4 * square(var);
	std::vector<double> v {1.2, 3.4, 4.5};

	print_vector(v);

	const double s1 = sum(v);
	//constexpr double2 = sum(v); //error: v is not constant
	print_vector(v);
	std::cout << s1 << std::endl; 

}