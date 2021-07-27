/*
	ellipses.cpp

	This program demonstrates the use of
	ellipses.
*/

#include <iostream>
#include <cstdarg> // for ellipses

// The ellipses must be the last parameter
// count is how many additional parameters we are passing
double findAverage(int count, ...)
{
	double sum { 0 };

	// We access the ellipses through a va_list 
	va_list list; // va = Variable args

	// initialize through va_start. the first parameter is
	// the list to initialize, last parameter is the last
	// non-ellipsis argument.
	va_start(list, count);

	for (int arg = 0; arg < count; arg++)
		sum += va_arg(list, int);
	// Use va_arg
	// First param is list
	// Second param is data type

	// At last clean up the list
	va_end(list);

	return 1.0 * sum / count;
}

int main()
{
	std::cout << findAverage(2, 1, 2) << "\n";
	std::cout << findAverage(5, 6, -6, -5, 4, 3) << "\n";
}