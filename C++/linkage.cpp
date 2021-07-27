/*
	linkage.cpp

	This program demonstrates the concept
	of internal and external linkages.
*/

#include <iostream>

static int g_x { 10 }; // non constant-global variable made internal using static
const int g_y { 1 }; // const var have internal linkage by default
constexpr int g_z { 2 }; // constexpr var have internal linkage by default
 
// This function now declared static. Attempts to access it
// in another file using forward declaration will fail
static int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y); //Forward declaration
extern int x; // we have to mention that x is from outside
			  // variable forward declaration
extern int y;
extern int z;

int main()
{
	std::cout << g_x << std::endl;
	std::cout << g_y << std::endl;
	std::cout << g_z << std::endl;
	std::cout << add(g_x, g_y) << std::endl;
	std::cout << subtract(g_x, g_y) << std::endl;
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
	std::cout << "z = " << z << std::endl;
}