/*
	hex_to_binary.cpp

	Accepts a number in hex and converts to 
	binary.
*/

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string bin_(char);
int hex_to_dec(char);
string hex_to_bin(string);
string dec_to_bin(int);
string word(char);

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

int hex_to_dec(char hex)
{
	if (hex >= '0' && hex <= '9')
		return static_cast<int>(hex) - 48;

	return static_cast<int>(toupper(hex)) - 55;
}

string word(char hex)
{
	int n = hex_to_dec(hex);

	string s = "";
	if (n <= 1)
		s.append(" 000");
	else if (n <= 3)
		s.append(" 00");
	else if (n <= 7)
		s.append(" 0");
	else
		s.append(" ");
	s.append(dec_to_bin(n));	
	return s;
}

string hex_to_bin(string hex)
{
	if (static_cast<int>(hex.size()) == 1)
		return word(hex[0]);

	char end = *(hex.end() - 1);
	hex.pop_back();
	return hex_to_bin(hex) + word(end);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cout << "No arguments given to convert. Try again." << endl;
		return 1;
	}

	for (int i = 1; i < argc; i++)
		cout << argv[i] << ": " << hex_to_bin(argv[i]) << endl;

	return 0;
}