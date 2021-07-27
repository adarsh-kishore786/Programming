/*
	binary_to_hex.cpp

	Accepts numbers in binary and converts 
	them to hex.
*/

#include <iostream>
#include <algorithm>
using namespace std;

string std_values(int x)
{
	if (x >= 0 && x <= 9)
		return to_string(x);

	switch (x)
	{
		case 10: return "A";
		case 11: return "B";
		case 12: return "C";
		case 13: return "D";
		case 14: return "E";
		case 15: return "F"; 
	}

	return "?"; // Should never happen
}

string dec_to_hex(int n)
{
	if (n >= 0 && n <= 15)
		return std_values(n);

	return dec_to_hex(n / 16) + std_values(n % 16);
}

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

string bin_to_hex(string bin_)
{
	int n = bin_to_dec(bin_);
	return dec_to_hex(n);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cout << "No numbers given. Try again." << endl;
		return 1;
	}

	for (int i = 1; i < argc; i++)
		cout << argv[i] << ": 0x" << bin_to_hex(argv[i]) << endl;
}