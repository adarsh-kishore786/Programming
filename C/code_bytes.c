/*
	code_bytes.c
*/

#include "byte_repr.h"
#include <stdio.h>

int sum(int x, int y)
{
	return x + y;
}

int main()
{
	show_pointer((byte_pointer) sum);
}