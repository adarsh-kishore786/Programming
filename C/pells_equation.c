/* pells_equation.c

   The Pell's equation is: x^2 - Ny^2 = 1,
   where N is any non-square natural
   number. We will try to capture all
   integer solutions of this equation.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

int gcd(int a, int b)
{
    if (a == b || a == 0)
        return a;

    int t1 = abs(a - b);
    int t2 = a < b ? a : b;

    a = t1;
    b = t2;
    gcd(a, b);
}

void simplify(int xyk[][3])
{
    for (int i = 0; i <= 2; i++)
    {
        int g = gcd(xyk[0][i], xyk[1][i]);

        if (g != 1 && g != 0)
        {
            xyk[0][i] /= g;
            xyk[1][i] /= g;
        }
    }
}

void display(int xyz[][3])
{
    for (int i = 0; i <= 2; i++)
        printf("%d ", xyz[0][i]);
    printf("\n-----------------------\n");
    for (int i = 0; i <= 2; i++)
        printf("%d ", xyz[1][i]);
    printf("\n\n");
}

int is_integer(float num)
{
    int truncated = (int) num;
    return num - truncated == 0;
}

void next(int v[], int lc[][2], int count)
{
    if (count > 10)
        return;

    int sum[2] = {0, 0};

    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
            sum[i] += lc[i][j] * v[j];
    }
    v = sum;
    printf("%2d. (%d, %d)\n", count, v[0], v[1]);
    next(v, lc, count+1);
}

int main()
{
    int n;
    int v[2] = {1, 0};
    int lc[2][2] = {{3, 4},
                    {2, 3}};
    int xyk[2][3] = {{2, 0, 6},
                     {2, 2, 4}};

    display(xyk);
    simplify(xyk);
    display(xyk);
    input:
    {
        printf("Enter a non-square number:\n");
        scanf("%d", &n);
    }

    if (n < 0)
    {
        printf("%d is a negative number. Enter a positive number.\n", n);
        goto input;
    }

    if (is_integer(sqrt(n)))
    {
        printf("%d is a perfect square. Enter a non-square.\n", n);
        goto input;
    }

    printf("Solving x^2 - %dy^2 = 1:\n", n);
    printf("Trivial solution = (%d, %d)\n", v[0], v[1]);

    next(v, lc, 1);
    return 0;
}
