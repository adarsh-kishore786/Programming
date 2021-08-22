/* variable_string_input_length.c

   This program demonstrates how to take input
   of a variable length string.

   Author: Adarsh
*/

# include <stdio.h>
# include <stdlib.h>
# include "util.c"

int main()
{
    int len_max = 128;
    int curr_length = len_max;

    char *str = (char*)malloc(curr_length * sizeof(char));

    printf("Enter a string of any size:\n");

    int c = EOF;
    int i = 0;

    while (i < 100)
    {
        str[i] = getchar();
        i++;
        /*if (i == curr_length)
        {
            curr_length += len_max;
            str = (char*) realloc(str, curr_length * sizeof(char));
        }*/
        printf("%c", str[i]);
    }
    str[i] = '\0';

    printf("The string:\n");
    print_pointer(str);

}

