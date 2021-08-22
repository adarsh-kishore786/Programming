/* pythagorean_tripes.c

   This program prints all the pythagorean
   triples with side length less than a limit
   entered by the user.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

int main()
{
    int a, b, c, t, l;

    printf("Enter a limit:\n");
    scanf("%d", &l);

    printf("Pythagorean triples upto %d:\n", l);
    for (t = 2; (pow(t, 2) + 1) <= l; t++)
    {
        a = pow(t, 2) - 1;
        b = 2 * t;
        c = pow(t, 2) + 1;

        printf("(%d, %d, %d)\n", a, b, c);
    }
}
