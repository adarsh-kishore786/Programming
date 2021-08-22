/* print_string.c

   This program demonstrates how to
   declare and print strings.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    char name[] = "Klinsman";
    int i = 0;
    while (i <= 7)
    {
        printf("%c", name[i]);
        i++;
    }
    printf("\n");
    i = 0;
    while ( name[i] != '\0')
    {
        printf("%c", name[i]);
        i++;
    }
    printf("\n");

    i = 0;
    while ( *(name + i) != '\0' )
    {
        printf("%c", *(name + i));
        i++;
    }

    printf("\n%s", name); // Best way
}
