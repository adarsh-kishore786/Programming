/*
	hex_to_decimal.cpp

	This program accepts a hex number
	and converts it to decimal.
*/

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int intVal(char hex)
{
	if (hex >= '0' && hex <= '9')
		return static_cast<int>(hex) - 48;

	return static_cast<int>(toupper(hex)) - 55;
}

int hex_to_dec(string hex)
{
	if ((int)hex.size() == 1)
		return intVal(hex[0]); 
	
	
	char end = hex[hex.size() - 1];
	hex.pop_back();
 
	return 16 * hex_to_dec(hex) + intVal(end);
	return 0;
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cout << "No number entered for conversion. Try again." << endl;
		return 1;
	}

	for (int i = 1; i < argc; i++)
		cout << argv[i] << ": " << hex_to_dec(argv[i]) << endl;

	return 0;
}