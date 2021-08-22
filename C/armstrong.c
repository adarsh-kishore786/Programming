/* armstrong.c

   This program prints all the Armstrong
   numbers from 1 to 500.

   Authror: Adarsh
*/

# include <stdio.h>
# include <math.h>

int sum_cubes(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += pow(n % 10, 3);
        n /= 10;
    }
    return sum;
}

int main()
{
    int num = 1;

    while (num <= 500)
    {
        int sum = sum_cubes(num);
        if (sum == num)
            printf("%d\n", num);
        num++;
    }
    return 0;
}
