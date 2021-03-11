/* getint.c

   This program receives an integer string 
   and then parses it into an integer.

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

int getint()
{
	int c = EOF;
    printf("Enter an integer: ");
    int i = 0;
    int num = 0;
    int is_neg = 0;

    while ((c = getchar()) != EOF && c != '\n')
    {
    	if (c == '-')
    	{
    		is_neg = 1;
    		continue;
    	}
    	num += (int)(toint(c) * pow(10, i));
    	i++;
    }

    return pow(-1, is_neg) * reverse(num);
}

int main()
{
	int a;
	a = getint();
	printf("\nYou entered %d.\n", a);
}