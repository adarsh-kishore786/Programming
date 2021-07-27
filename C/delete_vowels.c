/* delete_vowels.c

   This program accepts a sentence from 
   the user as input and then deletes all
   the vowels from it.

   Author: Adarsh
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char *str, char c)
{
	int find = -1;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == c)
		{
			find = 1;
			break;
		}
	}
	return find;
}

char* del_vowels(char *str)
{
	char vowels[] = "aeiouAEIOU";
	char *new_string = malloc(128);
	int length = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		char c = str[i];
		if (find(vowels, c) == -1)
			new_string[length++] = c;
	}
	new_string[length] = '\0';
	return new_string;
}

int main()
{
	char *str;
	char c;

	str = malloc(128 * sizeof(char));

	printf("Enter a sentence:\n");
	gets(str);
	fflush(stdin);

	char *new_s = del_vowels(str);
	printf("\nThe sentence after deleting all vowels:\n");
	
	for (int i = 0; i < strlen(new_s); i++)
		printf("%c", new_s[i]);
}