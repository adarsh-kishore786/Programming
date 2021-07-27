/* queue_linked.c

   This program demostrates the 
   data structure of queue using
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
	printf("3. Display all elements\n");
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

	Node *prev = NULL;
	Node *curr = *head;

	while (curr != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	curr = malloc(sizeof(Node));

	curr->val = val;
	curr->next = NULL;

	if (prev != NULL)
		prev->next = curr;
	else
		*head = curr;
}

void rem(Node **head)
{
	*head = (*head)->next;
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

	printf("----Queue----\n");

	while (1)
	{
		input:
		{
			ch = input();
		}

		if (ch > 4 || ch <= 0)
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
						printf("There are no elements in the queue.\n");
						continue;
					}
					rem(&head);
					break;
			case 3: if (head == NULL)
					{
						printf("There are no elements in the queue.\n");
						continue;
					}
					display(head);
					break;
			case 4: exit(EXIT_SUCCESS);
		}
	}
}