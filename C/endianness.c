/*
	endianness.c

	This program prints the byte representation
	of integers and finds if the system is 
	little endian or big endian.
*/

#include <stdio.h>
#include "byte_repr.h"

void test_show_bytes(int val)
{
	int ival = val;
	float fval = (float) val;	
	int *pval = &ival;

	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}

int main()
{
	int val = 0x87654321;

	byte_pointer valp = (byte_pointer) &val;

	show_bytes(valp, 1);
	show_bytes(valp, 2);
	show_bytes(valp, 3);
	show_bytes(valp, 4);
	printf("\n");

	int x = 3510593;
	test_show_bytes(x); // This machine is little-endian

	const char *str = "abcdef";
	show_bytes((byte_pointer)str, sizeof(str));
	// Represetation of character bytes is platform 
	// independent. It is always big endian.
}