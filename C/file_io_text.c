/* file_io_text.c

   This program demonstrates IO
   operations to a text file.

   Author: Adarsh
*/	

#include <stdio.h>

struct employee
{
	char name[40];
	int age;
	float bs;
};

int main()
{
	FILE *fp;
	struct employee e;

	fp = fopen("employee2.dat", "w");

	printf("Enter name of employee: ");
	gets(e.name);
	fflush(stdin);

	printf("Enter age of employee: ");
	scanf("%d", &(e.age));
	fflush(stdin);

	printf("Enter basic salary of employee: ");
	scanf("%f", &(e.bs));
	fflush(stdin);

	fprintf(fp, "%s %d %f", e.name, e.age, e.bs);
	fclose(fp);

	fp = fopen("employee2.dat", "r");
	while (fscanf(fp, "%s %d %f", e.name, &e.age, &e.bs) != EOF)
		printf("Name: %s\nAge: %d\nSalary: %f\n", e.name, e.age, e.bs);
	fclose(fp);
}