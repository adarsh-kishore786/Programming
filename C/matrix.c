/* matrix.c

   This program creates a 3x2 matrix
   using 2D array.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    int matrix[3][2];

    for (int i = 0; i < 3; i++)
    {
        printf("Enter a row of two numbers:\n");
        scanf("%d %d", matrix[i], matrix[i] + 1);
    }

    printf("The matrix:\n");
    for (int i = 0; i < 3; i++)
        printf("[ %2d %2d ]\n", matrix[i][0], matrix[i][1]);

    return 0;
}
