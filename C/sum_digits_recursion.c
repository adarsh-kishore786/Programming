/* sum_digits_recursion.c

   This program accepts a number from
   the user and calculates the sum of its
   digits using recursion.

   Author: Adarsh
*/

# include <stdio.h>

int sum(int num)
{
    int digit = num % 10;

    if (num < 10)
        return digit;
    return digit + sum(num / 10);
}

int main()
{
    int num;

    printf("Enter a number:\n");
    scanf("%d", &num);

    int s = sum(num);

    printf("Sum of digits: %d", s);
}
