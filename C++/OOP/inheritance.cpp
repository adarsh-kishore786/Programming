// We'll be using this often enough for demo
#include <iostream>

class Base
{
public:
	int m_id;

	Base(int id = 0): m_id { id } {}
	
	int getId() const { return m_id; }
};

class Derived: public Base
{
public:
	double m_cost;

	Derived(double cost = 0.0) : 
		m_cost { cost } {}

	// Overloaded constructor for initializing parent
	Derived(double cost = 0.0, int id=0): 
		Base{ id }, m_cost { cost }
	{} 

	double getCost() const { return m_cost; }
};

int main()
{
	Derived derived{ 1.3, 5 };
	std::cout << "Id: " << derived.getId() << "\n";
	std::cout << "Cost: " << derived.getCost() << "\n";

	return 0;
}