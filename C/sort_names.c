/* sort_name.c

   This program accepts names from the user
   and sorts them in the ascending order.

   Author: Adarsh
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_list(char **names, int length)
{
	for (int i = 0; i < length; i++)
		printf("%d. %s\n", (i + 1), *(names + i));
}

int compare(char *s1, char *s2)
{	
	int i = 0;
	int val = 0;

	char *t1 = malloc(strlen(s1) + 1);
	char *t2 = malloc(strlen(s2) + 1);

	strlwr(strcpy(t1, s1));
	strlwr(strcpy(t2, s2));

	while (1 == 1)
	{
		char c1 = *(t1 + i);
		char c2 = *(t2 + i);

		if (c1 == '\0' || c2 == '\0')
		{
			if (strlen(s1) > strlen(s2))
				val = 1;
			else if (strlen(s1) < strlen(s2))
				val = -1;
			break;
		}

		if (c1 > c2)
		{
			val = 1;
			break;
		}
		else if (c1 < c2)
		{
			val = -1;
			break;
		}
		i++;
	}

	return val;
}

void select_sort(char **names, int length, int order)
{
	for (int i = 0; i < length - 1; i++)
	{
		int pos = i;

		for (int j = i + 1; j < length; j++)
		{
			if (compare(*(names + pos), *(names + j)) == order)
				pos = j;
		}

		char *t = *(names + i);
		*(names + i) = *(names + pos);
		*(names + pos) = t;
	}
}

void insert_sort(char **names, int length, int order)
{
	for (int i = 0; i < length; i++)
	{
		int pos = i;
		for (int j = i + 1; j < length; j++)
		{
			if (compare(*(names + pos), *(names + j)) == order)
				pos = j;
		}

		char *t = *(names + pos);
		for (int j = pos; j > i; j--)
			*(names + j) = *(names + j - 1);

		*(names + i) = t;
	}
}

int main()
{
	char **names;
	int length;
	int order;

	printf("Enter the number of names:\n");
	scanf("%d", &length);
	fflush(stdin);

	names = malloc(length * sizeof(char*));

	for (int i = 0; i < length; i++)
	{
		char temp[128];
		printf("Enter a name: ");
		gets(temp);
		fflush(stdin);

		*(names + i) = malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(*(names + i), temp);
	}

	printf("\nThe original name list you entered:\n");
	for (int i = 0; i < length; i++)
	{
		printf("%d. %s\n", (i + 1), *(names + i));
	}

	order:
	{
	    printf("\nEnter order of arrangement:\n");
		printf("1 for ascending order\n");
		printf("-1 for descending order\n");
		scanf("%d", &order);
	}
	
	if (order != 1 && order != -1)
	{
		printf("This is not a valid order.\n");
		goto order;
	}

	insert_sort(names, length, order);

	printf("\nThe new name list in %s order:\n", (order == 1 ? "ascending":"descending"));
	print_list(names, length);
}