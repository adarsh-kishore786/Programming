/* pass_2darray_function.c

   This program demonstrates passing a 2D
   array to a function via help of pointers.

   Author: Adarsh
*/

# include <stdio.h>

void display1(int a[3][4])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void display2(int (*a)[4])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", *(*(a + i) + j));
        printf("\n");
    }
}

int main()
{
    int a[3][4] = {
                    1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 0, 1, 2
                  };

    display1(a);
    printf("\n");
    display2(a);

}
