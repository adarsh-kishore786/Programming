/*
	pseudo_random_gen.cpp

	This program demonstrates how to write
	a pseudo random generator (PRNG).
*/

#include <iostream>

unsigned int PRNG()
{
	// seed
	static unsigned int seed { 5323 };
	// due to the use of large numbers and overflow
	// it is hard to predict the output
	seed = 825379 * seed + 2396403;

	return seed % 32768;
}

int main()
{
	for (int count = 1; count <= 100; count++)
	{
		std::cout << PRNG() << '\t';

		if (count % 5 == 0)
			std::cout << std::endl;
	}
}