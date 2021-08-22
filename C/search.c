/* search.c

   This program accepts an array
   from a user and a number from the
   user and then finds th number of
   instances of that element in the
   array.

   Author: Adarsh
*/

# include <stdio.h>
# include <stdlib.h>

int main()
{
    int* array;
    int length, element;

    printf("Enter the size of the array:\n");
    scanf("%d", &length);

    array = (int*) malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        printf("Enter a number: ");
        scanf("%d", array + i);
    }

    printf("Enter a number to search in the array:\n");
    scanf("%d", &element);

    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (array[i] == element)
            count++;
    }

    if (count == 0)
    {
        printf("Given element does not exist in the array.");
        return 0;
    }

    printf("The given array is:\n");
    for (int i = 0; i < length; i++)
        printf("%d. %d\n", (i + 1), array[i]);

    printf("\n%d occurs %d time(s) in the given array.", element, count);
}
