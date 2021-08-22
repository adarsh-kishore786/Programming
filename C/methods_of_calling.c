/* methods_of_calling.c

   This program demonstrates the two methods
   of calling: call by value and call by
   reference.

   Author: Adarsh
*/

# include <stdio.h>

void swapr(int *x, int *y) // Call by reference
{
    // Since we are calling by reference, the
    // address to actual variables are being
    // passed. Thus we are manipulating the actual
    // arguments, not formal

    int t;
    t = *x; // Value at x = Value at address of actual object = Value of object
    *x = *y;
    *y = t;

    printf("\n\nx = %d, y = %d\n", *x, *y);
}

void swapv(int x, int y) // Call by value
{
    int t;
    t = x;
    x = y;
    y = t;

    printf("x = %d, y = %d\n", x, y);
}

int main()
{
    int a = 10, b = 20;
    swapv(a, b);

    printf("a = %d, b = %d\n", a, b);

    swapr(&a, &b); // Addresses of a and b
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
