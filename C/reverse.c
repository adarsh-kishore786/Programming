// reverse.c
// This program accepts an integer
// and prints the number after reversing the digits
// Author: Adarsh, Date: 08/09/2020

# include <stdio.h>
# include <math.h>

int n_digits(int n)
{
    int i = 0;
    int n1 = n;

    while (n1 != 0)
    {
        i += 1;
        n1 /= 10;
    }

    return i;
}

int reverse_num(int n)
{
    int n_d = n_digits(n);
    int i = 1;
    int rev = 0;
    int num = n;

    while (i <= n_d)
    {
        rev += (int)(pow(10, i-1)) * (num / (int)(pow(10, n_d - i)));
        num %= (int)pow(10, n_d - i);
        i += 1;
    }

    return rev;
}

int main()
{
    int num;

    printf("Enter a number:\n");
    scanf("%d", &num);

    printf("The number: %d\n", num);
    printf("Number of digits in %d: %d\n", num, n_digits(num));
    printf("Reverse of %d: %d", num, reverse_num(num));

    return 0;
}
