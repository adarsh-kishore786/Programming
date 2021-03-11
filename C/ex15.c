#include <stdio.h>
#include <stdlib.h>

int count = 5;

void initialize(int *ages, char **names, int *cur_age, char **cur_name)
{
	*ages = 23;
	*(ages + 1) = 43;
	*(ages + 2) = 12;
	*(ages + 3) = 89;
	*(ages + 4) = 2;

	*names = "Alan";
	*(names + 1) = "Frank";
	*(names + 2) = "Mary";
	*(names + 3) = "John";
	*(names + 4) = "Lisa";

	for (int i = 0; i < count; i++)
	{
		cur_age[i] = *(ages + i);
		cur_name[i] = *(names + i);
	}
}

void print1(int *ages, char **names)
{
	for (int i = 0; i < count; i++)
		printf("%s has %d years alive.\n", names[i], ages[i]);

	printf("---\n");
}

void print2(int *ages, char **names)
{
	for (int i = 0; i < count; i++)
		printf("%s will be reborn in %d years.\n", *(names + i), *(ages + i));

	printf("---\n");
}

void print3(int *cur_age, char **cur_name)
{
	for (int i = 0; i < count; i++)
		printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));

	printf("---\n");
}

void print4(int *cur_age, char **cur_name)
{
	for (int i = 0; i < count; i++)
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);

	printf("---\n");	
}

int main()
{
	int *ages = (int*) malloc(5 * sizeof(int));
	char **names = (char**) malloc(5 * 5 * sizeof(char));
	int cur_age[5];
	char *cur_name[5];
	initialize(ages, names, cur_age, cur_name);

	print1(ages, names);
	print2(ages, names);
	print3(cur_age, cur_name);
	print4(cur_age, cur_name);

	// for (cur_name = names + count - 1, cur_age = ages + count - 1;
	// 			(cur_age - ages) >= 0; cur_name--, cur_age--)
	// {
	// 	printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	// }

 	printf("---\n");
	printf("Size of ages array   : %u\n", sizeof(ages) * count);
	printf("Size of names array  : %u\n", sizeof(names) * count);
	printf("Size of ages pointer : %u\n", sizeof(cur_age)); // NOT sizeof(ages)
	printf("Size of names pointer: %u\n", sizeof(cur_name)); // NOT sizeof(names)

	printf("---\n");
	// arrays are static, pointers are dynamic

	//ages = {6, 7, 8, -10, 0} //ERROR
	//cur_age = ages + 10;

	for (int i = 0; i < count; i++)
	{
		printf("Address of ages + %d : %p %u\n", i, ages + i, ages + i);
		printf("Address of names + %d: %p %u\n", i, names + i, ages + i);
	}
	return 0;
}