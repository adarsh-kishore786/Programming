/* largest_number_in_matrix.c

   This program accepts a 2D array(matrix)
   from the user and finds the largest
   number in the matrix.

   Author: Adarsh
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int n_digits(int num)
{
    int nd = 0;
    while (num != 0)
    {
        nd++;
        num /= 10;
    }

    if (nd == 0)
        return 1;
    return nd;
}
int main()
{
    int length, width;
    int* array;
    int size;

    int largest = 0;
    int i_largest = 0;
    int j_largest = 0;

    int smallest;

    printf("Enter the length and width of the matrix:\n");
    scanf("%d %d", &length, &width);

    array = (int*) malloc( length * width * sizeof(int) );

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf(" %d", array + i * width + j);

            int val = *(array + i * width + j);
            if (i == 0 && j == 0)
            {
                smallest = *array;
                largest = *array;
                continue;
            }

            if (val > largest)
            {
                largest = val;
                i_largest = i;
                j_largest = j;
            }

            if (val < smallest)
                smallest = val;
        }
    }

    size = (abs(smallest) > largest) ? n_digits(abs(smallest)) + 1 :
                                        n_digits(abs(largest)) + 1;

    printf("\nThe matrix you entered:\n");
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int val = *(array + i * width + j);
            printf("%*d ", size, val);

        }
        printf("\n");
    }

    printf("\nThe largest number is element [%d][%d] = %d",
                i_largest, j_largest, largest);
    return 0;
}
