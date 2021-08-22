/* trig_sum.c

   This program accepts an angle from
   the user in degrees, finds the sine
   and cosine of the angle, and checks if
   their sum is 1.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

pi = 3.14159;

float to_radians(float angle)
{
    return angle * pi / 180;
}

int main()
{
    float angle;

    printf("Enter an angle in degrees:\n");
    scanf(" %f", &angle);

    float rad = to_radians(angle);
    float sine = sin(rad);
    float cosine = cos(rad);

    float sum = pow(sine, 2) + pow(cosine, 2);

    printf("\nsin(%f) = %f", angle, sine);
    printf("\ncos(%f) = %f", angle, cosine);
    printf("\nsin^2(%f) + cos^2(%f) = %f\n", angle, angle, sum);

    if (round(sum) == 1)
        printf("\nSum is indeed 1.");
    else
        printf("\nWhat on Earth happened?");

    return 0;
}
