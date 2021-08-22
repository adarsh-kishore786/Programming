/* the_arrow_operator.c

   This program demonstrates the use
   of the membership operator ->.
   p -> a is equivalent to (*p).a.
   It is used in pointer to a structure.

   Author: Adarsh
*/

#include <stdio.h>

struct book
{
    char name[25];
    char author[25];
    int callno;
};

void display1(char *s, char *t, int n)
{
    printf("%s %s %d\n", s, t, n);
}

void display2(struct book b)
{
    printf("%s %s %d\n", b.name, b.author, b.callno);
}

void display3(struct book *pb)
{
    printf("%s %s %d\n", pb->name, pb->author, pb->callno);
    printf("%s %s %d\n", (*pb).name, (*pb).author, (*pb).callno);
    // Equivalent representation
}

int main()
{
    struct book b1 = {"Let Us C", "YPK", 101};
    display1(b1.name, b1.author, b1.callno);
    display2(b1);
    display3(&b1);
}
