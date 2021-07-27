#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("ERROR: You need 1 argument.");
		return 1;
	}

	char *str = argv[1];
	for (int i = 0; i < strlen(str); i++)
	{
		char c = str[i];
		switch (c)
		{
			case 'a':
			case 'A': printf("\"A\"\n");
					  break;
			case 'e':
			case 'E': printf("\"E\"\n");
					  break;
			case 'i':
			case 'I': printf("\"I\"\n");
					  break;
			case 'o':
			case 'O': printf("\"O\"\n");
					  break;
			case 'u':
			case 'U': printf("\"U\"\n");
					  break;
			default: printf("%c is not a vowel\n", c);
		}
	}
}