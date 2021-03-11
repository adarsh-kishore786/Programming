/* file_io_binary.c

   This program demonstrates IO
   functions in a binary file.

   Author: Adarsh
*/

#include <stdio.h>

struct emp
{
	char name[40];
	int age;
	float bs;
};

int main()
{
	FILE *fp;
	struct emp e;

	fp = fopen("employee.dat", "wb");

	printf("Enter name of employee: ");
	gets(e.name);
	fflush(stdin);

	printf("Enter age of employee: ");
	scanf("%d", &(e.age));
	fflush(stdin);

	printf("Enter basic salary of employee: ");
	scanf("%f", &(e.bs));
	fflush(stdin);

	fwrite(&e, sizeof(e), 1, fp);
	fclose(fp);

	fp = fopen("employee.dat", "rb");
	while (fread(&e, sizeof(e), 1, fp) == 1)
		printf("Name: %s\nAge: %d\nSalary: %f\n", 
			e.name, e.age, e.bs);

	fclose(fp);
}