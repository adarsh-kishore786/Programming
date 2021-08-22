/* matrix_operations.c

   This program demonstrates the
   matrix operations of addition,
   subtraction, negation.

   Author: Adarsh
*/

# include <stdio.h>
# include "util.c"

int main()
{
    int length, width, length1, width1;
    int *a, *b;
    int size, size1;

    a = input_matrix(&length, &width, a, &size, 0);

    printf("\nThe original matrix A:\n");
    print_matrix(a, length, width, size);

    printf("\n");

    int *at = transpose(a, length, width);
    printf("\nA'\n");
    print_matrix(at, width, length, size);
    printf("\n");

    b = input_matrix(&length1, &width1, b, &size1, 0);

    printf("\nB:\n");
    print_matrix(b, length1, width1, size1);

    int *c, s3;
    c = sub(a, b, &s3, length, width, length1, width1);

    printf("\nC = A - B\n");
    print_matrix(c, length, width, s3);

    printf("\nB:\n");
    print_matrix(b, length1, width1, size1);

    return 0;
}

