/* reverse_array.c

   This program accepts an array entered
   by the user and copies it into another
   array in the reverse order.

   Author: Adarsh
*/

# include <stdio.h>
# include <stdlib.h>

int main()
{
    int length, *p;

    printf("Enter the size of the array:\n");
    scanf("%d", &length);

    p = (int*) malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        printf("Enter a number: ");
        scanf("%d", p + i);
    }

    printf("The array you entered:\n");
    for (int i = 0; i < length; i++)
        printf("%d. %d\n", (i + 1), p[i]);

    int* reverse = (int*) malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
        (length - i - 1)[reverse] = *(p + i);

    printf("\nThe array in reverse:\n");
    for (int i = 0; i < length; i++)
        printf("%d. %d\n", (i + 1), reverse[i]);
}
