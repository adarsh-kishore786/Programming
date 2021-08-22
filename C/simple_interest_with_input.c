// A program to calculate simple interest
// It can take input from user.
// Author: Adarsh, Date: 05/09/2020

# include <stdio.h>

int main()
{
    int p, n;
    float r, si;

    printf("Enter values of p, n, r:\n");
    scanf("%d, %d, %f", &p, &n, &r);

    si = p * r * n / 100;

    printf("\nSimple Interest: Rs. %f", si);
    return 0;
}
