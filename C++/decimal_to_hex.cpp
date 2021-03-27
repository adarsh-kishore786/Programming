/* 
	decimal_to_hex.cpp

	Takes a number converts to hex.
*/

#include <iostream>
#include <string>
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

void printHex(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		int n = stoi(argv[i]);
		cout << n << ": " << "0x" << dec_to_hex(n) << endl;
	}
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		printf("No numbers entered to be converted.\n");
		return 1;
	}

	printHex(argc, argv);
}