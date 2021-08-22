/* power_of_point.c

   This program accepts the coordinates of
   the centre of a circle and its radius,
   and the coordinates of another point.
   Then it determines whether the point lies
   inside, on, or outside the circle.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

int main()
{
    float centre_x, centre_y;
    float radius;
    float point_x, point_y;
    float power_of_point;

    printf("Enter the coordinates of centre of circle:\n");
    scanf(" (%f, %f)", &centre_x, &centre_y);

    printf("Enter the radius of the circle:\n");
    scanf(" %f", &radius);

    printf("Equation of circle is:\n");
    printf("(x - %f)^2 + (y - %f)^2 = %f\n\n", centre_x, centre_y, radius*radius);

    printf("Enter the coordinates of a point:\n");
    scanf(" (%f, %f)", &point_x, &point_y);

    power_of_point = pow((point_x - centre_x), 2) + pow((point_y - centre_y), 2)
                    - pow(radius, 2);

    if (power_of_point < 0)
        printf("\nThe point lies inside the circle.");
    else if (power_of_point == 0)
        printf("\nThe point lies on the circle.");
    else
        printf("\nThe point lies outside the circle.");

    return 0;
}
