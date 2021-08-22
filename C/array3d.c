/* array3d.c

   This program demonstrates the
   initialization of a 3d array
   and printing it.

   Author: Adarsh
*/

# include <stdio.h>
# include <stdlib.h>

int main()
{
    int *array;
    int length, width, height;

    printf("Enter the length of the array: ");
    scanf("%d", &length);

    printf("Enter the width of the array: ");
    scanf("%d", &width);

    printf("Enter the height of the array: ");
    scanf("%d", &height);

    array = (int*) malloc(length * width * height * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < height; k++)
            {
                printf("Enter element [%d][%d][%d]: ", i, j, k);
                scanf("%d", array + i * (width * height) + j * height + k);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    printf("\nThe array entered:\n");

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < height; k++)
                printf("Element [%d][%d][%d]: %d\n", i, j, k
                                , *(array + i * (width * height) + j * height + k));
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}
