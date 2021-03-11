/* file_count.c

   This program reads a file
   and counts the number of 
   chars, spaces, tabs and new-
   lines in the file.

   Author: Adarsh
*/

#include <stdio.h>

int main()
{
	FILE *fp;
	char ch;
	int noc = 0, nos = 0, not = 0, nol = 0;

	fp = fopen("../Python/matrix.py", "r");

	while ((ch = fgetc(fp)) != EOF)
	{
		noc++;
		if (ch == ' ')
			nos++;
		if (ch == '\t')
			not++;
		if (ch == '\n')
			nol++;
	}

	fclose(fp);

	printf("Number of characters: %d\n", noc);
	printf("Number of spaces    : %d\n", nos);
	printf("Number of tabs      : %d\n", not);
	printf("Number of new lines : %d\n", nol);
}