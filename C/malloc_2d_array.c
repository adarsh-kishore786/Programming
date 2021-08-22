/* malloc_2d_array.c

   This program demonstrates the use of
   the malloc function to create a 2d
   array of variable length and width.

   Author: Adarsh
*/

# include <stdio.h>
# include <stdlib.h>

int main()
{
    int r, c;
    int *p;
    printf("Enter the number of rows and columns:\n");
    scanf("%d %d", &r, &c);

    p = (int*) malloc(r * c * sizeof(int));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter a number: ");
            scanf("%d", p + i * c + j);
        }
    }

    for (int i = 0; i < r; i++)
    {
        printf("[ ");
        for (int j = 0; j < c; j++)
            printf("%3d ", *(p + i * c + j));
        printf(" ]\n");
    }
}
