// salary.c
// A program to print the salary of a person
// taking into account the DA and HRA
// Author: Adarsh, Date: 06/09/2020

# include <stdio.h>

int main()
{
    float bs, da, hra, ts;

    printf("Enter basic salary:\n");
    scanf("%f", &bs);

    da = 0.4 * bs;
    hra = 0.2 * bs;
    ts = bs + da + hra;

    printf("\nBasic salary: %f\n", bs);
    printf("Dearness allowance: %f\n", da);
    printf("House rent allowance: %f\n", hra);
    printf("Total salary: %f", ts);
    return 0;
}
