/*
	file_replace_string.c

	This program reads a file and a string and 
	replaces file string with given pattern.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_error(int err_no)
{
	switch (err_no)
	{
		case 1: printf("File not found/String not given. Try again.\n");
				exit(1);
		case 2: printf("Cannot open file. Try again.\n");
				exit(2);
		case 3: printf("An error occured. Try again.\n");
				exit(3);
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
		display_error(1);

	FILE *fp_open = fopen(argv[1], "r");

	if (!fp_open)
		display_error(2);

	char str[strlen(argv[2]) + 1];

	FILE *fp_new = fopen("temp.txt", "w+");

	while (fgets(str, strlen(argv[2]) + 1, fp_open))
	{
		if (!strcmp(str, argv[2]))
			fprintf(fp_new, "%s", argv[3]);
		else
			fprintf(fp_new, "%s", str);
	}

	rewind(fp_new);
	fclose(fp_open);

	fp_open = fopen(argv[1], "w");

	char ch;
	while ((ch = fgetc(fp_new)) != EOF)
		fprintf(fp_open, "%c", ch);

	fclose(fp_new);
	fclose(fp_open);

	return 0;	
}