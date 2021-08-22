/* circular_shift.c

   This program accepts three numbers
   (x, y, z) from the user and does a
   circular shift on them, i.e, changes
   to (y, z, x).

   Author: Adarsh
*/

# include <stdio.h>

void circular_shift(int *x, int *y, int *z)
{
    int t1 = *x, t2 = *y, t3 = *z;
    *x = t2;
    *y = t3;
    *z = t1;
}

int main()
{
    int x, y, z;
    int a, b, c;

    printf("Enter three numbers:\n");
    scanf("%d %d %d", &x, &y, &z);

    a = x;
    b = y;
    c = z;

    circular_shift(&x, &y, &z);

    printf("Original tuple: (%d, %d, %d)\n", a, b, c);
    printf("New tuple     : (%d, %d, %d)", x, y, z);

    return 0;
}
