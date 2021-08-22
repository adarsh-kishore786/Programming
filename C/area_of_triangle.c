// area_of_triangle.c
// This program accepts the sides of a triangle
// and prints the area of the triangle after
// checking that the sides indeed for a triangle

// Author: Adarsh

#include <stdio.h>
#include <math.h>
int is_triangle(int a, int b, int c)
{
    int is_triangle = 1;

    if ((a + b < c) || (b + c < a) || (c + a < b)
        || (a < 0) || (b < 0) || (c < 0))
    {
        is_triangle = 0;
    }
    return is_triangle;
}

float area_of_triangle(int a, int b, int c)
{
    float s = (a + b + c) / 2.0;
    float s1 = s - a;
    float s2 = s - b;
    float s3 = s - c;

    float area = pow(s * s1 * s2 * s3, 0.5);
    return area;
}

int main()
{
    int a, b, c;

    printf("Enter the sides of the triangle:\n");
    scanf("%d, %d, %d", &a, &b, &c);

    if (is_triangle(a, b, c) == 0)
    {
        printf("The sides %d, %d, %d do not form a triangle.",
               a, b, c);
    }
    else
    {
        printf("Sides of triangle are: %d, %d, %d", a, b, c);
        printf("\nArea of the triangle: %f", area_of_triangle(a, b, c));
    }

    return 0;
}
