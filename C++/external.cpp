static int g_x { 2 }; // This is an internal variable, not recognized by 
					  // linkage.cpp


#include <iostream>
 
int x { 2 }; // non-const variables are global by default
extern const int y { 3 }; // const variables can be made global by 
						  // extern keyword
extern constexpr int z { y }; // Similar for constexpr 
// Error
//int add(int x, int y);

/*int main()
{
	std::cout << add(2, 3) << std::endl;
}*/

// Functions have external linkages by default
int subtract(int x, int y)
{
	return x - y;
}