/*
	count_if.cpp

	This program demonstrates the use of 
	the count_if function, which is same as an
	if condition placed inside a for loop 
	for counting.
*/

#include <iostream>
#include <string>
#include <iterator> // for begin, end, size
#include <algorithm> // for count_if

bool isVowel(char c)
{
	switch (c)
	{
		case 'a':
		case 'A':
		case 'e': 
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U': return true;
	}

	return false;
}

bool isPrime(int n)
{
	if (n == 0 || n == 1)
		return false;

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return true;
	}

	return false;
}

namespace v1
{
	void execute()
	{
		std::string str { "Hello" };

		int numVowels { 0 };
		for (int i = 0; i < str.size(); i++)
		{
			if (isVowel(str[i]))
				numVowels++;
		}

		std::cout << str << " has " << numVowels << " vowels.\n"; 

		int size { 10 };
		int arr[size] {};
		int numPrimes {0};
		for (int i = 0; i < size; i++)
			arr[i] = i + 1;

		for (int i = 0; i < size; i++)
		{
			if (isPrime(arr[i]))
				numPrimes++;
		}

		std::cout << "There are " << numPrimes << " primes between 1 and " << size + 1 << ".\n";
	}
}

inline namespace v2
{
	void execute()
	{
		std::string str { "Hello" };

		auto numVowels { std::count_if(std::begin(str), std::end(str), isVowel) };
		std::cout << str << " has " << numVowels << " vowels.\n"; 

		int size { 10 };
		int arr[size] {};

		for (int i = 0; i < size; i++)
			arr[i] = i + 1;

		auto numPrimes { std::count_if(arr, arr + size, isPrime) };

		std::cout << "There are " << numPrimes << " primes between 1 and " << size + 1 << ".\n";
	}
}

int main()
{
	execute();
}