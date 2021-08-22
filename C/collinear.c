/* collinear.c

   This program accepts the coordinates of
   three points and then determines if the
   points lie in a straight line or not.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    float x1, x2, x3, y1, y2, y3;

    printf("Enter the coordinates of three points:\n");
    scanf(" (%f, %f) (%f, %f) (%f, %f)", &x1, &y1,
                &x2, &y2, &x3, &y3);

    printf("The points you entered are:\n");
    printf("(%f, %f), (%f, %f), (%f, %f)\n\n",
                x1, y1, x2, y2, x3, y3);

    float same = 0;
    float collinear = 0;

    if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3)
        || (x3 == x1 && y3 == y1))
        same = 1;

    else if (x1 == x2 && x2 == x3)
        collinear = 1;
    else if (x1 != x2 && x2 != x3)
    {
        float m12 = (y2 - y1) / (x2 - x1);
        float m23 = (y3 - y2) / (x3 - x2);

        if (m12 == m23)
            collinear = 1;
    }

    if (same != 1)
    {
        if (collinear == 1)
            printf("The given points are collinear.");
        else
            printf("The given points are not collinear.");
    }
    else
        printf("At least two points are the same.");

    return 0;
}
