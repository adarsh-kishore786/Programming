// digit_sum.c
// This program accepts an integer and
// prints the sum of its digits
// Author: Adarsh, Date: 08/09/2020

# include <stdio.h>

int main()
{
    int num, num2;
    int sum = 0;

    printf("Enter a number:\n");
    scanf("%d", &num);
    num2 = num;

    do
    {
        sum += num2 % 10;
        num2 /= 10;
    }
    while (num2 != 0);

    printf("Sum of digits of %d: %d", num, sum);
    return 0;
}
