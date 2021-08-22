/* sin_series.c

   This program accepts the value of
   x and calculates sin(x) using its
   series expansion.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

int fact(int n)
{
    int p = 1;
    for (int i = 2; i <= n; i++)
        p *= i;
    return p;
}

void sinx(float x, float *sin_x)
{
    for (int r = 0; r <= 10; r++)
    {
        *sin_x += (pow(-1, r) * pow(x, (2 * r + 1))
                    / fact(2 * r + 1));
    }
}

int main()
{
    float x, sin_x;

    printf("Enter the value of x:\n");
    scanf(" %f", &x);

    sinx(x, &sin_x);
    printf("sin(%f) using expansion = %f\n", x, sin_x);
    printf("Actual value of sin(%f) = %f", x, sin(x));
    return 0;
}
