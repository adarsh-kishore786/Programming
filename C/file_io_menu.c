/* file_io_menu.c

   This program gives various
   options to explore files.

   Author: Adarsh
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void read(char *str)
{
	int i = 0;
	int c = EOF;
	int length = 1;

	while ((c = getchar()) != EOF && c != '\n')
	{
		str[i] = c;
		i++;

		if (i == length - 1)
		{
			length += 5;
			str = (char*)realloc(str, length * sizeof(char));
		}
	}
	str[i] = '\0';
}

void read_file_into_memory(FILE *fp, char *str)
{
	int length = 1;
	int i = 0;
	char ch = ' ';

	while (ch != EOF)
	{
		ch = fgetc(fp);
		str[i] = ch;
		i++;

		if (i == length - 1)
		{
			length += 10;
			str = (char*) realloc(str, length * sizeof(char));
		}
	}
	str[i] = '\0';
}

int choice()
{
	int ch;
	printf("\nWhat would you like to do?\n");
	printf("1. Read the contents of the file\n");
	printf("2. Count number of char, whitespace, alphabets,");
	printf(" numbers, special characters, newlines\n");
	printf("3. Read another file\n");
	printf("4. Quit\n");

	scanf("%d", &ch);
	fflush(stdin);

	return ch;
}

void readfile(char *str)
{
	printf("%s\n", str);
}

void count(char *str)
{
	int num_char = 0, num_blank = 0, num_alpha = 0,
		num_int = 0, num_special = 0, num_new = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		char c = str[i];

		if ((c >= 65 && c <= 91) || (c >= 97 && c <= 123))
			num_alpha++;
		else if (c >= 48 && c <= 57)
			num_int++;
		else if (c == ' ')
			num_blank++;
		else if (c == '\n')
			num_new++;
		else
			num_special++;

		num_char++;
	}

	printf("\nNumber of characters        : %d\n", num_char);
	printf("Number of whitespaces       : %d\n", num_blank);
	printf("Number of alphabets         : %d\n", num_alpha);
	printf("Number of digits            : %d\n", num_int);
	printf("Number of new lines         : %d\n", num_new);
	printf("Number of special characters: %d\n", num_special);
}

FILE* get_file(char *address, FILE *f, char *mode)
{
	int errnum;
	printf("Input address of file:\n");
	read:
	{
		read(address);
	}

	f = fopen(address, mode);
	if (f == NULL)
	{
		errnum = errno;
		fprintf(stderr, "Value of error: %d\n", errno);
		perror("Error printed by perror");
		fprintf(stderr, "Error opening file: %s\n", strerror(errno));	
		printf("Cannot find file. Try again:\n");
		goto read;
	}

	return f;
}

int main()
{
	FILE *fp = NULL, *ft = NULL;
	char *source, *target, *str;
	char ch;

	source = (char*)malloc(sizeof(char));
	target = (char*)malloc(sizeof(char));
	str = (char*)malloc(sizeof(char));

	fp = get_file(source, fp, "r");

	read_file_into_memory(fp, str);

	while (1)
	{
		choice_input:
		{
			ch = choice();
		}

		if (ch > 4 || ch <= 0)
		{
			printf("Not a valid choice.\n");
			goto choice_input;
		}

		switch (ch)
		{
			case 1: readfile(str);
					break;
			case 2: count(str);
					break;
			case 3: fclose(fp);
					fp = get_file(source, fp, "r");
					read_file_into_memory(fp, str);
					break;
			case 4: exit(EXIT_SUCCESS);
		}
	}	
}