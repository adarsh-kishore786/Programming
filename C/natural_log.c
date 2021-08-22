/* natural_log.c

   This program accepts a value from
   a user and computes its natural logarithm
   using series expansion.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

float ln(float x)
{
   float y = x - 1;

   float sum = 0;
   for (int i = 1; i <= 10; i++)
   {
       float term = pow(y, i) / i;
       if (i % 2 == 0)
           sum -= term;
       else
           sum += term;
   }
   return sum;
}

int main()
{
    float x;

    printf("Enter a number whose natural log is to ");
    printf("be found:\n");
    scanf(" %f", &x);

    printf("You entered: %f", x);
    printf("\n");

    float val = ln(x);
    printf("\nln(%f)                 = %f", x, val);
    printf("\nActual value of ln(%f) = %f\n", x, log(x));
    return 0;
}
