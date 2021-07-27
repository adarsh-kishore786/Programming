#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print_letters(char arg[])
{
	for (int i = 0; i < strlen(arg); i++)
	{
		char ch = arg[i];

		if (isalnum(ch) || isblank(ch))
			printf("\'%c\' == %d ", ch, ch);
	}
	printf("\n");
}
void print_arguments(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
		print_letters(argv[i]);
}

int main(int argc, char *argv[]) 
{
	print_arguments(argc, argv);
	return 0;
}