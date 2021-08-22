/* sum_avg_stddev.c

   This program accepts 5 numbers from
   the user and prints their sum, average
   and standard deviation. It uses call
   by reference.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

void sum_avg_dev(int a, int b, int c, int d, int e,
                 int *sum, float *avg, float *dev)
{
    *sum = a + b + c + d + e;
    *avg = *sum / 5;

    float d1 = pow((a - *avg), 2);
    float d2 = pow((b - *avg), 2);
    float d3 = pow((c - *avg), 2);
    float d4 = pow((d - *avg), 2);
    float d5 = pow((e - *avg), 2);

    *dev = sqrt((d1 + d2 + d3 + d4 + d5) / 5);
}

int main()
{
    int a, b, c, d, e;
    int sum;
    float avg, std_dev;

    printf("Enter five numbers:\n");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    sum_avg_dev(a, b, c, d, e, &sum, &avg, &std_dev);

    printf("Sum       = %d\n", sum);
    printf("Average   = %f\n", avg);
    printf("Std. Dev. = %f\n", std_dev);

    return 0;
}
