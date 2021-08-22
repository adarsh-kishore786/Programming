/* string_functions.c

   This program demonstrates various
   string functions.

   Author: Adarsh
*/

# include <stdio.h>
# include <string.h>

int print_pointer(char *p)
{
    int i = 0;
    while (*(p + i) != '\0')
    {
        printf("%c", *(p + i));
        i++;
    }
    return i;
}

void change_back(char str[])
{
    str[0] = 'H';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    str[5] = '\0';
}

int main()
{
    char str[] = "Hello";
    char *pstr = str;

    printf("The string: %s\n", str);

    printf("The string using pointer: ");
    int i = print_pointer(pstr);
    printf("\n");

    printf("The length of the string: %d\n", strlen(str));
    printf("The length using pointers: %d\n", i);

    printf("The string in lowercase: %s\n", strlwr(str));
    //str = strlwr(str); //error
    pstr = strlwr(str);
    printf("The string in lowercase using pointer: ");
    print_pointer(pstr);
    printf("\n");

    printf("The string in uppercase: %s\n", strupr(str));
    pstr = strupr(str);
    printf("The string in uppercase using pointer: ");
    print_pointer(pstr);
    printf("\n");

    change_back(str);

    char str1[] = " World!";
    printf("Another string: %s\n", str1);
    printf("Appending the second to the first: %s\n", strcat(str, str1));
    change_back(str);
    printf("Appending some characters of second to first: %s\n", strncat(str, str1, 2));
}
