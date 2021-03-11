/*
	enum_classes.cpp

	This progeam demonstrates the use
	of enum classes, and their necessity.
*/

#include <iostream>

namespace v1
{
	void run()
	{
		enum Color
		{
			color_red,
			color_blue
		};

		enum Fruit
		{
			fruit_banana,
			fruit_apple
		};

		Color color { color_red };
		Fruit fruit { fruit_banana };

		if (color == 0)
			std::cout << "color is the first element of enum Color.\n";
		if (fruit == 0)
			std::cout << "fruit is the first element of enum Fruit.\n";

		/*if (color == fruit)
			std::cout << "Color equals Fruit\n"; // Definitely not what we want!
		else
			std::cout << "Color does not equal Fruit\n";*/
	}
	// That's why we need enum classes
}

inline namespace v2
{
	void run()
	{
		enum class Color
		{
			color_red,
			color_blue
		};

		enum class Fruit
		{
			fruit_banana,
			fruit_apple
		};
		// The compiler does not convert enum classes implicitly to integers

		Color color { Color::color_red }; // Now it must be accessed by its namespace
		Fruit fruit { Fruit::fruit_banana };

		std::cout << static_cast<int>(color) << std::endl;

		/*if (color == 0) // Compile error comparision between enum class and integer
			std::cout << "color is the first element of enum Color.\n";
		if (fruit == 0)
			std::cout << "fruit is the first element of enum Fruit.\n";

		if (color == fruit) // Compile error
			std::cout << "Color equals Fruit\n"; // Definitely not what we want!
		else
			std::cout << "Color does not equal Fruit\n";
	}*/
	}
}

int main()
{
	run();
}