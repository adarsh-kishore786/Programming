#include <stdio.h>
#include "functions.h"

int main()
{
    printf("%d\n", add(2, 0));

    printf("%d\n", ADD(2, 0));

    person engineer_man;
    engineer_man.age = 32;

    printf("Engineer man's age is: %d\n", engineer_man.age);
}
