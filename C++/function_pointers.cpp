/*
	function_pointers.cpp

	This program demonstrates the concept 
	of pointers to functions.
*/

#include <iostream>
#include <functional>

int foo()
{
	return 5;
}

int foo1()
{
	return 6;
}

int doSomething(int a)
{
	return a*a;
}

int toInt(bool val)
{
	return static_cast<int>(val);
}

int main()
{
	std::cout << "Result of foo:" << foo() << "\n";
	std::cout << "Just foo: " << foo << "\n";
	std::cout << "Address of foo: " << reinterpret_cast<void*>(foo) << "\n";

	//Creating a function pointer
	int (*funcPtr)();
	funcPtr = &foo;
	std::cout << funcPtr << "\n";
	funcPtr = &foo1;
	std::cout << funcPtr << "\n";

	int (*ptr)(int) { &doSomething };
	std::cout << ptr << "\n";
	std::cout << "Using ptr: " << ptr(5) << "\n"; // Implicit dereferncing done	

	std::function<int(bool)> ptr2 { &toInt };
	//std::cout << ptr2 << "\n";
	std::cout << "Using ptr2: " << ptr2(true) << "\n";
}
