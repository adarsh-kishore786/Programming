/*
	binary_to_hex.cpp

	Accepts numbers in binary and converts 
	them to decimal.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int intVal(char b)
{
	if (b == '0')
		return 0;
	return 1;
}

int bin_to_dec(string bin_)
{
	if ((int)bin_.size() == 1)
		return intVal(bin_[0]); 
	
	char end = *(bin_.end() - 1);
	bin_.pop_back();
 
	return 2 * bin_to_dec(bin_) + intVal(end);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cout << "No numbers given. Try again." << endl;
		return 1;
	}

	for (int i = 1; i < argc; i++)
		cout << argv[i] << ": " << bin_to_dec(argv[i]) << endl;
}