/* salary2.c

   This program accepts the gender,
   years of service and qualification
   of the user and finds the salary to be
   given to him/her.

   Author: Adarsh
*/

#include <stdio.h>

int main()
{
    char g;
    int yos;
    int qual;
    int salary;

    printf("Enter gender of employee:\n");
    scanf(" %c", &g);

    printf("Enter years of service:\n");
    scanf(" %d", &yos);

    printf("Enter qualification (0 = G, 1 = PG):\n");
    scanf(" %d", &qual);

    if (g == 'M')
    {
        if (yos >= 10 && qual == 1)
            salary = 15000;
        else if (yos >= 10 && qual == 0)
            salary = 10000;
        else if (yos < 10 && qual == 1)
            salary = 10000;
        else if (yos < 10 && qual == 0)
            salary = 7000;
    }
    else
    {
        if (yos >= 10 && qual == 1)
            salary = 12000;
        else if (yos >= 10 && qual == 0)
            salary = 9000;
        else if (yos < 10 && qual == 1)
            salary = 10000;
        else if (yos < 10 && qual == 0)
            salary = 6000;
    }

    printf("Salary: Rs. %d", salary);
    return 0;
}
