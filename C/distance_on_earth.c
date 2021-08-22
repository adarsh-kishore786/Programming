/* distance_on_earth.c
   This program accepts the latitude and
   longitude of two places on the earth in
   degrees and outputs the distance
   between them on the surface of earth in
   miles.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

int main()
{
    float l1, l2;
    float g1, g2;

    printf("Enter the coordinates of two places in the form\n");
    printf("(latitude, longitude) where both are in degrees:\n");
    scanf("(%f, %f) (%f, %f)", &l1, &g1, &l2, &g2);

    float dist = 3963 * acos(sin(l1) * sin(l2) +
                       cos(l1) * cos(l2) * cos(g2 - g1));

    printf("The two places are:\n");
    printf("(%f, %f), (%f, %f)", l1, g1, l2, g2);
    printf("\nThe distance between them is %f miles", dist);
    return 0;
}
