/*
	rgba.cpp

	This program defines a class RGBA using 
	constructor member initialization. Then calls 
	it.
*/

#include <iostream>
#include <cstdint>

using uint8 = std::uint_fast8_t;

class RGBA
{
private:
	uint8 m_red;
	uint8 m_green;
	uint8 m_blue;
	uint8 m_alpha;

public:
	RGBA(uint8 red = 0, uint8 green = 0, uint8 blue = 0, uint8 alpha = 255):
			m_red { red },
			m_green { green },
			m_blue { blue },
			m_alpha { alpha }
	{}

	void print()
	{
		std::cout << "r = " << (int)m_red << " ";
		std::cout << "b = " << (int)m_green << " ";
		std::cout << "g = " << (int)m_blue << " ";
		std::cout << "a = " << (int)m_alpha << "\n";
	} 
};

int main()
{
	RGBA teal { 0, 127, 127 };
	teal.print();

	return 0;
}