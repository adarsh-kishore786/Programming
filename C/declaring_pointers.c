/* declaring_pointers.c

   This program illustrates the process
   of declaring pointers.

   Author: Adarsh
*/

# include <stdio.h>

int main()
{
    int i = 3;

    printf("Address of i = %d\n", &i);

    // Now &i which refers to the memory location of i
    // is also a variable. Thus this value can be stored in
    // another variable, say j. We say that j is a pointer
    // variable, and denote it by saying *j, i.e.,
    // j stores the address of i.

    int *j; // Meaning that the value of the address stored in j
            // is the address of an int (i)
    j = &i; // Since j is a memory address, 'value of j' means the
            // value stored in it like a regular dtype, while
            // 'value at j' means the value at the address of
            // what j is referring to, i.e, value at the address
            // of i

    printf("Value of j = Address of i = %d\n", j);

    // Now j itself is a variable. Thus it has its own memory
    // address, which we can refer by &j.

    printf("Address of j = %d\n", &j);
    printf("Value at address of i = Value of i = %d\n", *(&i));
    printf("Value at address of j = Value of j = Address of i = %d\n", *(&j));
    printf("Value at j = Value of address at i = %d\n\n", *j);

    char c = 'a';
    char *cc = &c; // this does not mean that the value stored in cc
                   // is a char, since memory addresses are always
                   // whole numbers. What it means is that cc stores
                   // the address of a char variable (c)
    printf("Value of c = %c\n", c);
    printf("Address of c = %u\n", &c);
    printf("Value at address of c = %c\n", *(&c));

    printf("Value of cc = Address of c = %u\n", cc);
    printf("Value at cc = Value stored at the address stored in cc = Value of c = %c\n", *cc);
    printf("Address of cc = %u\n", &cc);
    printf("Value at address of cc = Value of cc = Address of c = %u\n\n", *(&cc));

    // We can further extend this concept. Since a pointer is basically
    // a variable with a memory address we can create another pointer to
    // this pointer. Eg-

    float o;
    float *p1;
    float **p2; // p2 is a pointer to a pointer, thus the **

    o = 45.34;
    p1 = &o;
    p2 = &p1;

    printf("Value at o = %f\n", o);
    printf("Address of o = %u\n", &o);
    printf("Value at address of o = Value of o = %f\n", *&o);
    printf("Value of p1 = Address of o = %u\n", p1);
    printf("Address of p1 = %u\n", &p1);
    printf("Value at address of p1 = Value of p1 = Address of o = %u\n", *(&p1));
    printf("Value at p1 = Value at address of o = Value of o = %f\n\n", *p1);

    printf("Value of p2 = Address of p1 = %u\n", p2);
    printf("Address of p2 = %u\n", &p2);
    printf("Value at address of p2 = Value of p2 = Address of p1 = %u\n", *(&p2));
    printf("Value at p2 = Value at address of p1 = Value of p1 = Address of o = %u\n", *p2);

    int t = 3;
    int p = t;

    printf("Address of t = %u\n", &t);
    printf("Address of p = %u\n", &p);
    return 0;
}
