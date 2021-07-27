/*
	file_append.c

	This program appends the contents of one file
	to another file after opening it in r+ mode.
*/

#include <stdio.h>
#include <stdlib.h>

#define NO_FILE 0
#define NO_OPEN 1

void error_(int er_no)
{
	switch (er_no)
	{
		case NO_FILE: printf("No/invalid filename given. Try again.\n");
					  exit(1); 
		case NO_OPEN: printf("Cannot open file. Try again.\n");
					  exit(2);
	}
}
int main(int argc, char **argv)
{
	if (argc != 3)
		error_(NO_FILE);

	FILE *fp1 = fopen(argv[1], "r+");

	if (!fp1)
		error_(NO_OPEN);

	FILE *fp2 = fopen(argv[2], "r+");

	if (!fp2)
	{
		fclose(fp1);
		error_(NO_OPEN);
	}

	char ch;
	fseek(fp1, 0, SEEK_END);

	while (!feof(fp2))
	{
		char c;
		if ((c = fgetc(fp2)) == EOF)
			break;
		fprintf(fp1, "%c", c);
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}