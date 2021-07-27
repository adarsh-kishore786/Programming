/* bit_operations.c

   This program demonstrates the
   bit operations.

   Author: Adarsh
*/

#include <stdio.h>

void showbits(unsigned char n)
{
	unsigned char j, k, andmask;

	for (int i = 7; i >= 0; i--)
	{
		j = i;
		andmask = 1 << j;
		k = n & andmask;
		k == 0 ? printf("0") : printf("1");
	}
}

int main()
{
	// one's complement
	unsigned char ch = 32;
	unsigned char dh;
	dh = ~ch;
	printf("~ch = %d\n", dh);
	printf("~ch = %x\n", dh);
	printf("~ch = %X\n", dh);
	printf("~ch = %#X\n", dh);

	// left and right shift
	char num = 225, k;
	printf("Decimal %d is the same as binary ", num);
	showbits(num);

	k = num >> 1;
	printf("\nDecimal %d is the same as binary ", k);
	showbits(k);

	k = num >> 2;
	printf("\nDecimal %d is the same as binary ", k);
	showbits(k);

	k = num << 1;
	printf("\nDecimal %d is the same as binary ", k);
	showbits(k);

	k = num << 2;
	printf("\nDecimal %d is the same as binary ", k);
	showbits(k);

	// negative numbers are right shifted retaining their 
	// sign in binary

	printf("\n");
	num = -5;
	for (int j = 0; j <= 10; j++)
	{
		k = num >> j;
		printf("\n%d = %d >> %d in decimal is in binary ", k, num, j);
		showbits(k);
	}

	printf("\n");

	num = -5;
	for (int j = 0; j <= 10; j++)
	{
		k = num << j;
		printf("\n%d = %d << %d in decimal is in binary ", k, num, j);
		showbits(k);
	}

}