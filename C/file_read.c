/*
	file_read.c

	Displays contents of a file
*/

#include <stdio.h>

int main(int args, char *argv[])
{
	if (args != 2)
	{
		printf("Invalid or no filename given. Try again.\n");
		return 1;
	}

	FILE *fp;
	char ch = ' ';
	fp = fopen(argv[1], "r");

	if (!fp)
	{
		printf("No such file exists. Try again.\n");
		return 2;
	}

	while ((ch = fgetc(fp)) != EOF)
		printf("%c", ch);

	printf("\n");
	fclose(fp);
	return 0;
}