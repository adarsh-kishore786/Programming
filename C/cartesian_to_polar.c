/* cartesian_to_polar.c
   The program accepts a given ordered
   pair (x, y) in the Cartesian coordinate
   system and outputs its equivalent
   representation in the polar coordinate
   system.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

float angle(float x, float y)
{
    float pi = 3.1415926535;
    if (x == 0)
    {
        if (y > 0)
        {
            return pi / 2;
        }
        else if (y < 0)
        {
            return -pi / 2;
        }
        else
        {
            return -10;
        }
    }
    else
    {
        float theta = atan(fabs(y) / fabs(x));

        if (x < 0 && y > 0)
        {
            theta = pi - theta;
        }
        else if (x < 0 && y < 0)
        {
            theta -= pi;
        }
        else if (x > 0 && y < 0)
        {
            theta = -theta;
        }
        return theta;
    }
}

int main()
{
    float x, y;

    printf("Enter an ordered pair in Cartesian coordinates:\n");
    scanf("(%f, %f)", &x, &y);

    float r = pow((x * x + y * y), 0.5);

    printf("You entered (%f, %f)", x, y);
    printf("\nThe equivalent representation in polar");
    printf(" coordinates is (%f, %f)", r, angle(x, y));
    return 0;
}
