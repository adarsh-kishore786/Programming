/* average_marks.c

   This program accepts the marks of 5
   different students from the user
   and prints the average marks obtained.
   It makes use of the concept of array.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    int avg, sum = 0;
    int i;
    int marks[30];

    for (i = 0; i <= 4; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &marks[i]);
    }

    for (i = 0; i <= 4; i++)
        sum += marks[i];
    avg = sum / 5.0;

    printf("Average marks obtained: %d", avg);
    return 0;
}
