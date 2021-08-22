/* menu.c

   This program can do various things
   like calculate factorial of a
   number, if it is prime or not, if
   it is odd or even.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>
# include <stdlib.h> // This contains exit() function

int factorial(int num)
{
    int p = 1;

    for (int i = 1; i <= num; i++)
        p *= i;
    return p;
}

int is_prime(int num)
{
    int is_prime = 1;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            is_prime = 0;
            break;
        }
    }
    return is_prime;
}

int is_even(int num)
{
    return num % 2 == 0;
}

int main()
{
    int num;
    int ch;

    do
    {
        printf("Enter your choice:\n");
        printf("1. Factorial of the number\n");
        printf("2. Number is prime or not\n");
        printf("3. Number is odd or even\n");
        printf("4. Exit\n");
        scanf(" %d", &ch);

        if (ch != 4)
        {
            printf("Enter a number:\n");
            scanf(" %d", &num);
        }

        switch(ch)
        {
            case 1: printf("Factorial of %d: %d"
                        , num, factorial(num));
                    break;

            case 2: if (is_prime(num))
                        printf("%d is prime.", num);
                    else
                        printf("%d is not prime.", num);
                    break;

            case 3: if (is_even(num))
                        printf("%d is even.", num);
                    else
                        printf("%d is odd.", num);
                    break;
            default: printf("Exiting...");
                     exit(0);
        }
        printf("\n\n");
    } while (ch != 4);
    return 0;
}
