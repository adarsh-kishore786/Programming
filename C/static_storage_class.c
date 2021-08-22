/* static_storage_class.c

   This program demonstrates the
   static storage class.

   Author: Adarsh
*/

# include <stdio.h>

void increment()
{
    auto int i = 1;
    static int j = 1; // Value persists between diff func calls
                      // j dies only when execution ends
    i += 1;
    j += 1;
    printf("%d %d\n", i, j);
}

int main()
{
    for (int i = 1; i <= 3; i++)
        increment();
    return 0;
}
