/*
	id_gen.cpp

	This progam generates IDs using 
	static member variables and functions.
*/

#include <iostream>
using namespace std;

class IDGenerator
{
private:
	static int s_nextID;

public:
	static int getNextID();
};

int IDGenerator::s_nextID { 1 };

int IDGenerator::getNextID() { return s_nextID++; }

int main()
{
	for (int i = 0; i <= 5; i++)
		cout << "The next ID is " << IDGenerator::getNextID() << endl;

	return 0;
}