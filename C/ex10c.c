#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("ERROR: You need 1 or more arguments.\n");
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		char *str = argv[i];
		for (int j = 0; j < strlen(str); j++)
		{
			char c = str[j];
			if (c >= 65 && c <= 91)
				c += 32;
			str[j] = c;
		}
		printf("After lowering all the uppercase, your argument %d is: %s\n", i, str);
	}
}