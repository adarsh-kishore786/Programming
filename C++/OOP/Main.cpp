#include <string>
#include <iostream>
#include "Creature.h"
#include "Point2D.h"

int main()
{
    std::cout << "Enter name for your creature: ";
    std::string name {};
    std::cin >> name;
    Creature creature { name, {4, 7} };

    while (true)
    {
        // print name and location
        std::cout << creature << std::endl;

        std::cout << "Enter new X location for creature (-1 to quit): ";
        int x {};
        std::cin >> x;
        if (x == -1) 
            break;

        std::cout << "Enter new Y location for creature (-1 to quit): ";
        int y {};
        std::cin >> y;
        if (y == -1) 
            break;

        creature.moveTo(x, y);
    }

    return 0;
}