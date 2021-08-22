/* ascii.c

   This program prints the ascii
   values and characters corresponding
   to them from 0 to 255.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    int c = 0;

    printf("ASCII table:\n");
    while (c <= 255)
    {
        printf("%d: %c\n", c, c);
        c++;
    }
    return 0;
}
