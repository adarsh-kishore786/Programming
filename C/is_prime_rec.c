/*
    is_prime_rec.c

    This program inputs a number from the user
    and prints whether it is prime or not, using
    recursion.
*/

#include <stdio.h>

int num_factors(int, int);
int is_prime(int);

int main()
{
    int n;
    printf("Enter a number: ");
    fscanf(stdin, "%d", &n);
    
    if (is_prime(n))
        printf("%d is prime.\n", n);
    else
        printf("%d is not prime.\n", n);
}

int num_factors(int n, int div_)
{
    if (n == 1)
        return 0;
        
    if (div_ > n)
       return 0;
    
    if (n % div_ == 0)
        return 1 + num_factors(n, div_ + 1);
    return num_factors(n, div_ + 1);
}

int is_prime(int n)
{
    if (num_factors(n, 2) == 1)
        return 1;
    return 0;
}
