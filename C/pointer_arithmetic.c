/* pointer_arithmetic.c

   This program demonstrates the
   application of arithmetic on
   variables representing pointers.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 45, 67, 56, 74};
    int i = 4, *j, *k, *x, *y;

    j = &i;

    printf("Original address at j: %u\n", j);
    j += 9; // Pointer + number
    printf("New address at j: %u\n", j);
    k = &i;
    printf("Original address at k: %u\n", k);
    k -= 3; // Pointer - number

    printf("New address at k: %u\n", k);

    x = &arr[1];
    y = &arr[5];

    printf("Address at x: %u\n", x);
    printf("Address at y: %u\n", y);
    printf("y - x = %d\n", y - x); // Pointer - Pointer

    j = &arr[4];
    k = (arr + 4); // Just writing arr like this refers to the
                    // memory location of first element of array

    if (j == k)
        printf("Both pointers point to same location.\n");
    else
        printf("The two pointers point to different locations.\n");
}
