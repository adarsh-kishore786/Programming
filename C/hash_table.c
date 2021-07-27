/* hash_table.c

   This program demonstrates the 
   data structure of a hash 
   table.

   Author: Adarsh
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 1000

typedef struct entry
{
	int key;
	int val;
	struct entry *next;
} element;

typedef struct htable 
{
	element *entry;
} htable;

int hash(int val)
{
	int k = ((abs(val + 3) * 37) + 17) % TABLE_SIZE;
	return k;
}

int input()
{
	int ch;
	printf("\nWhat would you like to do?\n");
	printf("1. Add an element\n");
	printf("2. Remove an element\n");
	printf("3. Search for an element\n");
	printf("4. Display the table\n");
	printf("5. Quit\n");

	scanf("%d", &ch);
	fflush(stdin);

	return ch;
}

void add_element(htable **h_t)
{
	int val;
	int key;

	printf("\nEnter value to be added: ");
	scanf("%d", &val);
	fflush(stdin);

	key = hash(val);

	element *entry = (*h_t + key)->entry;
	element *prev = NULL;

	while (entry != NULL)
	{
		prev = entry;
		entry = entry->next;
	}
	entry = malloc(sizeof(element));

	entry->key = key;
	entry->val = val;
	entry->next = NULL;

	if (prev != NULL)
		prev->next = entry;
	else
		(*h_t + key)->entry = entry;
}

void remove_element(htable **h_t)
{
	int val;
	int key;
	int found = 0;

	printf("\nEnter value to be removed: ");
	scanf("%d", &val);
	fflush(stdin);

	key = hash(val);

	element *entry = (*h_t + key)->entry;
	element *prev = NULL;

	while (entry != NULL)
	{
		if (entry->val == val)
		{
			found = 1;
			break;
		}

		prev = entry;
		entry = entry->next;
	}
	if (found == 0)
	{
		printf("The given value does not exist in the table.\n");
		return;
	}

	if (prev != NULL)
		prev->next = entry->next;
	else
	{
		entry = entry->next;
		(*h_t + key)->entry = entry;
	}
}

void search_element(htable *h_t)
{
	int val;
	int key;
	int found = 0;

	printf("\nEnter a value: ");
	scanf("%d", &val);
	fflush(stdin);

	key = hash(val);
	element *entry = h_t[key].entry;

	while (entry != NULL)
	{
		if (entry->val == val)
		{
			found = 1;
			break;
		}
		entry = entry->next;
	}
	if (found == 0)
	{
		printf("The given value does not exist in the table.\n");
		return;
	}
	printf("The value %d is at %u.\n", val, key);
}

void display(htable *h_t)
{
	int empty = 1;
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		element *entry = h_t[i].entry;
		if (entry == NULL)
			continue;
		empty = 0;
		printf("\nCurrently at %u:\n", i);
		printf("Value: ");
		while (entry != NULL)
		{
			printf("%d ", entry->val);
			entry = entry->next;
		}
		printf("\n");
	}

	if (empty == 1)
		printf("\nThe table is empty.\n");
}

int main()
{
	int ch;
	htable *h_t;

	h_t = malloc(TABLE_SIZE * sizeof(htable));
	for (int i = 0; i < TABLE_SIZE; i++)
		h_t[i].entry = NULL; 

	printf("----Hash Table----\n");

	while (1)
	{
		input:
		{
			ch = input();
		}

		if (ch > 5 || ch <= 0)
		{
			printf("Invalid input. Rebooting...\n");
			goto input;
		}

		switch (ch)
		{
			case 1: add_element(&h_t);
					break;
			case 2: remove_element(&h_t);
					break;
			case 3: search_element(h_t);
					break;
			case 4: display(h_t);
					break;
			case 5: exit(EXIT_SUCCESS);
		}
	}
}