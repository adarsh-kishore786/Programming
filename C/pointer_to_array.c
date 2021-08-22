/* pointer_to_array.c

   This program demonstrates the concept
   of an array of pointers.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    int s[4][2] = { {1234, 56}, {1212, 33},
                    {1434, 80}, {1312, 78} };
    int (*p) [2]; // p is a pointer to an array of two integers. p is a single value, not an array itself. it just points to an array
    int *pint;

    for (int i = 0; i < 4; i++)
    {
        p = s + i;
        // p is a pointer to an array, which is further a pointer to two values, since arrays behave like
        // pointers
        pint = *p;
        // p is cast to an integer pointer pint, which then points to the individual
        // elements in the different columns.
        for (int j = 0; j < 2; j++)
            printf("%d ", *(pint + j));
            // We could also write *(*p + j)
        printf("\n");
    }
    return 0;
}
