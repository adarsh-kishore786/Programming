/*
	decimal_to_binary.cpp

	Accepts a number in decimal and prints
	its binary.
*/

#include <iostream>
#include <string>

using namespace std;

string bin_(int n)
{
	if (n == 0)
		return "0";
	return "1";
}

string dec_to_bin(int n)
{
	if (n < 2)
		return bin_(n);

	return dec_to_bin(n / 2) + bin_(n % 2);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cout << "No arguments given to convert. Try again." << endl;
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{

		cout << argv[i] << ": " << dec_to_bin(stoi(argv[i])) << endl;
	}

	return 0;
}