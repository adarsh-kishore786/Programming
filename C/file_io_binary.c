/*
	file_io_binary.c

	Reads and stores data in a binary file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee
{
	char name[40];
	int age;
	float salary;
} emp;

void error(int x)
{
	switch(x)
	{
		case 1: printf("Invalid/no file given. Try again.\n");
				exit(1);
		case 2: printf("Invalid/no read/write options given. Try again.\n");
				exit(2);
		case 3: printf("Cannot open file. Try again.\n");
				exit(3);
	}

	printf("An error occured. Try again.\n");
	exit(4);
}

void operFile(FILE *fp)
{
	if (!fp)
		error(3);

	printf("Enter number of employees: ");
	int n;
	fscanf(stdin, "%d", &n);

	for (int i = 0; i < n; i++)
	{
		emp e;
		printf("Name  : ");
		fscanf(stdin, "%s", e.name);

		printf("Age   : ");
		fscanf(stdin, "%d", &e.age);

		printf("Salary: ");
		fscanf(stdin, "%f", &e.salary);

		fwrite(&e, sizeof(e), 1, fp);
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
		error(1);

	if (!strcmp(argv[2], "r"))
	{
		FILE *fp_read = fopen(argv[1], "rb");

		if (!fp_read)
			error(3);

		emp e;
		while (fread(&e, sizeof(e), 1, fp_read) == 1)
		{
			printf("Name  : %s\n", e.name);
			printf("Age   : %d\n", e.age);
			printf("Salary: %f\n\n", e.salary);
		}
		fclose(fp_read);
	}
	else if (!strcmp(argv[2], "a"))
	{
		FILE *fp_append = fopen(argv[1], "ab");

		operFile(fp_append);
		fclose(fp_append);
	}
	else if (!strcmp(argv[2], "w"))
	{
		printf("This will overwrite any existing files.\n");
		printf("For appending use 'a' instead of 'w'.\n");
		printf("Continue anyway? (Y/N) ");
		char ch;

		fscanf(stdin, "%c", &ch);
		if (ch != 'Y' && ch != 'y')
			exit(0);

		FILE *fp_write = fopen(argv[1], "wb");
		operFile(fp_write);
		fclose(fp_write);
	}
	else
		error(2);

	return 0;
}