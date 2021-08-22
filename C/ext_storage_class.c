/* ext_storage_class.c

   This program demonstrates the
   external storage class.

   Author: Adarsh
*/

# include <stdio.h>

int i; // Global default is 0

void increment()
{
    printf("Value of i on incrementing = %d\n", ++i);
}

void decrement()
{
    printf("Value of i on decrementing = %d\n", --i);
}

int main()
{
    printf("i = %d\n", i);
    increment();
    increment();
    decrement();
    decrement();

    return 0;
}
