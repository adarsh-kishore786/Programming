/* pointer_2darray.c

   This program demonstrates the use of
   pointer notation to access the
   elements of a 2D array.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    int s[4][2] = {
                    {1234, 56},
                    {1212, 33},
                    {1434, 80},
                    {1312, 78}
                  };

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", *(*(s + i) + j));
        }
        printf("\n");
    }
    return 0;
}
