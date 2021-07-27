/*
	byte_repr.h

	A header file for seeing the bytes
	of data types and functions.
*/

#ifndef BYTE_REPR 
#define BYTE_REPR

#include <stdio.h>
typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer p, int l)
{
	for (int i = 0; i < l; i++)
		printf(" %.2x", p[i]);
	printf("\n");
}

void show_int(int x)
{
	printf("%d: \t\t", x);
	show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
	printf("%f: ", x);
	show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void* x)
{
	printf("void*: \t\t");
	show_bytes((byte_pointer)&x, sizeof(void*));
}

#endif