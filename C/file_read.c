/* file_read.c

   This program creates a file
   IO app.

   Author: Adarsh
*/

#include <stdio.h>

int main()
{
	FILE *fp;
	char ch;
	fp = fopen("file_read.txt", "r");

	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)
			break;
		printf("%c", ch);
	}
	printf("\n");
	fclose(fp);
}