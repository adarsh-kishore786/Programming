/* student_structure.c

   This program creates a structure
   named student which stores some
   details of students like roll no,
   name, department, course, year of
   joining.

   Author: Adarsh
*/

#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    char name[25];
    char department[25];
    char course[25];
    int year_of_joining;
};

void input(struct student *s, int l)
{
    printf("Enter details of each student:\n");

    for (int i = 0; i < l; i++)
    {
        printf("Student %d\n", i+1);

        printf("Roll      : ");
        scanf(" %d", &((s+i)->roll));
        fflush(stdin);

        printf("Name      : ");
        gets((s+i)->name);
        fflush(stdin);

        printf("Department: ");
        gets((s+i)->department);
        fflush(stdin);

        printf("Course    : ");
        gets((s+i)->course);
        fflush(stdin);

        printf("Y.O.J     : ");
        scanf(" %d", &((s+i)->year_of_joining));
        fflush(stdin);
        printf("\n");
    }
}

void print_struct(struct student s)
{
    printf("Roll no   : %d\n", s.roll);
    printf("Name      : %s\n", s.name);
    printf("Department: %s\n", s.department);
    printf("Course    : %s\n", s.course);
    printf("Y.O.J.    : %d\n\n", s.year_of_joining);
}

void print_structs(struct student *s, int l)
{
    printf("Details of each student:\n");
    for (int i = 0; i < l; i++)
    {
        printf("Student %d\n", i+1);
        print_struct(*(s+i));
    }
}

struct student find(struct student *s, int roll, int l)
{
    for (int i = 0; i < l; i++)
    {
        if ((s+i)->roll == roll)
            return *(s+i);
    }
    printf("No such student exists in the database.\n");
    exit(0);
}

int main()
{
    int l, roll;
    struct student *s = malloc(l * sizeof(struct student));

    printf("Enter the number of students:\n");
    scanf(" %d", &l);
    fflush(stdin);

    input(s, l);
    printf("\n");
    print_structs(s, l);

    printf("Enter the roll number to be searched for:\n");
    scanf(" %d", &roll);
    fflush(stdin);

    struct student s1 = find(s, roll, l);
    printf("\n");
    print_struct(s1);
}
