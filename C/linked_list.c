/* linked_list.c

   This program demonstrates a 
   data structutre called the
   linked list.

   Author: Adarsh
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int val;
	struct Node *next;
} Node;

int input()
{
	int ch;
	printf("\nWhat would you like to do?\n");
	printf("1. Add an element\n");
	printf("2. Remove an element\n");
	printf("3. Display all elements (sorted)\n");
	printf("4. Quit\n");

	scanf("%d", &ch);
	fflush(stdin);
	return ch;
}

void add(Node **head)
{
	int val;

	printf("\nEnter a value: ");
	scanf("%d", &val);
	fflush(stdin);

	Node *curr = *head;
	Node *prev = NULL;

	while (curr != NULL)
	{
		if (curr->val >= val)
			break;
		prev = curr;
		curr = curr->next;
	}
	Node *new = malloc(sizeof(Node));

	new->val = val;
	new->next = curr;

	if (prev != NULL)
		prev->next = new;
	else
		*head = new;
}

void rem(Node **head)
{
	int val;

	printf("\nEnter value to be removed: ");
	scanf("%d", &val);
	fflush(stdin);

	Node *curr = *head;
	Node *prev = NULL;

	while (curr != NULL)
	{
		if (curr->val == val)
			break;

		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL)
	{
		printf("\nThe value %d does not exist in the list.\n", val);
		return;
	}

	if (prev != NULL)
		prev->next = curr->next;
	else
		*head = curr->next;
}

void display(Node *node)
{
	if (node == NULL)
		return;

	printf("\nCurrently at %u:\n", node);
	printf("Value       : %d\n", node->val);
	printf("Next address: %u\n", node->next);

	display(node->next);
}

int main()
{
	int ch;
	Node *head = NULL;

	printf("----Linked List----\n");
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
			case 1: add(&head);
					break;
			case 2: if (head == NULL)
					{
						printf("There are no elements in the stack.\n");
						continue;
					}
					rem(&head);
					break;
			case 3: if (head == NULL)
					{
						printf("There are no elements in the stack.\n");
						continue;
					}
					display(head);
					break;
			case 4: exit(EXIT_SUCCESS);
		}
	}
}