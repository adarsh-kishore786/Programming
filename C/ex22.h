#ifndef _ex22_h
#define _ex22_h

// makes THE_SIZE in ex22.c available to other .c files
extern int THE_SIZE;

// getter and setter for internal static variable in ex22.c
int get_age();
void set_age(int age);

// updates static variable inside update_ratio
double update_ratio(double ratio);

void print_size();

#endif