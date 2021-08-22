/* euclid_algorithm.c

   This program accepts two numbers
   from the user and prints their
   gcd by Euclid's algorithm.

   Author: Adarsh
*/
# include <stdio.h>
# include <math.h>

int max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}

int min(int x, int y)
{
    if (x < y)
        return x;
    return y;
}

int euclid_step(int x, int y)
{
    int t1, t2, t;

    do
    {
        t1 = max(x, y);
        t2 = min(x, y);

        t = t1 % t2;
        x = t2;
        y = t;
    }
    while (t != 0);
    return t2;
}

int main()
{
    int a, b, c;

    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);

    c = euclid_step(a, b);

    printf("a = %d, b = %d\n", a, b);
    printf("HCF = %d", c);
    return 0;
}
