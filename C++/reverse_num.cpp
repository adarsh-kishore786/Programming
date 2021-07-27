/*
	reverse_num.cpp

	Enter n nums and reverse them.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string reverse_(string num)
{
	return reverse(num.begin(), num.end());
}

int main()
{
	int n {};
	cin >> n;
	vector<string> r_nums {};

	for (int i = 0; i < n; i++)
	{
		string num {};
		cin >> num;
		r_nums.push_back(reverse_(num));
	}

	for (auto& e : r_nums)
		cout << e << endl;
}