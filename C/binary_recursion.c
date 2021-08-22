/* binary_recursion.c

   This program accepts a number from
   the user and prints its binary
   equivalent using recursion.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

int power_of_two(int num)
{
    int n = 1;
    while (pow(2, n) <= num)
        n++;
    return n-1;
}

void binary(int num, int power)
{
    if (power == 0)
    {
        printf("%d\n", num);
        return;
    }

    int p = pow(2, power);
    printf("%d", num / p);
    binary(num % p, power - 1);
}

int main()
{
    int num;

    printf("Enter a number:\n");
    scanf("%d", &num);

    int power = power_of_two(num);
    printf("%d in binary:\n", num);
    binary(num, power);

    return 0;
}
