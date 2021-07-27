/*
	namespace2.cpp

	Shows inline namespace
*/

#include <iostream>

namespace v1
{
	void doSomething()
	{
		std::cout << 5 << std::endl;
	}
}

namespace v2
{
	void doSomething()
	{
		std::cout << 6 << std::endl;
	}
}

//Default version
inline namespace v3
{
	void doSomething()
	{
		std::cout << -10 << std::endl;
	}
}

int main()
{
	v1::doSomething();
	v2::doSomething();
	v3::doSomething();

	doSomething(); // Means doSomething() in the inline namespace

}