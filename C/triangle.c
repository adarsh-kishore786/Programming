/* triangle.c

   This program accepts the vertices of
   a triangle and a point and finds if
   the point lies inside or outside the triangle.

   Author: Adarsh
*/

# include <stdio.h>
# include <math.h>

void area_of_triangle(float d1, float d2, float d3,
                      float *area)
{
    float s = (d1 + d2 + d3) / 2;

    *area = sqrt(s * (s - d1) * (s - d2) * (s - d3));
}

void dist(float x1, float y1, float x2,
          float y2, float *dist)
{
    *dist = sqrt( pow(x2 - x1, 2) + pow(y2 - y1, 2) );
}

int inside_or_outside(float x, float y, float x1, float y1,
                      float x2, float y2, float x3,
                      float y3)
{
    float d12, d23, d31, d1, d2, d3;
    float area, a12, a23, a31;

    dist(x1, y1, x2, y2, &d12);
    dist(x2, y2, x3, y3, &d23);
    dist(x3, y3, x1, y1, &d31);

    dist(x, y, x1, y1, &d1);
    dist(x, y, x2, y2, &d2);
    dist(x, y, x3, y3, &d3);

    area_of_triangle(d12, d23, d31, &area);
    area_of_triangle(d1, d2, d12, &a12);
    area_of_triangle(d2, d3, d23, &a23);
    area_of_triangle(d3, d1, d31, &a31);

    float a = a12 + a23 + a31;

    if (round(a) == round(area))
        return 1;
    return 0;
}

int main()
{
    float x1, y1, x2, y2, x3, y3, x, y;
    float d12, d13, d23;
    float area;

    printf("Enter the vertices of a triangle:\n");
    scanf(" (%f, %f) (%f, %f) (%f, %f)", &x1, &y1,
                &x2, &y2, &x3, &y3);

    dist(x1, y1, x2, y2, &d12);
    dist(x2, y2, x3, y3, &d23);
    dist(x1, y1, x3, y3, &d13);
    area_of_triangle(d12, d23, d13, &area);

    printf("Distance between (%f, %f) and (%f, %f): %f\n",
            x1, y1, x2, y2, d12);
    printf("Distance between (%f, %f) and (%f, %f): %f\n",
            x2, y2, x3, y3, d23);
    printf("Distance between (%f, %f) and (%f, %f): %f\n\n",
            x3, y3, x1, y1, d13);

    printf("Area of triangle: %f sq. units\n", area);

    printf("Enter a point:\n");
    fflush(stdin);
    scanf(" (%f, %f)", &x, &y);

    if (inside_or_outside(x, y, x1, y1, x2, y2, x3, y3))
        printf("The point lies inside the triangle.\n");
    else
        printf("The point lies outside the triangle.\n");

    return 0;
}
