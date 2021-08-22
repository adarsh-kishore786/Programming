/* array_pointer.c

   This program is used to access the
   elements of a program using
   pointers.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    int num[] = {24, 34, 12, 44, 56, 17};
    int i, *j;
    j = num;

    for (i = 0; i <= 5; i++)
    {
        printf("address = %u value = %d\n", j, *j);
        j++; // Pointer now refers to next memory location
    }
}
