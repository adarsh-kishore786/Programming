/*
	ball_height.cpp

	This program simuates a ball being 
	dropped from a building whose height
	is input by user. It gives the height 
	of ball after each second till it 
	reaches the ground.
*/

#include "constants.h"
#include <iostream>

double getHeight()
{
	std::cout << "Enter the height of the tower in metres: ";
	double height {};
	std::cin >> height;

	return height;
}

double getCurrentHeight(const double height, int time)
{
	double currentHeight { height - constants::g * time * time / 2 };
	return currentHeight;
}

void printHeight(const double height)
{
	double currHeight { height };

	int time { 0 };
	while (true)
	{
		currHeight = getCurrentHeight(height, time);

		if (currHeight > 0)
			std::cout << "At " << time << " seconds, the ball is at height: "
					  << currHeight << " meters\n";
		else
		{
			std::cout << "At " << time << " seconds, the ball is on the ground.\n";
			break;
		}
		time++;
	}
}

int main()
{
	double height { getHeight() };
	printHeight(height);
}