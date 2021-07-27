/*
	file_string_io.c

	This program accepts a few lines 
	from user and puts it into a file 
	of their choice.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	char s[80];

	if (argc != 2)
	{
		printf("No/Invalid destination file given. Try again.\n");
		return 1;
	}

	FILE *fp_write = fopen(argv[1], "w");
	if (!fp_write)
	{
		printf("Couldn't open destination file. Try again.\n");
		return 2;
	}

	printf("Enter a few lines:\n");

	while (fgets(s, sizeof(s), stdin))
		fputs(s, fp_write);
	fclose(fp_write);
	printf("File successfully copied.\n");

	// Read the file back.
	FILE *fp_read = fopen(argv[1], "r");
	if (!fp_read)
	{
		printf("Can't read file. Try again.\n");
		return 3;
	}
	printf("\n");

	while (fgets(s, sizeof(s), fp_read))
		printf("%s", s);
	printf("\n");

	return 0;
}