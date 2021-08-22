/* prime.c

   This program prints all the prime numbers
   from 1 to a limit given by the user.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

int is_prime(int num)
{
    int lim = round(sqrt(num));
    int is_prime = 1;

    if (num <= 1)
        return 0;

    for (int i = 2; i <= lim; i++)
    {
        if (num % i == 0)
        {
            is_prime = 0;
            break;
        }
    }
    return is_prime;
}

int main()
{
    int lim;
    printf("Enter an upper limit greater than 1:\n");
    scanf(" %d", &lim);

    printf("\nPrime numbers from 1 to %d", lim);
    for (int i = 1; i <= lim; i++)
    {
        int p = is_prime(i);

        if (p)
            printf("%d\n", i);
    }
}
