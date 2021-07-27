/*
	employee_text.c

	This program reads/writes data on an
	employee from/into a text file using
	fprint and fscanf.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct emp
{
	char name[40];
	int age;
	float salary;

} emp;

void error(int n)
{
	switch (n)
	{
		case 1: printf("No/invalid filename given. Try again.\n");
				exit(1);
		case 2: printf("No/invalid read/write mode given. Try again.\n");
				exit(2);
		case 3: printf("No such file exists. Try again.\n");
				exit(3);
		case 4: printf("Cannot open file. Try again.\n");
				exit(4);
	}
}

void employee_details(FILE *fp)
{
	if (!fp)
		error(3);

	printf("Enter number of employees: ");
	int n;
	fscanf(stdin, "%d", &n);

	for (int i = 0; i < n; i++)
	{
		emp e;
		printf("Enter name  : ");
		fscanf(stdin, "%s", e.name);

		printf("Enter age   : ");
		fscanf(stdin, "%d", &e.age);

		printf("Enter salary: ");
		fscanf(stdin, "%f", &e.salary);

		fprintf(fp, "\n%s %d %f", e.name, e.age, e.salary);
		printf("\n");
	}
	fclose(fp);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		if (argc == 1)
			error(1);
		else
			error(2);

	if (!strcmp(argv[2], "r"))
	{
		FILE *fp_read = fopen(argv[1], "r");

		if (!fp_read)
			error(3);

		emp e;
		while (fscanf(fp_read, "%s %d %f", e.name, &e.age, &e.salary) != EOF)
		{
			printf("Name  : %s\n", e.name);
			printf("Age   : %d\n", e.age);
			printf("Salary: %f\n\n", e.salary);
		}
		fclose(fp_read);
	}
	else if (!strcmp(argv[2], "a"))
	{
		FILE *fp_append = fopen(argv[1], "a");

		employee_details(fp_append);
	}
	else if (!strcmp(argv[2], "w"))
	{
		printf("This will erase all previous data on this file.");
		printf(" If you want to append, use 'a' instead of 'w'.");

		printf("Continue? (Y/N)");
		char ch;
		fscanf(stdin, "%c", &ch);

		if (ch != 'Y' && ch != 'y')
			exit(1);

		FILE *fp_write = fopen(argv[1], "w");

		employee_details(fp_write);
	}
	else
		error(2);
	return 0;
}