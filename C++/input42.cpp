/* input42.cpp

   This program takes in input of
   integers from the user and prints
   the numbers with digits of 1 or 2.
   It stops processing after user has
   entered 42.

   Author: Adarsh
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int nd(int n)
{
	int p = 0;
	while (n != 0)
	{
		p++;
		n /= 10;
	}

	return (p == 0) ? 1 : p; 
	// Suppose n = 0. Then p = 0 from above code but 0 is
	// 1 digit number
}

int main()
{
	int length = 1;
	int *numbers = (int*)malloc(length * sizeof(int));
	int n = 0;
	int i = 0;

	cout << "Enter a list of numbers and -1 to quit:" << endl;
	while (1)
	{
		cin >> n;
		if (n != -1)
		{
			numbers[i] = n;
			i++;

			if (i == length)
			{
				length += 5;
				numbers = (int*)realloc(numbers, length * sizeof(int));
			}
		}
		else
			break;
	}

	cout << "\nThe list of numbers you entered after filter:\n" << endl;

	for (int j = 0; j < i; j++)
	{
		if (numbers[j] == 42)
			break;
		if (nd(numbers[j]) > 2) 
			continue;
		cout << numbers[j] << endl;
	}
}
