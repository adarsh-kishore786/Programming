/*
	bit_manipulation.cpp

	This program introduces techniques 
	for bit manipulation.
*/

#include <bitset>
#include <iostream>

int main()
{
	std::bitset<12> bits { 0b0000'0101'1111 }; // bits = 0000 0101 1111
	std::cout << bits << std::endl;

	bits.set(3); // bit position 3 is set to 1, which it already is
	std::cout << bits << std::endl;

	bits.set(7); // bit position 7 is set to 1
	std::cout << bits << std::endl;

	bits.flip(1); // bit 1 is flipped to complement
	std::cout << bits << std::endl;

	bits.reset(0); // bit 0 is reset to 0
	std::cout << bits << std::endl;
}