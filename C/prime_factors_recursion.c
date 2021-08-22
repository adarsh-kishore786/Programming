/* prime_factors_recursion.c

   This program accepts a number from
   the user and prints its prime factors
   using recursion.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

int is_prime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void prime_factors(int num)
{
    if (is_prime(num))
    {
        printf("%d\n", num);
        return;
    }

    int n = 1;
    for (int i = 2; i <= num; i++)
    {
        if (num % i == 0 && is_prime(i))
        {
            n = i;
            break;
        }
    }
    printf("%d\n", n);
    prime_factors(num / n);
}

int main()
{
    int num;

    printf("Enter a number:\n");
    scanf("%d", &num);

    printf("Prime factors of %d:\n", num);
    prime_factors(num);

    return 0;
}

