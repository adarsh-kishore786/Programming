/* 
	array.c
*/

#include <stdio.h>

int main()
{
	int a[5];

	printf("Enter a number: ");
	scanf(" %d", &a[0]);

	printf("Enter a number: ");
	scanf(" %d", &a[1]);

	printf("Enter a number: ");
	scanf(" %d", &a[2]);

	printf("Enter a number: ");
	scanf(" %d", &a[3]);

	printf("Enter a number: ");
	scanf(" %d", &a[4]);

	printf("%d\n", a[0]);
	printf("%d\n", a[1]);
	printf("%d\n", a[2]);
	printf("%d\n", a[3]);
	printf("%d\n", a[4]);

	return 0;
}