/* unformatted_io_copy.c

   This program demonstrates the working
   of the gets() and the puts() function
   by creating two functions xgets() and
   xputs() which copy their working.

   Author: Adarsh
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xgets(char* str, int *length)
{
	int c = EOF;
	int i = 0;

	while ((c = getchar()) != '\n' && c != EOF)
	{
		str[i] = (char) c;
		i++;

		if (i == *length) 
		{
			*length += 10;
			str = realloc(str, *length * sizeof(char));
		}
	}
	str[i] = '\0';
}

void xputs(char* output)
{
	printf("%s\n", output);
}

int main()
{
	char* str = malloc(1 * sizeof(char));
	int length = 2;
	printf("Enter a string:\n");
	xgets(str, &length);

	xputs(str);
}