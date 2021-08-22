/* conditional_compilation.c

   This program demonstrates the use
   of the #ifdef macro.

   Author: Adarsh
*/

# include <stdio.h>
# define EVEN
# define TEST 15

int main()
{
    # ifdef EVEN
        printf("Number is even.\n");
    # else
        printf("Number is not even.\n");
    # endif // EVEN

    # if TEST <= 5
        int t = TEST + 1;
        printf("%d\n", t);
    # elif TEST <= 10
        printf("TEST between 5 and 10\n");
    # elif TEST <= 20
        return 1;
    # else
        printf("Don't know what happened.");
    # endif // TEST
}

