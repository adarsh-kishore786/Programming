/*
	masking_oper.c

	This program shows various masking
	operations in C.
*/

#include <stdio.h>
#include <stdlib.h>

// Returns LSB of x
int get_lsb(int x)
{
	return x & 0xFF;
}

// will complement all bytes of x, except the 
// LSB
int complement_except_lsb(int x)
{
	int y = ~(x | 0xFF);
	int z = get_lsb(x);
	return y | z;
}

// will set LSB to 0xFF
int set_lsb(int x)
{
	return x | 0xFF;
}

void oper(int x)
{
	printf("The number: 0x%x\n", x);
	printf("LSB       : 0x%x\n", get_lsb(x));
	printf("Complements except LSB: 0x%x\n", complement_except_lsb(x));
	printf("Set LSB: 0x%x\n", set_lsb(x));
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("No numbers given. Try again.\n");
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		int x = (int)strtol(argv[i], NULL, 16);
		oper(x);
	}

	return 0;
}