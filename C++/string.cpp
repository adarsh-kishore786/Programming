/*
	string.cpp

	This program introduces the concept 
	of a string.
*/

#include <iostream>
#include <string>
#include <limits>

int main()
{
	std::string hello { "Hello World" };
	std::cout << hello << "!" << std::endl;

	std::string str1 { "Ash" };
	std::string str2 { "Ketchum" };

	std::cout << str1 + " " + str2 << std::endl; // Both + and .append() concatenate
	std::cout << str1.append(" ").append(str2) << std::endl; 

	// But strings do not get expected input using cin
	// As cin breaks at first non-leading whitespace
	std::cout << "Enter your name: ";
	std::string name {};
	std::cin >> name;

	std::cout << "Enter your age: ";
	std::string age {};
	std::cin >> age;

	std::cout << "Your name is " << name << " and your age is " << age << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Instead we should use std::getline() which stops at only \n
	std::cout << "Enter your full name: ";
	std::getline(std::cin, name);

	std::cout << "Enter your age: ";
	std::getline(std::cin, age);

	std::cout << "Your name is " << name << " and your age is " << age << std::endl;
	std::cout << "The length of your name is: " << name.length() << std::endl;
	std::cout << "You have lived " << static_cast<double>(std::stoi(age)) / name.length() 
			  << " years for each letter of your name." << std::endl; 	
}