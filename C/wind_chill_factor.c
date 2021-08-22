/* wind_chill_factor.c

   This program accepts the air temperature and
   wind velocity and calculates the wind chill
   factor.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

int main()
{
    float temp, v;

    printf("Enter the temperature and wind velocity:\n");
    scanf("%f, %f", &temp, &v);

    float wcf = 35.74 + 0.6215 * temp +
                (0.4275 * temp - 35.75) * pow(v, 0.16);

    printf("The wind chill factor is %f", wcf);
    return 0;
}
