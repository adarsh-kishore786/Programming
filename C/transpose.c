/* transpose.c

   This program accepts a matrix from
   the user and prints the transpose of
   the matrix.

   Author: Adarsh
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "util.c"

int main()
{
    int length, width;
    int* matrix;
    int size;

    matrix = input_matrix(&length, &width, matrix, &size, 0);

    printf("\nThe original matrix:\n");
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
            printf("%*d ", size, *(matrix + i * width + j));
        printf("\n");
    }

    printf("\nThe transpose:\n");
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
            printf("%*d ", size, *(matrix + j * width + i));
        printf("\n");
    }


    return 0;
}
