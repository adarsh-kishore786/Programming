/* call_by_reference.c

   This program demonstrates an important
   use of call by reference using pointers.
   It can change more than one value at
   multiple address. Thus, in effect, it is
   returning more than one value.

   Author: Adarsh
*/
# include <stdio.h>

void area_cir(float r, float *ar, float *cir)
{
   *ar = 3.14 * r * r;
   *cir = 2 * 3.14 * r;
}

int main()
{
    float radius, area, cir;

    printf("Enter the radius of the circle:\n");
    scanf( "%f", &radius);

    area_cir(radius, &area, &cir);

    printf("Radius: %f\n", radius);
    printf("Area: %f\n", area);
    printf("Circumference: %f\n", cir);

    return 0;
}
