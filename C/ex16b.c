#include <stdio.h>
#include <string.h>

typedef struct Person
{
	char name[20];
	int age;
	int height;
	int weight;
} Person;

Person create_person(char *name, int age, int height, int weight)
{
	Person p;
	strcpy(p.name, name);
	p.age = age;
	p.height = height;
	p.weight = weight;

	return p;
}

void print_person(Person p)
{
	printf("\n");
	printf("Name  : %s\n", p.name);
	printf("Age   : %d\n", p.age);
	printf("Height: %d\n", p.height);
	printf("Weight: %d\n", p.weight);
}

int main(int argc, char *argv[]) 
{
	Person joe = create_person("Joe Alex", 45, 120, 180);

	print_person(joe);
}