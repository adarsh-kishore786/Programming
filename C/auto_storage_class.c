/* storage_classes.c

   This program demonstrates the various
   storage classes in C.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    auto int i, j; // The default int
    printf("%d %d\n", i, j);

    i = 1;
    {
        auto int i = 2;
        {
            auto int i = 3;
            printf("%d\n", i);
        }
        printf("%d\n", i);
    }
    printf("%d\n", i);
}
