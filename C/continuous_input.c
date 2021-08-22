/* continuous_input.c

   This program accepts a number from
   the user and prints the square of
   the number. It keeps doing so until
   the user asks it to stop.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    int n;
    int c = 'y';

    while (c == 'y' || c == 'Y')
    {
        printf("Enter a number:\n");
        scanf("%d", &n);

        printf("Square of %d: %d", n, n*n);

        printf("\nContinue (Y/N)?\n");
        fflush(stdin);
        scanf("%c", &c);
    }
    return 0;
}
