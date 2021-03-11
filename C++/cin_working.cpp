/*
	cin_working.cpp

	This program shows how the std::cin operator
	works and some techniques of defensive 
	programming to protect against invalid input.
*/

#include <iostream>
#include <limits>
#include <cassert>

namespace v1
{
	double getDouble()
	{
		std::cout << "Enter a double value: ";
		double a {};
		std::cin >> a;
		return a;
	}

	char getOperator()
	{
		std::cout << "Enter an operator +, -, *, /: ";
		char ch {};
		std::cin >> ch;

		return ch;
	}
}

namespace v2
{
	double getDouble()
	{
		std::cout << "Enter a double value: ";
		double a {};
		std::cin >> a;
		return a;
	}

	bool correct(char ch)
	{
		switch (ch)
		{
			case '+':
			case '-':
			case '*':
			case '/': return true;
		}
		return false;
	}

	char getOperator()
	{
		while (true)
		{
			std::cout << "Enter an operator +, -, *, /: ";
			char ch {};
			std::cin >> ch;

			if (correct(ch))
				return ch;
			else
				std::cout << "Invalid operator entered. Try again.\n\n";
		}
	}
}

namespace v3
{
	void clearBuffer()
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore until \n
	}

	double getDouble()
	{
		std::cout << "Enter a double value: ";
		double a {};
		std::cin >> a;
		clearBuffer();
		return a;
	}

	bool correct(char ch)
	{
		switch (ch)
		{
			case '+':
			case '-':
			case '*':
			case '/': return true;
		}
		return false;
	}

	char getOperator()
	{
		while (true)
		{
			std::cout << "Enter an operator +, -, *, /: ";
			char ch {};
			std::cin >> ch;

			if (correct(ch))
				return ch;
			else
				std::cout << "Invalid operator entered. Try again.\n\n";
			clearBuffer();
		}
	}
}

inline namespace v4
{
	void clearBuffer()
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore until \n
	}

	void handleFail()
	{
		std::cin.clear();
		clearBuffer();
	}

	double getDouble()
	{
		input: std::cout << "Enter a double value: ";
		double a {};
		std::cin >> a;
		if (std::cin.fail())
		{
			handleFail();
			std::cout << "Invalid input. Try again.\n\n";
			goto input;
		}
		clearBuffer();
		return a;
	}

	bool correct(char ch)
	{
		switch (ch)
		{
			case '+':
			case '-':
			case '*':
			case '/': return true;
		}
		return false;
	}

	char getOperator()
	{
		while (true)
		{
			std::cout << "Enter an operator +, -, *, /: ";
			char ch {};
			std::cin >> ch;

			if (correct(ch))
				return ch;
			else
				std::cout << "Invalid operator entered. Try again.\n\n";
			clearBuffer();
		}
	}
}

void calculate(double a, double b, char ch)
{
	double r {};
	switch (ch)
	{
		case '+': r = a + b;
				  break;
		case '-': r = a - b;
				  break;
		case '*': r = a * b; 
				  break;
		case '/': assert(b != 0 && "Can't divide by zero.");
				  r = a / b;
				  break;
	}
	std::cout << a << " " << ch << " " << b << " = " << r << std::endl;
}

int main()
{
	/*
	When the extraction operator is used, the following procedure happens:

	1. If there is data already in the input buffer, that data is used for extraction.
	2. If the input buffer contains no data, the user is asked to input data for extraction. 
	3. When the user hits enter, a ‘\n’ character will be placed in the input buffer.
	   operator >> extracts as much data from the input buffer as it can into the variable 
	   (ignoring any leading whitespace characters, such as spaces, tabs, or ‘\n’).
	   Any data that can not be extracted is left in the input buffer for the next extraction
	

	int x {};
	std::cin >> x; // Suppose user inputs 5a. Then 5 will be taken into x and 'a' left

	char ch {};
	std::cin >> ch; 

	std::cout << "x = " << x << std::endl;
	std::cout << "ch = " << ch << std::endl;

	std::cin >> ch;
	std::cout << "ch = " << ch << std::endl;

	std::cin >> ch;
	std::cout << "ch = " << ch << std::endl;
	/*

	/*
		Input errors are of 4 types-
		1. Input extraction succeeds but input is meaningless to program.
		2. Input extraction succeeds but user enters additional input. This will stay in
		   input buffer and can affect later programs.
		3. Input extraction fails.
		4. Input extraction succeeds but user overflows a numeric value.
	*/
	
	double a { getDouble() };
	double b { getDouble() };
	char op { getOperator() };

	calculate(a, b, op);
}