/* array_function.c

   This program demonstrates passing
   an array to a function.

   Author: Adarsh
*/

# include <stdio.h>

void display1(int* j, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        printf("element = %d\n", *j);
        j++;
    }
}

void display2(int j[], int n)
{
    for (int i = 0; i <= n - 1; i++)
        printf("element = %d\n", j[i]);
}

int main()
{
    int num[] = {24, 34, 12, 44, 56, 17};
    display1(num, 6);
    printf("\n");
    display2(num, 6);
    printf("\n");

    for (int i = 0; i <= 5; i++)
    {
        printf("Address = %u %u", &num[i], num + i);
        printf(" %u\n", i + num);
        printf("Element = %d %d", num[i], *(num + i));
        printf(" %d %d\n", *(i + num), i[num]);
    }
}
