#include <stdio.h>
#include <stdint.h>

int main()
{
	uint64_t num = 234324333;
	printf("num: %d\n", num);

	printf("The maximum value of int8_t: %d\n", INT8_MAX);
	printf("The minimum value of int8_t: %d\n", INT8_MIN);

	printf("The maximum value of uint8_t: %u\n", UINT8_MAX);
	//printf("The minimum value of uint8_t: %d\n", UINT8_MIN); error min of all
			// unisgned data types is 0 no UINT(N)_MIN is defined

	printf("The maximum value of int16_t: %d\n", INT16_MAX);
	printf("The minimum value of int16_t: %d\n", INT16_MIN);
	printf("The maximum value of uint16_t: %d\n", UINT16_MAX);

	printf("The maximum value of int32_t: %d\n", INT32_MAX);
	printf("The minimum value of int32_t: %d\n", INT32_MIN);
	printf("The maximum value of uint32_t: %u\n", UINT32_MAX);

	// The least width type macros return a type that stores bytes
	// greater or equal to the least asked bytes and less than any 
	// higher storing type.

	printf("The max val of int_least8_t: %d\n", INT_LEAST8_MAX);
	printf("The min val of int_least8_t: %d\n", INT_LEAST8_MIN);

	printf("The max val of uint_least8_t: %u\n", UINT_LEAST8_MAX);

	// The fast width return the most efficient type for storing 
	// given bytes

	printf("The max val of int_fast8_t: %d\n", INT_FAST8_MAX);

	// These integers hold pointers
	printf("The max val of intptr_t: %u\n", INTPTR_MAX);
	printf("The min val of intptr_t: %u\n", INTPTR_MIN);

	// ptrdiff_t is a typedef of intptr_t
	printf("The max val of ptrdiff_t: %u\n", PTRDIFF_MAX);

	// size_t basically holds all positive integers, it is the return 
	// type of the sizeof() function since its always positive
	printf("The max val of size_t: %u\n", SIZE_MAX);
	printf("sizeof(size_t): %u\n", sizeof(size_t)); // in bytes
}