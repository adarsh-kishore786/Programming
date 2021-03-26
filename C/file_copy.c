/*
	file_copy.c

	This program demonstrates how to
	copy contents of one file to 
	another.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Invalid/no source and/or destination filename given. Try again.\n");
		return 1;
	}

	FILE *fp_read = fopen(argv[1], "r");
	if (!fp_read)
	{
		printf("No such file exists. Try again.\n");
		return 2;
	}

	FILE *fp_write = fopen(argv[2], "w");

	if (!fp_write)
	{
		printf("Cannot open target file. Try again.\n");
		fclose(fp_read);
		return 3;
	}
	char c;

	while ((c = fgetc(fp_read)) != EOF)
	{
		printf("%c", c);
		fputc(c, fp_write);
	}
	fclose(fp_read);
	fclose(fp_write);

	return 0;
}