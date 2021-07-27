#include <stdio.h>
#include <stdlib.h>

void increment_me(int *num)
{
	++*num;
}

int main()
{
	int number = 10;
	int *p_number = &number;

	printf("Number is: %d\n", number);
	printf("Value of pointer after dereferencing: %d\n", *p_number);

	number++;
	printf("Number is: %d\n", number);
	printf("Value of pointer after dereferencing: %d\n", *p_number);

	++*p_number;

	printf("Number is: %d\n", number);
	printf("Value of pointer after dereferencing: %d\n", *p_number);

	increment_me(p_number);

	printf("Number is: %d\n", number);
	printf("Value of pointer after dereferencing: %d\n", *p_number);

	increment_me(&number);

	printf("Number is: %d\n", number);
	printf("Value of pointer after dereferencing: %d\n", *p_number);

	return EXIT_SUCCESS;
}