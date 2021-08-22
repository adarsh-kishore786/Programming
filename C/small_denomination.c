/* small_denomination.c

   Consider a currency system in which there
   are notes of denomination Re. 1, Rs. 2,
   Rs. 5, Rs. 10, Rs. 50, Rs. 100.

   The program accepts an input currency from
   the user and prints the smallest number of
   notes required to represent the currency.

   Author: Adarsh
*/

# include <stdio.h>

void notes(int rup)
{
    int n1, n2, n5, n10, n50, n100;

    int r = rup;

    n100 = r / 100;
    r -= 100 * n100;

    n50 = r / 50;
    r -= 50 * n50;

    n10 = r / 10;
    r -= 10 * n10;

    n5 = r / 5;
    r -= 5 * n5;

    n2 = r / 2;
    r -= 2 * n2;

    n1 = r;

    int sum = n1 + n2 + n5 + n10
              + n50 + n100;
    printf("The smallest way requires %d notes\n", sum);
    printf("Re. 1 : %d, Rs. 2 : %d, Rs. 5  : %d\n", n1, n2, n5);
    printf("Rs. 10: %d, Rs. 50: %d, Rs. 100: %d", n10, n50, n100);
}

int main()
{
    int r;

    printf("Enter amount of Rs:\n");
    scanf("%d", &r);

    printf("Amount entered: %d\n", r);
    notes(r);

    return 0;
}
