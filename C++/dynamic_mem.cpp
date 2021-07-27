/*
	dynamic_mem.cpp

	This program demonstrates the new and
	delete keywords used for dynamic memory
	allocation.
*/

#include <iostream>

void doSomething()
{
	int* ptr {new int { 0 }}; // This dynamic memory is now lost 
				// when ptr goes out of scope
	// To prevent such memory leaks, always delete pointers
	// before going out of scope
	delete ptr;
}

int main()
{
	int* ptr { new int }; // ptr has dynamic memory
	*ptr = 7;

	std::cout << "ptr is a dynamic memory address pointer and value"
			  << " stored at ptr is " << *ptr << ".\n";

	// We can initialize and assign simultaneously
	int* ptr1 {new int{5}};
	std::cout << "Value at ptr1 = " << *ptr1 << ".\n";

	// After using our pointers, we should return the memory
	delete ptr; 
	std::cout << "ptr is now deleted. It's value is " << *ptr << ".\n"; // Some garbage value
	ptr = nullptr;
	//std::cout << "Deleted pointers should be made nullptr. Now value = " << *ptr << ".\n";//Error. This will now crash

	// Sometimes new may fail. In that case we should use new (std::nothrow)
	int *p = new (std::nothrow)	int (5); // if allocation fails p = nullptr
	if (!p)
		std::cout << "Failed to allocate memory.\n";

	doSomething();
}