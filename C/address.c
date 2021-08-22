/* address.c

   This program prints the address
   location of a variable storing
   a value.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    int i = 3;
    printf("Address of i = %u\n", &i); // The &i refers to the memory location at
                                       // which i is stored
                                       // %u means unsigned integer. We know address
                                       // location is a positive number so no question
                                       // of its sign. However, we could use %d also.
    printf("Value of i = %d\n", i);
    printf("Value at address of i = %d", *(&i));
    return 0;
}

// Pointer operators in C-
// &- The 'address of a variable' operator.
// *- The 'value at address' operator. Used as *(&)
