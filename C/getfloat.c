/* getfloat.c

   This program simulates a float
   parser, it accepts a float and 
   displays it.

   Author: Adarsh
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int toint(char c)
{
	return (int)c - 48;
}

int n_d(int num)
{
	int nd = 0;
	while (num != 0)
	{
		nd++;
		num /= 10;
	}
	return nd == 0 ? 1 : nd;
}

int reverse(int num)
{
	int rev = 0;
	int nd = n_d(num) - 1;

	while (num != 0)
	{
		rev += (num % 10) * pow(10, nd);
		nd--;
		num /= 10;
	}
	return rev;
}

float getfloat()
{
	int c = EOF;
	int int_part = 0;
	float dec_part = 0.0;
	int in_integer = 1;
	int i = 0;
	int is_neg = 0;

	printf("Enter a floating point value: ");

	while ((c = getchar()) != EOF && c != '\n')
	{
		if (in_integer)
		{
			if (c != '.' && c != '-')
			{
				int_part += (int)(toint(c) * pow(10, i));
				i++;
			}
			else if (c == '-')
				is_neg = 1;
			else 
			{
				in_integer = 0;
				i = -1;
				continue;
			}
		}
		else
		{
			dec_part += toint(c) * pow(10, i);
			i--;
		}
	}
	return pow(-1, is_neg) * (reverse(int_part) + dec_part);
}

int main()
{
	float a;
	a = getfloat();
	printf("You entered %f.", a);
}