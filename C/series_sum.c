/* series_sum.c

   This program prints the sum of a
   given series.

   Author: Adarsh
*/

# include <stdio.h>

int factorial(int n)
{
    int p = 1;
    for (int i = 2; i <= n; i++)
        p *= i;
    return p;
}

int main()
{
    int term;
    float sum = 0;

    printf("Enter the last term of the series:\n");
    scanf("%d", &term);

    for (int i = 1; i <= term; i++)
    {
        float fact = factorial(i);
        float term = i / fact;
        printf("%f\n", term);
        sum += term;
    }
    printf("Sum: %f", sum);
    return 0;
}
