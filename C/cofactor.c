/* cofactor.c

   This program accepts a matrix from
   the user and computes the cofactor matrix
   for the matrix. Additionally, it also
   the determinant of a matrix.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "util.c"

int cofactor(int *a, int l, int w, int r, int c)
{
    return pow(-1, r + c + 2) * determinant(minor(a, l, w, r, c), l-1, w-1);
}

int main()
{
    int *a;
    int l, w, s;

    a = input_matrix(&l, &w, a, &s, 1);

    printf("\nA:\n");
    print_matrix(a, l, w, s);

    int *at = transpose(a, l, w);

    printf("\nA':\n");
    print_matrix(at, w, l, s);

    int detA = determinant(a, l, w);
    printf("\nDeterminant of A = |A| = %d", detA);
    printf("\nDeterminant of A' = |A'| = %d", determinant(at, w, l));

    printf("\nCofactor matrix of A: \n");

    int *cmA = (int*) malloc(l * w * sizeof(malloc));
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < w; j++)
            *(cmA + i * w + j) = cofactor(a, l, w, i, j);
    }
    cmA = transpose(cmA, l, w);
    int s1 = get_size(cmA, w, l);
    print_matrix(cmA, w, l, s1);

    return 0;
}
