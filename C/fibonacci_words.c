/* fibbonaci_words.c

   This program prints the fibonacci
   sequence starting with two terms
   entered by user.

   Author: Adarsh
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fibonacci(char* f_0, char* f_1, int count)
{
    if (count == 0)
        return;

    printf("%s ", f_1);
    char *f_temp = f_1;
    strcat(f_1, f_0);
    f_0 = f_temp;
    fibonacci(f_0, f_1, count - 1);
}

int main()
{
    char *f_0 = malloc(100*sizeof(char));
    char *f_1 = malloc(100*sizeof(char));
    int n;

    printf("Enter the first character of the sequence:\n");
    gets(f_0);

    printf("Enter the second character of the sequence:\n");
    gets(f_1);

    printf("Enter number of terms:\n");
    scanf("%d", &n);

    printf("The Fibonacci Series with these initial conditions:\n");
    printf("%s ", f_0);
    fibonacci(f_0, f_1, n);
}
