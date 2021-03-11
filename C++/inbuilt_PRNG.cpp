/*
	inbuilt_PRNG.cpp

	This program demonstrates the inbuilt 
	PRNG that C++ has.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	int seed { 5323 };
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed initialization
	std::rand(); // For "better" results

	for (int count = 1; count <= 100; count++)
	{
		std::cout << std::rand() << "\t";

		if (count % 5 == 0)
			std::cout << std::endl;
	}

	// If the seed is same, all random numbers generated
	// will be same, thus we take seed variable as system
	// clock, something changing
}