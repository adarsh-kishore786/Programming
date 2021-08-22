/* areaperi.c

   This program makes use of the
   macros defined in areaperi.h to
   calculate the area and perimeter
   of various shapes.

   Author: Adarsh
*/

# include <stdio.h>
# include "areaperi.h"

int main()
{
    int r = 3;

    printf("Area of a circle of radius %d: %.2f\n", r, AREA_CIRCLE(r));
    printf("Perimeter of circle of radius %d: %.2f\n", r, CIRCUMFERENCE(r));

    int a = 3, b = 4, c = 5;
    printf("Area of a %d-%d-%d triangle: %.2f\n", a, b, c, AREA_TRIANGLE(a, b, c));
    printf("Perimeter of a %d-%d-%d triangle: %f\n", a, b, c, PERI_TRIANGLE(3, b, c));
}
