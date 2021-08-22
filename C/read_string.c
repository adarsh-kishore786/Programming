/* read_string.c

   This program demonstrates how to
   take input a string from the
   user.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    char name[25];

    printf("Enter your name:\n");
    scanf("%[^\n]s", name); // This can accept multiwords
    fflush(stdin);

    printf("\nHello %s!", name);


    // scanf cannot be used for multiword strings.
    // For that we use gets()

    printf("\nEnter full name:\n");
    gets(name);

    printf("Hello %s!", name);
}
