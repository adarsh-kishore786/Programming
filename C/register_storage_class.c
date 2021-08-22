/* register_storage_class.c

   This shows features of the register
   storage class.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    register int i; //The storage location is register,
                    // No other change.

    for (i = 1; i <= 10; i++)
        printf("%d\n", i);
}
