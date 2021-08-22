/* str_extract.c

   This program accepts a given string
   from the user. It then extracts a
   substring out of it with specified
   length and starting point.

   Author: Adarsh
*/

# include <stdio.h>
# include <stdlib.h>

void extract(char str[], int pos, int length, char *pstr)
{
    int i = pos;
    while (i - pos < length)
    {
        if (str[i] == '\0')
        {
            *(pstr + i - pos) = '\0';
            return;
        }
        *(pstr + i - pos) = str[i];
        i++;
    }
    *(pstr + length) = '\0';
}

void print_pointer(char *pstr)
{
    int i = 0;
    while (*(pstr + i) != '\0')
    {
        printf("%c", *(pstr + i));
        i++;
    }
}

int main()
{
    int pos, length;
    char str[1];

    printf("Enter a string:\n");
    gets(str);
    fflush(stdin);

    printf("Enter position and length of string to be extracted:\n");
    scanf("%d %d", &pos, &length);

    char *pstr = (char*) malloc(length * sizeof(char));
    extract(str, pos, length, pstr);
    printf("The extracted string:\n");
    print_pointer(pstr);
}
