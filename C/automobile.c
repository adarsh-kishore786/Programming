/* automobile.c

   This program creates a database
   for various models of an
   automobile.

   Author: Adarsh
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct engine
{
    char *s_no;
    int year_of_manufacture;
    char *material;
    int quantity;
};

int hex_to_decimal(char hex[])
{
    int sum = 0;
    int l = strlen(hex);

    for (int i = 0; i < l; i++)
    {
        char c = hex[i];
        int val;

        switch (c)
        {
            case '0': val = 0; break;
            case '1': val = 1; break;
            case '2': val = 2; break;
            case '3': val = 3; break;
            case '4': val = 4; break;
            case '5': val = 5; break;
            case '6': val = 6; break;
            case '7': val = 7; break;
            case '8': val = 8; break;
            case '9': val = 9; break;
            case 'A': val = 10; break;
            case 'B': val = 11; break;
            case 'C': val = 12; break;
            case 'D': val = 13; break;
            case 'E': val = 14; break;
            case 'F': val = 15; break;
        }

        sum += pow(16, l - i - 1) * val;
    }
    return sum;
}

void decimal_to_hex(int val, char *c)
{
    int i = 2;
    while (val != 0)
    {
        int d = val % 16;

        switch (d)
        {
            case 0: c[i] = '0'; break;
            case 1: c[i] = '1'; break;
            case 2: c[i] = '2'; break;
            case 3: c[i] = '3'; break;
            case 4: c[i] = '4'; break;
            case 5: c[i] = '5'; break;
            case 6: c[i] = '6'; break;
            case 7: c[i] = '7'; break;
            case 8: c[i] = '8'; break;
            case 9: c[i] = '9'; break;
            case 10: c[i] = 'A'; break;
            case 11: c[i] = 'B'; break;
            case 12: c[i] = 'C'; break;
            case 13: c[i] = 'D'; break;
            case 14: c[i] = 'E'; break;
            case 15: c[i] = 'F'; break;
        }
        val /= 16;
        i--;
    }
}

int main()
{
    int l;
    struct engine *engines;
    int start, end;

    start = hex_to_decimal("AA0");
    end = hex_to_decimal("FF9");

    l = end - start; // From AA0 to FF9
    engines = malloc(l * sizeof(struct engine));

    for (int i = start; i <= end; i++)
    {
    	char c[] = "ABC";
    	decimal_to_hex(i, c);

    	int d = i - start;

    	(engines + d)->s_no = malloc(4 * sizeof(char));
    	(engines + d)->material = malloc(6 * sizeof(char));

        strcpy((engines + d)->s_no, c);
        (engines + d)->year_of_manufacture = 2010;
        strcpy((engines + d)->material, "Iron");
        (engines + d)->quantity = 10;
    }

    for (int i = hex_to_decimal("BB1"); i <= hex_to_decimal("CC6"); i++)
    {
        int d = i - start;
        struct engine e = *(engines + d);
        printf("Information of model %s:\n", e.s_no);
        printf("Serial number      : %s\n", e.s_no);
        printf("Year of manufacture: %d\n", e.year_of_manufacture);
        printf("Material           : %s\n", e.material);
        printf("Quantity           : %d\n\n", e.quantity);
    }
}
