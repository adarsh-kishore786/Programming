/*
	unions.c

	This program shows the unions
	in C.
*/

#include <stdio.h>

struct s
{
	short int i;
	char ch[2];
};

union u
{
	float f;
	short int i;
	char ch[2];
};

int main()
{
	struct s key1;
	union u key2;

	key1.i = 512;
	
	key2.ch[0] = 'B';
	key2.ch[1] = 'A';

	printf("key1.i = %d\n", key1.i);
	printf("key1.ch[0] = %d\n", key1.ch[0]);
	printf("key1.ch[1] = %d\n\n", key1.ch[1]);

	printf("key2.i = %d\n", key2.i);
	printf("key2.ch[0] = %d\n", key2.ch[0]);
	printf("key2.ch[1] = %d\n", key2.ch[1]);
	printf("key2.f = %f\n", key2.f);

	return 0;
}