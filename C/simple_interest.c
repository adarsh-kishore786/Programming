/* Calculation of simple interest */
/* Author: Adarsh Date: 05/09/2020 */
# include <stdio.h>

int main()
{
    int p, n;
    float r, si;

    p = 1000;
    n = 3;
    r = 8.5;

    /* Formula for simple interest */

    si = n * p * r / 100;
    printf("%f\n", si);
    printf("%d, %d\n", p, n);
    printf("%c", 65); // Prints 'A'
    return 0;
}
