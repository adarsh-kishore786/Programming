/*
	polymorphism.cpp

	Demonstrates concept of polymorphism.
*/

#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string m_name {};
	int m_age;

public:
	Animal(string name, int age)
	{
		m_name = name;
		m_age = age;
	}	

	void animalSound()
	{
		cout << m_name << " makes its characteristic sound.\n";
	}
};

class Cow : public Animal
{
public:
	Cow(string name, int age) : Animal(name, age)
	{}
	
	void animalSound()
	{
		cout << m_name << " moos.\n";
	}
};

int main()
{
	Cow c {"Dora", 10};
	c.animalSound();
}