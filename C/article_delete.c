/* article_delete.c

   This program accepts a sentence
   from the user and deletes all articles
   from it.

   Author: Adarsh
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* del_articles(char str[])
{
	char articles[] = "ThetheTHE       a A an An ";
	char *new_s = malloc(strlen(str) * sizeof(char));
	int length = 0;

	for (int i = 0; i < strlen(str) - 2; i += 3)
	{
		char art[4];
		for (int j = 0; j < 3; j++)
			art[j] = str[i + j];
		art[3] = '\0';

		if (strstr(articles, art) == 0)
		{	
			for (int j = length; j < length + 3; j++)
			{
				printf("%c", art[j - length]);
				new_s[j] = art[j - length];
			}
			length += 3;
		}
		else 
		{
			new_s[length++] = ' ';
		}
	}

	new_s[length] = '\0';
	return new_s;
}

int main()
{
	char str[128];

	printf("Enter a sentence:\n");
	gets(str);
	fflush(stdin);

	char *new_s = del_articles(str);

	printf("\nThe sentence with no articles:\n");
	for (int i = 0; i < strlen(new_s); i++)
		printf("%c", new_s[i]);

}