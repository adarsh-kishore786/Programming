/* matrix_multiplication.c

   This program demonstrates the
   operation of matrix multiplication.

   Author: Adarsh
*/

# include <stdio.h>
# include "util.c"

int main()
{
    int l1, w1, s1;
    int l2, w2, s2;
    int *a1, *a2, *prod;
    int s;

    a1 = input_matrix(&l1, &w1, a1, &s1, 1);
    printf("\n");
    a2 = input_matrix(&l2, &w2, a2, &s2, 1);

    printf("\nA1\n");
    print_matrix(a1, l1, w1, s1);

    printf("\nA2\n");
    print_matrix(a2, l2, w2, s2);


    prod = mul(a1, a2, &s, l1, w1, l2, w2);

    printf("\nA1 * A2\n");
    print_matrix(prod, l1, w2, s);

    return 0;
}
