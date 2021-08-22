/* test_macro.c

   This program tests the macros
   defined in alphanumeric.h

   Author: Adarsh
*/

# include <stdio.h>
# include "alphanumeric.h"

int main()
{
    char c = 'A';
    if (is_upper(c))
        printf("%c is upper case.\n", c);
    else if (is_lower(c))
        printf("%c is lower case.\n", c);

    char c1 = '1';
    if (is_letter(c1))
        printf("%c is a letter.\n", c1);
    else
        printf("%c is not a letter.\n", c1);

    int a = 5, b = 16;
    printf("%d is the bigger of %d and %d.\n", BIGGER(a, b), a, b);
}
