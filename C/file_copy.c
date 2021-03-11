/* file_copy.c
  
   This program copies the contents of 
   one file to another.

   Author: Adarsh
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getinput(char* address)
{
	printf("Enter address of the file:\n");
	char c = EOF;
	int length = 2;
	int i = 0;

	while ((c = getchar()) != EOF && c != '\n')
	{
		address[i] = c;
		i++;

		if (i == length)
		{
			length++;
			address = realloc(address, length * sizeof(char));
		}
	}
	address[i] = '\0';
}

void target_address(char* target)
{
	int pos = 0;
	for (int i = strlen(target) - 1; i >= 0; i--)
	{
		if (target[i] == '.')
		{
			pos = i;
			break;
		}
	}

	for (int i = strlen(target); i >= pos + 1; i--)
		target[i] = target[i - 1];
	target[pos] = '2';
}

int main()
{
	FILE *fs, *ft;
	char ch;	
	char *address = malloc(sizeof(char));
	char *target;

	input:
	{
		getinput(address);
	}

	fs = fopen(address, "r");
	if (fs == NULL)
	{
		printf("\nFile not found. Rebooting\n");
		goto input;
	}
	printf("\nThe address you entered:\n%s\n", address);

	target = malloc(sizeof(address) + 5);
	strcpy(target, address);
	target_address(target);

	ft = fopen(target, "w");

	do
	{
		ch = fgetc(fs);

		if (ch != EOF)
			fputc(ch, ft);
	} while(ch != EOF);

	printf("\nFile successfully cloned in directory!");

	fclose(fs);
	fclose(ft);
}