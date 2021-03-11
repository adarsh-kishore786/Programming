/* mask.c

   This program develops the concept of
   a mask to derive the individual 
   bits of a byte, and the use of &, |
   and ^ bits.

   Author: Adarsh
*/

#include <stdio.h>
#include <math.h>

int bit(int num, int pos)
{
	int mask = 1 << (8 - pos);

	int result = num & mask;
	return (result == 0) ? 0 : 1;
}

int bits(int num)
{
	int bits = 0;
	for (int i = 8; i >= 1; i--)
		bits += pow(10, 8 - i) * bit(num, i);
	return bits;
}

int main()
{
	printf("After a left-shift the value gets multiplied by 2:\n");
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
			printf("%d << %d = %d\n", i, j, i<<j);
		printf("\n");
	}
	printf("In general, a << j = a * pow(2, j)\n");

	printf("After a right-shift the value gets floor divided by 2:\n");
	for (int i = 100; i >= 80; i--)
	{
		for (int j = 0; j <= 10; j++)
			printf("%d >> %d = %d\n", i, j, i>>j);
		printf("\n");
	}
	printf("In general, a >> j = a / pow(2, j)\n");

	printf("\nThe & operator:\n");
	printf("It works according to the truth table:\n");
	printf("| a | b | a & b |\n");
	printf("|---|---|-------|\n");
	printf("| 0 | 0 |   0   |\n");
	printf("| 0 | 1 |   0   |\n");
	printf("| 1 | 0 |   0   |\n");
	printf("| 1 | 1 |   1   |\n");

	int a = 12;
	int b = 7;
	printf("\nFor example:\n");
	printf("12   = 00001100\n");
	printf(" 7   = 00000111\n");
	printf("12&7 = 00000100 = %d\n", 12&7);

	printf("\nThe | operator:\n");
	printf("It works according to the truth table:\n");
	printf("| a | b | a | b |\n");
	printf("|---|---|-------|\n");
	printf("| 0 | 0 |   0   |\n");
	printf("| 0 | 1 |   1   |\n");
	printf("| 1 | 0 |   1   |\n");
	printf("| 1 | 1 |   1   |\n");

	printf("\nFor example:\n");
	printf("12   = 00001100\n");
	printf(" 7   = 00000111\n");
	printf("12|7 = 00001111 = %d\n", 12|7);

	printf("\nThe ^ operator:\n");
	printf("It works according to the truth table:\n");
	printf("| a | b | a ^ b |\n");
	printf("|---|---|-------|\n");
	printf("| 0 | 0 |   0   |\n");
	printf("| 0 | 1 |   1   |\n");
	printf("| 1 | 0 |   1   |\n");
	printf("| 1 | 1 |   0   |\n");

	printf("\nFor example:\n");
	printf("12   = 00001100\n");
	printf(" 7   = 00000111\n");
	printf("12^7 = 00001011 = %d\n", 12^7);

	printf("\nBuilding a bit extractor:\n");
	printf("Given any number, its bits can be extracted by the & operator:\n");
	printf("For example, 12 = %08d\n", bits(12));
	printf("Bit at the 5th position = %d\n", bit(12, 5));
	printf("Bit at the 8th position = %d\n", bit(12, 8));
}	