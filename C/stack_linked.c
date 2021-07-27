/* stack_linked.c

   This program creates a
   data structure stack using
   a linked list.

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
	printf("1. Push an element at the top\n");
	printf("2. Remove an element from the top\n");
	printf("3. Display all elements\n");
	printf("4. Quit\n");

	scanf("%d", &ch);
	fflush(stdin);
	return ch;
}

void push(Node **head)
{
	int val;

	printf("\nEnter a value: ");
	scanf("%d", &val);
	fflush(stdin);

	Node *new = malloc(sizeof(Node));
	new->val = val;
	new->next = *head;

	*head = new;
}

void pull(Node **head)
{
	*head = (*head)->next;
}

void display(Node *node)
{
	if (node == NULL)
		return;

	printf("\nCurrently at %u:\n", node);
	printf("Value       : %d\n", node->val);
	printf("Next address: %d\n", node->next);

	display(node->next);
}

int main()
{
	int ch;
	Node *head = NULL;

	printf("----Stack----\n");
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
			case 1: push(&head);
					break;
			case 2: if (head == NULL)
					{
						printf("There are no elements in the stack.\n");
						continue;
					}
					pull(&head);
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