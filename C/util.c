/* util.c

   This contains various utility
   functions.

   Author: Adarsh
*/

# include <stdlib.h>
# include <math.h>

int n_digits(int num)
{
    int nd = 0;
    int n = abs(num);

    while (n != 0)
    {
        nd++;
        n /= 10;
    }

    return (nd == 0) ? 1 : nd;
}

int get_size(int *m, int l, int w)
{
    int largest = *m;
    int smallest = *m;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int val = *(m + i * w + j);
            if (val > largest)
                largest = val;
            if (val < smallest)
                smallest = val;
        }
    }
    return (abs(smallest) > largest) ? n_digits(smallest) + 1 :
                                    n_digits(largest) + 1;
}

int* input_matrix(int* length, int* width, int *array,
                    int *size, int square)
{
    int largest;
    int smallest;

    if (square)
    {
        printf("Enter the side of the square matrix:\n");
        scanf(" %d", length);
        *width = *length;
    }
    else
    {
        printf("Enter the length and width of the matrix:\n");
        scanf(" %d %d", length, width);
    }

    array = (int*) malloc( *length * *width * sizeof(int) );

    for (int i = 0; i < *length; i++)
    {
        for (int j = 0; j < *width; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf(" %d", array + i * *width + j);

            int val = *(array + i * *width + j);
        }
    }

    *size = get_size(array, *length, *width);
    return array;
}

int is_compatible_addition(int l1, int w1, int l2, int w2)
{
    return (l1 == l2 && w1 == w2);
}

int is_compatible_multiplication(int w1, int l2)
{
    return l2 == w1;
}

int* negate(int *a, int l, int w)
{
    int *m = (int*) malloc(l * w * sizeof(int));
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < w; j++)
            *(m + i * w + j) = -*(a + i * w + j);
    }
    return m;
}

int* add(int *a, int *b, int *s, int l1, int w1, int l2, int w2)
{
    if (!is_compatible_addition(l1, w1, l2, w2))
    {
        printf("\nThe addition is not compatible: %d x %d", l1, w1);
        printf(" with %d x %d.", l2, w2);
        exit(0);
    }
    int *m = (int*) malloc(l1 * w1 * sizeof(int));

    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < w1; j++)
            *(m + i * w1 + j) = *(a + i * w1 + j) +
                                *(b + i * w1 + j);
    }

    *s = get_size(m, l1, w1);
    return m;
}

int* sub(int *a, int *b, int *s, int l1, int w1, int l2, int w2)
{
    b = negate(b, l2, w2);
    int *c = add(a, b, s, l1, w1, l2, w2);

    return c;
}

int* mul(int *a, int *b, int *s, int l1, int w1, int l2, int w2)
{
    if (!is_compatible_multiplication(w1, l2))
    {
        printf("The matrix multiplication is not compatible.");
        printf(" Operands %d x %d and %d x %d", l1, w1, l2, w2);
        exit(0);
    }

    int *m = (int*) malloc(l1 * w2 * sizeof(int));
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < w2; j++)
        {
            int sum = 0;
            for (int k = 0; k < w1; k++)
                sum += *(a + i * w1 + k) * *(b + k * w2 + j);
            *(m + i * w2 + j) = sum;
        }
    }
    *s = get_size(m, l1, w2);
    return m;
}

int* transpose(int* a, int l, int w)
{
    int *m = (int*) malloc(w * l * sizeof(int));
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < w; j++)
            *(m + j * l + i) = *(a + i * w + j);
    }
    return m;
}

int* minor(int *a, int l, int w, int r, int c)
{
    int l1 = l - 1;
    int w1 = w - 1;

    int *b = (int*) malloc(l1 * w1 * sizeof(int));

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == r && j == c)
                continue;

            int i1 = i, j1 = j;
            if (i > r) i1 -= 1;
            if (j > c) j1 -= 1;

            *(b + i1 * w1 + j1) = *(a + i * w + j);
        }
    }
    return b;
}

int determinant(int *a, int l, int w)
{
    if (l == 1 && w == 1)
        return *a;

    int sum = 0;
    for (int j = 0; j < w; j++)
    {
        int curr = *(a + j);
        sum += pow(-1, j + 2) * curr *
                    determinant(minor(a, l, w, 0, j), l - 1, w - 1);
    }
    return sum;
}


void print_matrix(int *a, int l, int w, int size)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < w; j++)
            printf("%*d ", size, *(a + i * w + j));
        printf("\n");
    }
}

void print_pointer(char *pstr)
{
    int i = 0;
    while (*(pstr + i) != '\0')
    {
        printf("%c", *(pstr + i));
        i++;
    }
}
