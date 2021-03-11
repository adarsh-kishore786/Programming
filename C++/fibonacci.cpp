/*
	fibonacci.cpp

	This program prints the first n 
	fibonacci numbers.
*/

#include <iostream>
#include <vector>

std::vector<int> fibonaccis{0, 1}; 

int getFibonacci(int n)
{
	if (n - 1 < fibonaccis.size())
		return fibonaccis[n - 1];
	int sum {getFibonacci(n - 1) + getFibonacci(n - 2)};
	fibonaccis.push_back(sum);

	return sum;	
}

int main()
{
	int n {};
	std::cout << "Enter number of Fibonacci numbers: ";
	std::cin >> n;

	std::cout << "\n";
	for (int i = 1; i <= n; i++)
		std::cout << getFibonacci(i) << " ";
}