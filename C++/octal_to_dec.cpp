/*
	octal_to_dec.cpp

	Accepts octal numbers and converts
	to decimal.
*/

#include <iostream>
#include <string>
using namespace std;

int oct_to_dec(string oct)
{
	if ((int)oct.size() == 1)
		return stoi(oct);

	char end = *(oct.end() - 1);
	oct.pop_back();
	return 8 * oct_to_dec(oct) + ((int)end - 48);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		cout << "No numbers entered. Try again.\n";
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		string oct = argv[i];
		cout << oct << ": " << oct_to_dec(oct) << endl;
	}

	return 0;
}