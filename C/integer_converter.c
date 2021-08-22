/* integer_converter.c

   This program accepts a string
   from the user and parses the
   string into an integer, if
   possible.

   Author: Adarsh
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int digit(char c)
{
    switch(c)
    {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
    }
}

int converter(char s[])
{
    int l = strlen(s);
    int p = l - 1;
    long int n = 0;

    for (int i = 0; i < l; i++)
    {
        char c = s[i];
        if (!('0' <= c && c <= '9'))
        {
            printf("Given string is not an integer.");
            exit(EXIT_FAILURE);
        }
        n += digit(c) * pow(10, p);
        p--;
    }
    return n;
}

int main()
{
    char s[2048];

    printf("Enter a string which contains only integer:\n");
    gets(s);

    printf("The integer representation of the string: %d",
           converter(s));
}
