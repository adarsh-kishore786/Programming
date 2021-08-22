/* cpreprocessor_define.c

   This program demonstrates the use
   of the define keyword. (A macro)

   Author: Adarsh
*/

# include <stdio.h>

# define PI 3.141592
# define AND &&
# define OR ||
# define FOUND printf("It's found\n");
# define E 2.7182818
# define PROD (PI * E)

# define AREA(x)(PI*x*x)
# define CIRCUM(x)(2*PI*x)

# define ISDIGIT(y)(y >= 48 AND y <= 57)
# define HLINE for (int i = 0; i <= 79; i++) \
               { \
                    printf("%c", 196); \
               } \
               printf("\n");
int main()
{
    int r = 5;
    char c = 'a';

    printf("Radius = %f\n", r);
    printf("Circumference = %f\n", CIRCUM(r));
    printf("Area = %f\n", AREA(r));

    HLINE;

    if (((2 > 1) AND (r == 5)) OR (56))
        FOUND;
    printf("e = %f\n", E);
    printf("pi*e = %f\n", PROD);

    printf("%d\n", ISDIGIT(c));

    return 0;
}
