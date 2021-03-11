/* person.c

   This program creates a struct
   which stores biodata of a 
   person.

   Author: Adarsh
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person
{
	int age;
	char *name;
};

int main()
{
    struct person em;

    em.age = 32;
    em.name = malloc(6 * sizeof(char));
    strcpy(em.name, "Brian");

    printf("Type 1: Dot notation without pointers:\n");
    printf("Name: %s\n", em.name);
    printf("Age : %d\n\n", em.age);

    struct person *em_ptr = &em;

    (*em_ptr).age = 33;
    (*em_ptr).name = realloc((*em_ptr).name, 7 * sizeof(char));
    strcpy((*em_ptr).name, "Brian!");

    printf("Type 2: Dot notation with pointers:\n");
    printf("Name: %s\n", (*em_ptr).name);
    printf("Age : %d\n\n", (*em_ptr).age);

    em_ptr->age = 34;
    em_ptr->name = realloc(em_ptr->name, 8 * sizeof(char));
    strcpy(em_ptr->name, "Brian!!");

    printf("Type 3: Arrow notation with pointers:\n");
    printf("Name: %s\n", em_ptr->name);
    printf("Age : %d\n", em_ptr->age);
}