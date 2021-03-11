/*
	enumerations.cpp

	This program introduces concept of 
	enums.
*/

#include <iostream>

enum Color
{
	color_black,
	color_red,
	color_blue,
	color_green,
	color_white,
	color_cyan,
	color_yellow,
	color_magenta,
};

int main()
{
	auto paint { Color::color_white };
	auto house { Color::color_blue };
	auto apple { Color::color_red };

	std::cout << paint << std::endl;
	std::cout << house << std::endl;
	std::cout << apple << std::endl;
}